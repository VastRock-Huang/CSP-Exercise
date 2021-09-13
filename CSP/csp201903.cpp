
/*
	试题编号：201903-1
	试题名称：小中大

	题干：
		老师给了你 n 个整数组成的测量数据，保证有序（可能为升序或降序），
	可能存在重复的数据。请统计出这组测量数据中的最大值、中位数以及最小值，
	并按照从大到小的顺序输出这三个数。	

	输入：
		从标准输入读入数据。
		第一行输入一个整数 n，在第二行中存在 n 个有序的整数，表示测量数据，
		可能为升序或降序排列，可能存在连续多个整数相等，整数与整数之间使
		用空格隔开。
	输出：
		输出到标准输出。
		包含一行，包括最大值、中位数以及最小值共三个数，并按照从大到小的
	顺序输出。数据与数据之间使用空格隔开。对于整数请直接输出整数，对于可能
	出现的分数，请输出四舍五入保留 1 位小数的结果。
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
	题目编号：201903-2
	题目名称：二十四点

	题干：
		二十四点是一款著名的纸牌游戏，其游戏的目标是使用 3 个加减乘除运算使得
	4张纸牌上数字的运算结果为 24。

	输入：
		定义每一个游戏由 4 个从 1-9 的数字和 3 个四则运算符组成，保证四则运算符
	将数字两两隔开，不存在括号和其他字符，运算顺序按照四则运算顺序进行。其中加
	法用符号 + 表示，减法用符号 - 表示，乘法用小写字母 x 表示，除法用符号 / 表
	示。在游戏里除法为整除，例如 2 / 3 = 0，3 / 2 = 1, 4 / 2 = 2。
		老师给了你 n 个游戏的解，请你编写程序验证每个游戏的结果是否为 24 。
	输出：
		从标准输入读入数据。第一行输入一个整数 n，从第 2 行开始到第 n + 1 行中，
	每一行包含一个长度为 7的字符串，为上述的 24 点游戏，保证数据格式合法。
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
					//op.push(a[j]);		//此else语句的另一种写法，但这种时间更长
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