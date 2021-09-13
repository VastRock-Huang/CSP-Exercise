
/*
	�����ţ�201903-1
	�������ƣ�С�д�

	��ɣ�
		��ʦ������ n ��������ɵĲ������ݣ���֤���򣨿���Ϊ������򣩣�
	���ܴ����ظ������ݡ���ͳ�Ƴ�������������е����ֵ����λ���Լ���Сֵ��
	�����մӴ�С��˳���������������	

	���룺
		�ӱ�׼����������ݡ�
		��һ������һ������ n���ڵڶ����д��� n ���������������ʾ�������ݣ�
		����Ϊ����������У����ܴ����������������ȣ�����������֮��ʹ
		�ÿո������
	�����
		�������׼�����
		����һ�У��������ֵ����λ���Լ���Сֵ���������������մӴ�С��
	˳�����������������֮��ʹ�ÿո����������������ֱ��������������ڿ���
	���ֵķ�����������������뱣�� 1 λС���Ľ����
*/

/*
#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	float midf;
	int mid;
	int flag = 0;
	if (n % 2==0)
	{
		mid = a[n / 2] + a[n / 2 - 1];
		if (mid % 2)
		{
			midf = mid * 1.0 / 2;
			flag = 1;
		}
		else
			mid /= 2;
	}
	else
		mid = a[n / 2];
	if (a[0] < a[n - 1])
		swap(a[0], a[n - 1]);

	if (flag)
		printf("%d %.1f %d", a[0], midf, a[n - 1]);
	else
		cout << a[0] << ' ' << mid << ' ' << a[n - 1];

	delete[] a;
	return 0;
}



/*
	��Ŀ��ţ�201903-2
	��Ŀ���ƣ���ʮ�ĵ�

	��ɣ�
		��ʮ�ĵ���һ��������ֽ����Ϸ������Ϸ��Ŀ����ʹ�� 3 ���Ӽ��˳�����ʹ��
	4��ֽ�������ֵ�������Ϊ 24��

	���룺
		����ÿһ����Ϸ�� 4 ���� 1-9 �����ֺ� 3 �������������ɣ���֤���������
	�������������������������ź������ַ�������˳������������˳����С����м�
	���÷��� + ��ʾ�������÷��� - ��ʾ���˷���Сд��ĸ x ��ʾ�������÷��� / ��
	ʾ������Ϸ�����Ϊ���������� 2 / 3 = 0��3 / 2 = 1, 4 / 2 = 2��
		��ʦ������ n ����Ϸ�Ľ⣬�����д������֤ÿ����Ϸ�Ľ���Ƿ�Ϊ 24 ��
	�����
		�ӱ�׼����������ݡ���һ������һ������ n���ӵ� 2 �п�ʼ���� n + 1 ���У�
	ÿһ�а���һ������Ϊ 7���ַ�����Ϊ������ 24 ����Ϸ����֤���ݸ�ʽ�Ϸ���
*/
/*
#include<iostream>
#include<stack>

using namespace std;

bool isOp(char c)
{
	if (c == '+' || c == '-' || c == 'x' || c == '/')
		return true;
	return false;
}

bool op1First(char op1, char op2)
{
	if ((op1 == '+' || op1 == '-') && (op2 == 'x' || op2 == '/'))
		return false;
	return true;	
}

int compute(int num1, char op, int num2)
{
	switch (op)
	{
	case '+':return num1 + num2;
	case '-':return num1 - num2;
	case 'x':return num1 * num2;
	case '/':return num1 / num2;
	}
}

int main()
{
	int n;
	cin >> n;
	stack<int> num;
	stack<char> op;
	for (int i = 0; i < n; i++)
	{
		char a[8] = { 0 };
		cin >> a;
		stack<int> num;
		stack<char> op;

		num.push(a[0] - '0');
		op.push(a[1]);
		num.push(a[2] - '0');

		int j = 3;
		int num1, num2;
		while (a[j]!= 0 || !op.empty())
		{
			int op1 = op.top();
			if (a[j])
			{
				if (op1First(op1, a[j]))
				{
					num2 = num.top();
					num.pop();
					num1 = num.top();
					num.pop();
					op.pop();
					num1 = compute(num1, op1, num2);
					num.push(num1);
					op.push(a[j]);
					num.push(a[j + 1]-'0');
				}
				else
				{
					num2 = num.top();
					num.pop();
					num1 = compute(num2, a[j], a[j + 1]-'0');
					num.push(num1);
					//op.push(a[j]);		//��else������һ��д����������ʱ�����
					//num.push(a[j + 1] - '0');
				}
				j += 2;
			}
			else
			{
				num2 = num.top();
				num.pop();
				num1 = num.top();
				num.pop();
				op.pop();
				num1 = compute(num1, op1, num2);
				num.push(num1);
			}
		}

		if (num.top() == 24)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}

/**/