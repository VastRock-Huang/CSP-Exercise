/*
	题目编号：201712-1
	题目名称：最小差值

	题干：
		给定n个数，请找出其中相差（差的绝对值）最小的两个数，输出它们的差值的
	绝对值。

	输入：
		输入第一行包含一个整数n。 
		第二行包含n个正整数，相邻整数之间使用一个空格分隔。
	输出：
		输出一个整数，表示答案。
*/
/*
#include<iostream>
#include<algorithm>
#include<cstdlib>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int* a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);
	int min = a[1] - a[0];
	int i;
	for (i = 2; i < n; i++)
	{
		int leap = abs(a[i] - a[i - 1]);
		if (leap < min)
			min = leap;
	}
	cout << min;
		

	delete[] a;
	return 0;
}


/*
	题目编号：201712-2
	题目名称：游戏

	题干：
		有n个小朋友围成一圈玩游戏，小朋友从1至n编号，2号小朋友坐在1号小朋友的顺
	时针方向，3号小朋友坐在2号小朋友的顺时针方向，……，1号小朋友坐在n号小朋友的
	顺时针方向。 
		游戏开始，从1号小朋友开始顺时针报数，接下来每个小朋友的报数是上一个小朋
	友报的数加1。若一个小朋友报的数为k的倍数或其末位数（即数的个位）为k，则该小
	朋友被淘汰出局，不再参加以后的报数。当游戏中只剩下一个小朋友时，该小朋友获胜。 
　　	例如，当n=5, k=2时： 
　		　1号小朋友报数1； 
　		　2号小朋友报数2淘汰； 
　		　3号小朋友报数3； 
　		　4号小朋友报数4淘汰； 
　		　5号小朋友报数5； 
　		　1号小朋友报数6淘汰； 
		　3号小朋友报数7； 
		　5号小朋友报数8淘汰； 
　		  3号小朋友获胜。 
		给定n和k，请问最后获胜的小朋友编号为多少？

	输入：
		输入一行，包括两个整数n和k，意义如题目所述。
	输出：
		输出一行，包含一个整数，表示获胜的小朋友编号。
*/
/*
#include<iostream>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int* per = new int[n] {0};
	int cnt = 0;
	int call = 0,turn=0;
	while (cnt<n-1)
	{
		if (!per[turn])
		{
			call++;
			if (call % k == 0 || call % 10 == k)
			{
				per[turn] = 1;
				cnt++;
			}
		}
		turn = (turn + 1) % n;
	}
	for (turn = 0; per[turn]; turn++);
	cout << turn + 1;

	delete[] per;
	return 0;
}

/**/