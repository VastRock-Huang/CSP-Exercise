/*
	题目编号：201809-1
	题目名称：卖菜

	题干：
		在一条街上有n个卖菜的商店，按1至n的顺序排成一排，这些商店都卖一种蔬
	菜。第一天，每个商店都自己定了一个价格。店主们希望自己的菜价和其他商店的
	一致，第二天，每一家商店都会根据他自己和相邻商店的价格调整自己的价格。具
	体的，每家商店都会将第二天的菜价设置为自己和相邻商店第一天菜价的平均值
	（用去尾法取整）。注意，编号为1的商店只有一个相邻的商店2，编号为n的商店只
	有一个相邻的商店n-1，其他编号为i的商店有两个相邻的商店i-1和i+1。给定第一
	天各个商店的菜价，请计算第二天每个商店的菜价。

	输入：
		输入的第一行包含一个整数n，表示商店的数量。第二行包含n个整数，依次表示
	每个商店第一天的菜价。
	输出：
		输出一行，包含n个正整数，依次表示每个商店第二天的菜价。
*/
/*
#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int* input = new int[n];
	for (int i = 0; i < n; i++)
		cin >> input[i];
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			cout << (input[0] + input[1]) / 2 << ' ';
		else if (i == n - 1)
			cout << (input[i] + input[i - 1]) / 2;
		else
			cout << (input[i - 1] + input[i] + input[i + 1]) / 3 << ' ';
	}

	delete[] input;
	return 0;
}


/*
	题目编号：201809-2
	题目名称：买菜

	题干：
		小H和小W来到了一条街上，两人分开买菜，他们买菜的过程可以描述为，去店里买
	一些菜然后去旁边的一个广场把菜装上车，两人都要买n种菜，所以也都要装n次车。具
	体的，对于小H来说有n个不相交的时间段[a1,b1],[a2,b2]…[an,bn]在装车，对于小W
	来说有n个不相交的时间段[c1,d1],[c2,d2]…[cn,dn]在装车。其中，一个时间段[s, t]
	表示的是从时刻s到时刻t这段时间，时长为t-s。
		由于他们是好朋友，他们都在广场上装车的时候会聊天，他们想知道他们可以聊多
	长时间。

	输入：
		输入的第一行包含一个正整数n，表示时间段的数量。接下来n行每行两个数ai，bi，
	描述小H的各个装车的时间段。接下来n行每行两个数ci，di，描述小W的各个装车的时
	间段。
	输出：
		输出一行，一个正整数，表示两人可以聊多长时间。

*/
/*
//法一：时间复杂度O(n^2)
//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	int** h = new int *[n];
//	int i;
//	for (i = 0; i < n; i++)
//		h[i] = new int[2];
//	for (i = 0; i < n; i++)
//	{
//		cin >> h[i][0] >> h[i][1];
//	}
//	long long opt = 0;
//	for (int j = 0; j < n; j++)
//	{
//		int w1, w2;
//		cin >> w1 >> w2;
//		int min, max;
//		for (i = 0; i < n; i++)
//		{
//			if (h[i][0] >= w2 || h[i][1] <= w1)
//				continue;
//			min = (w1 >= h[i][0]) ? w1 : h[i][0];
//			max = (w2 <= h[i][1]) ? w2 : h[i][1];
//			opt += (long long)(max - min);
//		}
//
//	}
//	cout << opt;
//	for (i = 0; i < n; i++)
//		delete[] h[i];
//	delete[] h;
//	return 0;
//}

	//易错点：此题关键在于小H和小W的数据段不是一一对应的所以需要两重循环进行遍历


//法二：时间复杂度O(n)
#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int** h = new int* [n];
	int** w = new int* [n];
	int i, j;
	for (i = 0; i < n; i++)
	{
		h[i] = new int[2];
		w[i] = new int[2];
	}
	for (i = 0; i < n; i++)
	{
		cin >> h[i][0] >> h[i][1];
	}
	long long opt = 0;
	for (j = 0; j < n; j++)
		cin >> w[j][0] >> w[j][1];

	i = 0, j = 0;
	while (i < n && j < n)	//i是h索引，j是w索引
	{
		int max, min;
		if (w[j][1] <= h[i][0])
		{	//无交集，且w时间偏早读取下一个w数据
			j++;
			continue;
		}
		else if (w[j][0] >= h[i][1])
		{	//无交集，且h时间偏早读取下一个h数据
			i++;
			continue;
		}
		//以下均为有交集情况
		//h结束时间晚时读取下一个w数据，w结束时间晚时读取下一个h数据
		//max取h、w结束时间小者，min取h、w起始时间大者
		//注：min的计算必须放在i、j自增前，否则有误
		else if (w[j][1] < h[i][1])
		{
			max = w[j][1];
			min = ((w[j][0] >= h[i][0]) ? w[j][0] : h[i][0]);
			j++;
		}
		else if (w[j][1] >= h[i][1])
		{
			max = h[i][1];
			min = ((w[j][0] >= h[i][0]) ? w[j][0] : h[i][0]);
			i++;
		}
		opt += (long long)max - min;
	}
	cout << opt;
	for (i = 0; i < n; i++)
	{
		delete[] h[i], w[i];
	}
	delete[] h, w;
	return 0;
}



/*
	题目编号: 201809-3
	题目名称: 元素选择器
*/


/**/