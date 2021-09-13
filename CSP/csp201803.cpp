/*
	题目编号：201803-1
	题目名称：跳一跳

	题干：
		近来，跳一跳这款小游戏风靡全国，受到不少玩家的喜爱。 
		简化后的跳一跳规则如下：玩家每次从当前方块跳到下一个方块，如果没有跳到
	下一个方块上则游戏结束。 
		如果跳到了方块上，但没有跳到方块的中心则获得1分；跳到方块中心时，若上
	一次的得分为1分或这是本局游戏的第一次跳跃则此次得分为2分，否则此次得分比上
	一次得分多两分（即连续跳到方块中心时，总得分将+2，+4，+6，+8…）。 
		现在给出一个人跳一跳的全过程，请你求出他本局游戏的得分（按照题目描述的
	规则）。

	输入：
		输入包含多个数字，用空格分隔，每个数字都是1，2，0之一，1表示此次跳跃跳
	到了方块上但是没有跳到中心，2表示此次跳跃跳到了方块上并且跳到了方块中心，0
	表示此次跳跃没有跳到方块上（此时游戏结束）。
	输出：
		输出一个整数，为本局游戏的得分（在本题的规则下）。
*/
/*
#include<iostream>

using namespace std;

int main()
{
	int ipt;
	int score = 0;
	cin >> ipt;
	int inc = 1;
	while (ipt)
	{
		if (ipt == 1)
			inc = 1;
		else if (inc == 1)
			inc = 2;
		else
			inc += 2;

		score += inc;

		cin >> ipt;
	}
	cout << score;
	return 0;
}



/*
	题目编号：201803-2
	题目名称：碰撞的小球

	题干：
		数轴上有一条长度为L（L为偶数)的线段，左端点在原点，右端点在坐标L处。有n个
	不计体积的小球在线段上，开始时所有的小球都处在偶数坐标上，速度方向向右，速度
	大小为1单位长度每秒。 
		当小球到达线段的端点（左端点或右端点）的时候，会立即向相反的方向移动，速度
	大小仍然为原来大小。 
		当两个小球撞到一起的时候，两个小球会分别向与自己原来移动的方向相反的方向，
	以原来的速度大小继续移动。 
		现在，告诉你线段的长度L，小球数量n，以及n个小球的初始位置，请你计算t秒之后，
	各个小球的位置。

	输入：
		输入的第一行包含三个整数n, L, t，用空格分隔，分别表示小球的个数、线段长度和
	你需要计算t秒之后小球的位置。 
		第二行包含n个整数a1, a2, …, an，用空格分隔，表示初始时刻n个小球的位置。
	输出：
		出一行包含n个整数，用空格分隔，第i个整数代表初始时刻位于ai的小球，在t秒之后
	的位置。
*/
/*
#include<iostream>
#include<algorithm>

using namespace std;

struct Ball
{
	int index;
	int pos;
	int v;
};

bool cmpPos(Ball a, Ball b)
{
	return a.pos < b.pos;
}

bool cmpIdx(Ball a, Ball b)
{
	return a.index < b.index;
}

//法一：时间复杂度O(2*nlogn+t*n)
//int main()
//{
//	int n, L, t;
//	cin >> n >> L >> t;
//	Ball* balls = new Ball[n];
//	int i, j;
//	for (i = 0; i < n; i++)
//	{
//		cin >> balls[i].pos;
//		balls[i].v = 1;
//		balls[i].index = i;
//	}
//	sort(balls, balls + n,cmpPos);
//	for (i = 0; i < t; i++)
//	{
//		for (j = 0; j < n; j++)
//			balls[j].pos += balls[j].v;
//		for (j = 0; j < n; j++)
//		{
//			if (balls[j].pos == L || balls[j].pos == 0)
//				balls[j].v *= -1;
//			else if (j > 0 && balls[j].pos == balls[j - 1].pos)
//				balls[j].v *= -1;
//			else if (j < n - 1 && balls[j].pos == balls[j + 1].pos)
//				balls[j].v *= -1;
//		}	
//	}
//	sort(balls, balls + n,cmpIdx);
//
//	for (i = 0; i < n; i++)
//		cout << balls[i].pos<< ' ';
//
//	delete[] balls;
//	return 0;
//}


//法二：时间复杂度O(nlogn)
int main()
{
	int n, L, t;
	cin >> n >> L >> t;
	Ball* balls = new Ball[n];
	int* temp = new int[n];
	int i, j;
	for (i = 0; i < n; i++)
	{
		cin >> balls[i].pos;
		balls[i].v = 1;
		balls[i].index = i;
	}
		
	for (i = 0; i < n; i++)
	{
		temp[i] = balls[i].pos + t;
		temp[i] = ((temp[i] / L) % 2 ? (L - temp[i] % L) : temp[i] % L);
	}
	//因为小球碰撞后相当于彼此交换，因此可以看做小球在L间来回运动而无碰撞
	//但这样算出的temp并不是原来小球的位置因此需要通过排序来对应
	sort(temp, temp + n);
	//先将小球的结束位置temp从小到大排序
	sort(balls, balls + n,cmpPos);
	//再将小球按初始位置从小到大排序
	for (i = 0; i < n; i++)
	{
		balls[i].pos = temp[i];
		//这样小球的初始与结束位置达到对应
	}
	
	sort(balls, balls + n,cmpIdx);
	//输出时需要按照输入的顺序因此再按照输入顺序排序
	for (i = 0; i < n; i++)
		cout << balls[i].pos << ' ';

	delete[] balls;
	return 0;
}
	//注：该种方法不需要每一秒都判断小球的状态，因此时间复杂度相对较低（在t比较大时），
	//但需要多次排序来对应小球顺序，容易出错

/**/