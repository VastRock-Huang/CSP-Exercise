/*
	��Ŀ��ţ�201512-1
	��Ŀ���ƣ���λ֮��

	��ɣ�
		����һ��ʮ��������n�����n�ĸ�λ����֮�͡�

	���룺
		����һ������n��
	�����
		���һ����������ʾ�𰸡�
*/
/*
#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int sum = 0;
	do
	{
		sum += n % 10;
		n /= 10;
	} while (n);
	cout << sum;
	return 0;
}

/*
	��Ŀ��ţ�201512-2
	��Ŀ���ƣ���������Ϸ

	��ɣ�
		��������Ϸ�����ܴ��ڻ�ӭ��һ����Ϸ����Ϸ��һ��������n��m�е���Ϸ������
	���У����̵�ÿһ��ÿһ�еķ����Ϸ���һ������ɫ�����ӣ���һ�л�һ����������
	������������ͬ��ɫ������ʱ����Щ���Ӷ������������жദ���Ա�����ʱ����Щ
	�ط������ӽ�ͬʱ�������� 
		���ڸ���һ��n��m�е����̣������е�ÿһ����������һ�����ӣ����������һ
	������������̡� 
		��ע�⣺һ�����ӿ�����ĳһ�к�ĳһ��ͬʱ��������

	���룺
		����ĵ�һ�а�����������n, m���ÿո�ָ����ֱ��ʾ���̵������������� 
		������n�У�ÿ��m���������ÿո�ָ����ֱ��ʾÿһ�������е����ӵ���ɫ��
	��ɫʹ��1��9��š�
	�����
		���n�У�ÿ��m�����������ڵ�����֮��ʹ��һ���ո�ָ�����ʾ����һ������
	������̡����һ�������е����ӱ����������Ӧ�ķ������0������������ӵ���
	ɫ��š�
*/
/*
#include<iostream>

using namespace std;

struct Node
{
	int color;
	int flag;
};

int main()
{
	int n, m;
	cin >> n >> m;
	Node** a = new Node * [n];
	for (int i = 0; i < n; i++)
		a[i] = new Node[m];
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j].color;
			a[i][j].flag = 1;
		}

	for (int i = 0; i < n; i++)
	{
		int j = 0;
		while (j<m-2)
		{
			if (a[i][j].color == a[i][j + 1].color && a[i][j].color == a[i][j + 2].color)
				for (int temp = a[i][j].color;j < m && a[i][j].color == temp; j++)
					//ע��˴�Ҫ����j<m������j<nͬ
					a[i][j].flag = 0;
			else
				j++;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int j = 0;
		while (j<n-2)
		{
			if (a[j][i].color == a[j + 1][i].color && a[j][i].color == a[j + 2][i].color)
				for (int temp = a[j][i].color; j < n && a[j][i].color == temp; j++)
					a[j][i].flag = 0;
			else
				j++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << a[i][j].color * a[i][j].flag << ' ';
		cout << endl;
	}

	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

	//�״�㣺���ڲ�ѭ���ж��ⲿѭ�������иı�ʱ��Ҫ���ڲ�ѭ�����ж�����м���
	//�ⲿѭ�����ж����

/**/