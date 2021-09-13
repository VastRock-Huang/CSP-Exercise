
/*
	试题编号：201912-1
	试题名称：报数

	题目描述：
		甲乙丙丁决定玩一个报数的游戏来打发时间。游戏规则为四个人从1开始
	轮流进行报数，但如果需要报出的数是7的倍数或含有数字7则直接跳过。
	此外大家约定，在总共报出了n个数后（不计入被跳过的数）游戏结束。现在需要你
	来帮忙统计，游戏过程中每个人各自跳过了几次。

	输入格式：
		从标准输入读入数据。
		输入仅一行，包含一个正整数n，表示报出了多少个数后游戏结束。
	输出格式：
		输出到标准输出。
		输出共四行，每行一个整数，依次表示甲乙丙丁四人在游戏过程中跳过的次数。
*/

/*
#include<iostream>

using namespace std;

int jumpCall(int call)
{
	if (call % 7 == 0)
		return 1;
	do
	{
		if (call % 10 == 7)
			return 1;
		call /= 10;
	} while (call);
	return 0;
}

int main()
{
	int n;
	cin >> n;
	int i, turn, call;
	int per[4] = { 0 };
	for (i = 1,call=1,turn=0; i <= n; call++)
	{

		if (jumpCall(call))
		{
			per[turn]++;
		}
		else
			i++;
		turn = (turn + 1) % 4;
	}
	for (i = 0; i < 4; i++)
		cout << per[i] << endl;
	return 0;
}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//int judgeI(int i)
//{
//	if (i % 7 == 0)
//		return 1;
//	do
//	{
//		if (i % 10 == 7)
//			return 1;
//		i = i / 10;
//	} while (i);
//	return 0;
//}
//
//int main()
//{
//	int n;
//	int i = 1;	//i报数(包括跳过的数)
//	int j = 0;	//j计数器，记录未跳过的数的个数
//	int turn = 0;	//对应人
//	int person[4] = { 0 };
//
//	scanf("%d", &n);
//
//	while (j<n)
//	{
//		if (judgeI(i))
//			person[turn]++;
//		else
//			j++;
//
//		i++;
//		turn = (turn + 1) % 4;
//	}
//
//	for (i = 0; i < 4; i++)
//		printf("%d\n", person[i]);
//
//	return 0;
//}


/*
	试题编号：2019212-2
	试题名称：回收站选址

	题目描述：
		通过无人机航拍我们已经知晓了n处尚待清理的垃圾位置，其中第i（1<=i<=n）
		处的坐标为（x，y），保证所有的坐标均为整数。
		我们希望在垃圾集中的地方建立些回收站。具体来说，对于一个位置（x, y）
		是否适合建立回收站，我们主要考虑以下几点：
			（x, y）必须是整数坐标，且该处存在垃圾：上下左右四个邻居位置，即
			（x, y+1），（x, y-1），（x+1, y）和（x-1, y）处，必须全部存在垃
			圾：进一步地，我们会对满足上述两个条件的选址进行评分，分数为不大
			于4的自然数，表示在（x±1，y±1）四个对角位置中有几处存在垃圾。
			现在，请你统计一下每种得分的选址个数。
	
	输入格式：
		从标准输入读入数据。输入总共有n+1行。
		第1行包含一个正整数n，表示已查明的垃圾点个数。
		第1+i行（1<=i<=n）包含由一个空格分隔的两个整数xi和yi，表示第i处垃圾的坐标。
		保证输入的n个坐标互不相同。
	输出格式：
		输出到标准输出。
		输出共五行，每行一个整数，依次表示得分为0、1、2、3和4的回收站选址个数。
*/

/*
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//
//int main()
//{
//	int n;
//	int* x, * y;
//	int i,j;
//	int score[5] = { 0 };
//	int counti = 0;
//	int scorei = 0;
//
//	scanf("%d", &n);
//	x = (int*)malloc(sizeof(int)*n);
//	y = (int*)malloc(sizeof(int)*n);
//	for (i = 0; i < n; i++)
//		scanf("%d %d", x + i, y + i);
//
//	for (i = 0; i < n; i++)
//	{
//		counti = 0;
//		scorei = 0;
//		for (j = 0; j < n; j++)
//		{
//			if ((x[j] - x[i]) * (y[j] - y[i]) == 0 && (abs(x[j] - x[i]) == 1 || abs(y[j] - y[i]) == 1))
//				counti++;
//			if (abs(x[j] - x[i]) * abs(y[j] - y[i]) == 1)
//				scorei++;
//		}
//		if (counti == 4)
//			score[scorei]++;
//	}
//
//	for (i = 0; i < 5; i++)
//		printf("%d\n", score[i]);
//
//
//	free(x);
//	free(y);
//	return 0;
//}

#include<iostream>
#include<set>

using namespace std;

struct node
{
	int x, y;
	node(int x1,int y1):x(x1),y(y1){}
	bool operator<(const node& oth)const
	{
		if (x != oth.x)
			return x < oth.x;
		return y < oth.y;
	}
};

set<node> s;

bool findNode(int x,int y)
{
	if (s.find(node(x,y)) != s.end())
		return 1;
	return 0;
}

int main()
{
	int n;
	cin >> n;
	int opt[5] = { 0 };
	
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		s.insert(node(x, y));
	}

	for (set<node>::iterator it = s.begin(); it != s.end();it++)
	{
		int x = it->x, y = it->y;
		if (findNode(x, y + 1) && findNode(x, y - 1) && findNode(x + 1, y) && findNode(x - 1, y))
		{
			int cnt = 0;
			if (findNode(x + 1, y + 1))
				cnt++;
			if (findNode(x + 1, y - 1))
				cnt++;
			if (findNode(x - 1, y + 1))
				cnt++;
			if (findNode(x - 1, y - 1))
				cnt++;
			opt[cnt]++;
		}
	}
	for (int i = 0; i < 5; i++)
		cout << opt[i] << endl;

	return 0;
		
}

	//注：两种方法第一种比较笨，第二种运用了set数据结构，相比来说时间复杂度第二
	//	种略优，第一种空间使用和代码长度略优
	



/**/