/*
	题目编号：201509-1
	题目名称：数列分段

	题干：
		给定一个整数数列，数列中连续相同的最长整数序列算成一段，问数列中共有
	多少段？

	输入：
		输入的第一行包含一个整数n，表示数列中整数的个数。
		第二行包含n个整数a1, a2, …, an，表示给定的数列，相邻的整数之间用一个
	空格分隔。
	输出：
		输出一个整数，表示给定的数列有多个段。
*/
/*
#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int opt = 1;
	int ipt1, ipt2;
	cin >> ipt1;
	for (int i = 1; i < n; i++)
	{
		cin >> ipt2;
		if (ipt2 != ipt1)
			opt++;
		ipt1 = ipt2;
	}
	cout << opt;

	return 0;
}



/*
	题目编号：201509-2
	题目名称：日期计算

	题干：
		给定一个年份y和一个整数d，问这一年的第d天是几月几日？ 
		注意闰年的2月有29天。满足下面条件之一的是闰年： 
		1） 年份是4的整数倍，而且不是100的整数倍； 
		2） 年份是400的整数倍。

	输入：
		输入的第一行包含一个整数y，表示年份，年份在1900到2015之间（包含1900和2015）。 
		输入的第二行包含一个整数d，d在1至365之间。
	输出：
		输出两行，每行一个整数，分别表示答案的月份和日期。
*/
/*
#include<iostream>

using namespace std;

int main()
{
	int y, d;
	cin >> y >> d;
	int monthday[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		monthday[2] = 29;
	int month = 0;
	while (d>monthday[month])
	{
		d = d - monthday[month];
		month++;
	}
	cout << month << endl << d;
	return 0;
}

/**/