﻿
/*
	试题编号：201909-1
	试题名称：小明种苹果

	题目描述：
		小明在他的果园里种了一些苹果树。为了保证苹果的品质，在种植过程中要进行
	若干轮疏果操作，也就是提前从树上把不好的苹果去掉。第一轮疏果操作开始前，小
	明记录了每棵树上苹果的个数。每轮疏果操作时，小明都记录了从每棵树上去掉的苹
	果个数。在最后一轮疏果操作结束后，请帮助小明统计相关的信息。

	输入格式：
		从标准输入读入数据。
		第1行包含两个正整数N和M，分别表示苹果树的棵数和疏果操作的轮数。
		第1+i行（1<=i<=N），每行包含M+1个整数ai0,ai1,...,aiM  。其中ai0为正整数，
	表示第一轮疏果操作开始前第i棵树上苹果的个数。aij（1<=j<=M）为零或负整数，
	表示第j轮疏果操作时从第i棵树上去掉的苹果个数。如果为零，表示没有去掉苹果；如
	果为负，其绝对值为去掉的苹果个数。
		每行中相邻两个数之间用一个空格分隔。

	输出格式：
		输出到标准输出。
		输出只有一行，包含三个整数T、k和P，其中，
		T为最后一轮疏果操作后所有苹果树上剩下的苹果总数（假设苹果不会因为其他原因减少）
		k为疏果个数（也就是疏果操作去掉的苹果个数）最多的苹果树编号（如有并列，
	输出满足条件的最小编号）
		P为该苹果树的疏果个数。
		相邻两个数之间用一个空格分隔。输入数据保证是正确的，也就是说，每棵树在全
	部疏果操作结束后剩下的苹果个数是非负的。
*/

/*
#include<iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	int tree;	//每棵树的初始苹果数
	int T = 0;
	int k, P=0;
	for (int i = 0; i < N; i++)
	{
		int cut;
		int j;
		int input;	//每次输入的疏果数（负数）
		cin >> tree;
		for (j = 1,cut=0; j < M + 1; j++)
		{
			cin >> input;
			cut -= input;
		}
		if (cut> P)
		{
			P = cut;
			k = i+1;
		}
		T += tree - cut;
	}
	cout << T << ' ' << k << ' ' << P;

	//for (int i = 0; i < N; i++)
	//	delete[] a[i];
	//delete[] a;
	return 0;
}


/*
	试题编号：201912-2
	试题名称：小明种苹果（续）

	题干：
		小明在他的果园里种了一些苹果树，这些苹果树排列成一个圆。为了保证苹果的
	品质，在种植过程中要进行疏果操作。为了更及时地完成疏果操作，小明会不时地检
	查每棵树的状态，根据需要进行疏果。检查时，如果发现可能有苹果从树上掉落，小
	明会重新统计树上的苹果个数（然后根据之前的记录就可以判断是否有苹果掉落了），
	在全部操作结束后，请帮助小明统计相关的信息。

	输入：
		从标准输入读入数据。
		第1行包含一个正整数N，表示苹果树的棵数。
		第1+i行（1<=i<=N），每行的格式为mi，ai1，ai2....，其中，第一个正整数mi
	表示本行后面的整数个数。后续的mi个整数表示小明对第i棵苹果树的操作记录。若aij
	（1<=j<=m）为正整数，则表示小明进行了重新统计该棵树上的苹果个数的操作，统计
	的苹果个数为aij；若为零或负整数，则表示一次疏果操作，去掉的苹果个数是|aij|。
		输入保证一定是正确的，满足：
		1、ai1>0，即对于每棵树的记录，第一个操作一定是统计苹果个数（初始状态，
	此时不用判断是否有苹果掉落）；
		2、每次疏果操作保证操作后树上的苹果个数仍为正。
	输出：
		输出到标准输出。
		输出只有一行，包含三个整数T、D、E，其中，
		T为全部疏果操作结束后所有苹果树上剩下的苹果总数（假设每棵苹果树在最后一
	次统计苹果个数操作后苹果不会因为疏果以外的原因减少）；
		D为发生苹果掉落的苹果树的棵数；
		E为相邻连续三棵树发生苹果掉落情况的组数。
		对于第三个统计量的解释：N棵苹果树A1，A2...AN 排列成一个圆，那么A1与A2相邻，
	A2与A3相邻，…AN−1与AN相邻，AN与A1相邻。如果Ai−1，Ai，Ai+1，这三棵树都发生了
	苹果掉落的情况，则记为一组。形式化的，有
		E=∣{Ai,∣Drop(Pred(Ai))∧Drop(Ai)∧Drop(Succ(Ai))}
	其中，Drop(Ai)表示苹果树Ai是否发生苹果掉落的情况，Pred(Ai)表示Ai的前一棵树Ai−1
	（如果i>1）或者AN（如果i=1），Succ(Ai) 表示Ai的后一棵树Ar+1（如果i<N）或者A1
	（如果i=N）

*/
/*
#include<iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int D = 0;
	int E = 0;
	bool* dropTree = new bool[N] {false};
	int T = 0;
	for (int i = 0; i < N; i++)
	{
		int m,num;
		cin >> m >> num;
		int ipt;
		for (int j = 1; j < m; j++)
		{
			cin >> ipt;
			if (ipt <= 0)
			{
				num += ipt;
			}
			if (ipt > 0 && ipt != num)
			{
				dropTree[i] = true;
				num = ipt;
			}
		}
		T += num;
	}
	for (int i = 0; i < N; i++)
	{
		if (dropTree[i])
		{
			D++;		
			if (dropTree[(i + 1) % N] && dropTree[(i + 2) % N])
				E++;
		}
	}

	cout << T << ' ' << D << ' ' << E;

	delete[] dropTree;
	return 0;
}
	//易错点：有掉落的树的数量需要在统计E时的循环中统计，因为在for-j循环ipt>0时统
	//计可能在一棵树上统计多次

/**/