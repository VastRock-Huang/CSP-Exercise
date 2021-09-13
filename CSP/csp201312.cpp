/*
	题目编号：201312-1
	题目名称：出现次数最多的数

	题干：
		给定n个正整数，找出它们中出现次数最多的数。如果这样的数有多个，请输出其
	中最小的一个。
		
	输入：
		输入的第一行只有一个正整数n(1 ≤ n ≤ 1000)，表示数字的个数。
		输入的第二行有n个整数s1, s2, …, sn (1 ≤ si ≤ 10000, 1 ≤ i ≤ n)。相
	邻的数用空格分隔。
	输出：
		输出这n个次数中出现次数最多的数。如果这样的数有多个，输出其中最小的一个。
*/
/*
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int num = a[0], max = 1;
	for (int i = 0,times=1; i < n - 1; i++)
	{
		if (a[i] == a[i + 1])
			times++;
		else
			times = 1;
		if (times > max)
		{
			num = a[i];
			max = times;
		}
	}
	cout << num;
	delete[] a;
	return 0;
}


//int main()
//{
//	int n;
//	cin >> n;
//	int a[10000] = { 0 };		//空间复杂度高的方法
//	int num, max = 0;
//	int ipt;
//	while (n--)
//	{
//		cin >> ipt;
//		if (++a[ipt] > max)
//		{
//			num = ipt;
//			max = a[ipt];
//		}
//		else if (a[ipt] == max && ipt < num)
//			num = ipt;
//	}
//	cout << num;
//	return 0;
//}


/*
	题目编号：201312-2
	题目名称：ISBN号码

	题干：
		每一本正式出版的图书都有一个ISBN号码与之对应，ISBN码包括9位数字、1位识
	别码和3位分隔符，其规定格式如“x-xxx-xxxxx-x”，其中符号“-”是分隔符（键盘
	上的减号），最后一位是识别码，例如0-670-82162-4就是一个标准的ISBN码。ISBN码
	的首位数字表示书籍的出版语言，例如0代表英语；第一个分隔符“-”之后的三位数
	字代表出版社，例如670代表维京出版社；第二个分隔之后的五位数字代表该书在出版
	社的编号；最后一位为识别码。 
	识别码的计算方法如下： 
		首位数字乘以1加上次位数字乘以2……以此类推，用所得的结果mod 11，所得的余
	数即为识别码，如果余数为10，则识别码为大写字母X。例如ISBN号码0-670-82162-4中
	的识别码4是这样得到的：对067082162这9个数字，从左至右，分别乘以1，2，…，9，
	再求和，即0×1+6×2+……+2×9=158，然后取158 mod 11的结果4作为识别码。 
		编写程序判断输入的ISBN号码中识别码是否正确，如果正确，则仅输出“Right”；
	如果错误，则输出是正确的ISBN号码。

	输入：
		输入只有一行，是一个字符序列，表示一本书的ISBN号码（保证输入符合ISBN号码
	的格式要求）。
	输出：
		输出一行，假如输入的ISBN号码的识别码正确，那么输出“Right”，否则，按照
	规定的格式，输出正确的ISBN号码（包括分隔符“-”）。
*/
/*
#include<iostream>

using namespace std;

int main()
{
	char str[15];
	cin >> str;
	int test = 0;
	int cnt;
	char* p;
	for (p = str,cnt = 1; cnt < 10; p++)
	{
		if (*p >= '0' && *p <= '9')
		{
			test += (*p - '0') * cnt;
			cnt++;
		}
	}
	p++;
	test %= 11;
	if (test == 10 && *p == 'X' || test == *p - '0')
		cout << "Right";
	else
	{
		if (test == 10)
			*p = 'X';
		else
			*p = test + '0';
		cout << str;
	}
	return 0;
}

/**/