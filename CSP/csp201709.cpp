/*
	题目编号：201709-1
	题目名称：打酱油

	题干：
		小明带着N元钱去买酱油。酱油10块钱一瓶，商家进行促销，每买3瓶送1瓶，或
	者每买5瓶送2瓶。请问小明最多可以得到多少瓶酱油。

	输入：
		输入的第一行包含一个整数N，表示小明可用于买酱油的钱数。N是10的整数倍，
	N不超过300。
	输出：
		输出一个整数，表示小明最多可以得到多少瓶酱油。
*/
/*
#include<iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int num = 0;

	num = N / 50 * 7;
	N %= 50;
	num += N / 30 * 4;
	N %= 30;
	num += N / 10;

	cout << num;

	return 0;
}


/*
	题目编号：201709-2
	题目名称：公共钥匙盒

	题干：
		有一个学校的老师共用N个教室，按照规定，所有的钥匙都必须放在公共钥匙盒里，
	老师不能带钥匙回家。每次老师上课前，都从公共钥匙盒里找到自己上课的教室的钥匙
	去开门，上完课后，再将钥匙放回到钥匙盒中。 
		钥匙盒一共有N个挂钩，从左到右排成一排，用来挂N个教室的钥匙。一串钥匙没有
	固定的悬挂位置，但钥匙上有标识，所以老师们不会弄混钥匙。 
		每次取钥匙的时候，老师们都会找到自己所需要的钥匙将其取走，而不会移动其他
	钥匙。每次还钥匙的时候，还钥匙的老师会找到最左边的空的挂钩，将钥匙挂在这个挂
	钩上。如果有多位老师还钥匙，则他们按钥匙编号从小到大的顺序还。如果同一时刻既
	有老师还钥匙又有老师取钥匙，则老师们会先将钥匙全还回去再取出。 
		今天开始的时候钥匙是按编号从小到大的顺序放在钥匙盒里的。有K位老师要上课，
	给出每位老师所需要的钥匙、开始上课的时间和上课的时长，假设下课时间就是还钥匙
	时间，请问最终钥匙盒里面钥匙的顺序是怎样的？

	输入：
		输入的第一行包含两个整数N, K。 
		接下来K行，每行三个整数w, s, c，分别表示一位老师要使用的钥匙编号、开始上课
	的时间和上课的时长。可能有多位老师使用同一把钥匙，但是老师使用钥匙的时间不会重
	叠。 
		保证输入数据满足输入格式，你不用检查数据合法性。
	输出：
		输出一行，包含N个整数，相邻整数间用一个空格分隔，依次表示每个挂钩上挂的钥
	匙编号。
*/
/*
#include<iostream>
#include<algorithm>

using namespace std;

struct Action
{
	int room;
	int time;
	int op;	//take->0  back->1
};

bool cmpAct(Action a, Action b)
{
	if (a.time != b.time)
		return a.time < b.time;
	else if (a.op != b.op)
		return a.op > b.op;
	return a.room < b.room;
}

int main()
{
	int N, K;
	cin >> N >> K;
	Action* acts = new Action[2 * K];
	int* keys = new int[N];
	for (int i = 0; i < N; i++)
		keys[i] = i+1;

	for (int i = 0; i < K; i++)
	{
		int w, s, c;
		cin >> w >> s >> c;
		acts[i + K].room=acts[i].room = w;
		acts[i].time = s;
		acts[i].op = 0;
		acts[i + K].time = s + c;
		acts[i + K].op = 1;
	}
	sort(acts, acts + 2 * K,cmpAct);
	for(int i=0;i<2*K;i++)
	{
		if(acts[i].op == 0)
		{
			for (int j = 0; j < N; j++)
			{
				if (acts[i].room == keys[j])
				{
					keys[j] = 0;
					break;
				}
			}
		}
		else
		{
			for(int j=0;j<N;j++)
				if (keys[j] == 0)
				{
					keys[j] = acts[i].room;
					break;
				}
		}
	}
	for (int i = 0; i < N; i++)
		cout << keys[i] << ' ';

	delete[] acts, keys;
	return 0;
}

	//易错点：对于操作Action的比较大小cmpAct函数的构造，注意取还顺序，尤其是
	//先归还op==1，在取op==0
/**/