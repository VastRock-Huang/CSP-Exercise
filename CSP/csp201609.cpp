/*
	题目编号：201609-1
	题目名称：最大波动

	题干：
		小明正在利用股票的波动程度来研究股票。小明拿到了一只股票每天收盘时的
	价格，他想知道，这只股票连续几天的最大波动值是多少，即在这几天中某天收盘
	价格与前一天收盘价格之差的绝对值最大是多少。

	输入：
		输入的第一行包含了一个整数n，表示小明拿到的收盘价格的连续天数。 
		第二行包含n个正整数，依次表示每天的收盘价格。
	输出：
		输出一个整数，表示这只股票这n天中的最大波动值。
*/
/*
#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	cin >> a[0];
	int max = 0;
	for (int i = 1; i < n; i++)
	{
		cin >> a[i];
		int leap = a[i] - a[i - 1];
		leap = leap > 0 ? leap : -leap;
		if (leap > max)
			max = leap;
	}
	cout << max;

	delete[] a;
	return 0;
}


/*
	题目编号：201609-2
	题目名称：火车购票

	题干：
		请实现一个铁路购票系统的简单座位分配算法，来处理一节车厢的座位分配。
		假设一节车厢有20排、每一排5个座位。为方便起见，我们用1到100来给所有
	的座位编号，第一排是1到5号，第二排是6到10号，依次类推，第20排是96到100
	号。
		购票时，一个人可能购一张或多张票，最多不超过5张。如果这几张票可以安
	排在同一排编号相邻的座位，则应该安排在编号最小的相邻座位。否则应该安排
	在编号最小的几个空座位中（不考虑是否相邻）。
		假设初始时车票全部未被购买，现在给了一些购票指令，请你处理这些指令。

	输入：
		输入的第一行包含一个整数n，表示购票指令的数量。
		第二行包含n个整数，每个整数p在1到5之间，表示要购入的票数，相邻的两个
	数之间使用一个空格分隔。
	输出：
		输出n行，每行对应一条指令的处理结果。
		对于购票指令p，输出p张车票的编号，按从小到大排序。
*/
/*
#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int seat[20];
	int flags[5] = { 0 };	
	//flags用来标记每一种购买是否还能连续
	//flags[i]表示购买i+1张票时位置是否还能连续，0可以，1不可以
	for (int i = 0; i < 20; i++)
		seat[i] = 0;
	for (int i = 0; i < n; i++)
	{
		int buy;
		cin >> buy;
		int j;
		if (flags[buy - 1] == 0)
		{
			for (j = 0; j < 20; j++)
			{
				if (5 - seat[j] >= buy)
				{
					for (int cnt = 0; cnt < buy; cnt++, seat[j]++)
						cout << j * 5 + seat[j] + 1 << ' ';
					cout << endl;
					break;
				}
			}
			if (j == 20)
			{
				flags[buy - 1] = 1;
			}
		}
		if (flags[buy - 1] == 1)
		{
			int cnt=0;
			for(j=0;cnt<buy&&j<20;j++)
				for (; seat[j] < 5; seat[j]++)
				{
					cout << j * 5 + seat[j] + 1 << ' ';
					cnt++;
				}
			cout << endl;
		}		
	}
	return 0;
}
/**/