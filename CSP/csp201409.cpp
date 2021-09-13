/*
	题目编号：201409-1
	题目名称：相邻数对

	题干：
		给定n个不同的整数，问这些数中有多少对整数，它们的值正好相差1。

	输入：
		输入的第一行包含一个整数n，表示给定整数的个数。 
		第二行包含所给定的n个整数。
	输出：
		输出一个整数，表示值正好相差1的数对的个数。
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
	int opt = 0;
	for (int i = 0; i < n - 1; i++)
		if (a[i] + 1 == a[i + 1])
			opt++;
	cout << opt;

	delete[] a;
	return 0;
}


/*
	题目编号：201409-2
	题目名称：画图

	题干：
		在一个定义了直角坐标系的纸上，画一个(x1,y1)到(x2,y2)的矩形指将横坐标范
	围从x1到x2，纵坐标范围从y1到y2之间的区域涂上颜色。 
		下图给出了一个画了两个矩形的例子。第一个矩形是(1,1) 到(4, 4)，用绿色和
	紫色表示。第二个矩形是(2, 3)到(6, 5)，用蓝色和紫色表示。图中，一共有15个单
	位的面积被涂上颜色，其中紫色部分被涂了两次，但在计算面积时只计算一次。在实
	际的涂色过程中，所有的矩形都涂成统一的颜色，图中显示不同颜色仅为说明方便。 

	输入：
		输入的第一行包含一个整数n，表示要画的矩形的个数。 
		接下来n行，每行4个非负整数，分别表示要画的矩形的左下角的横坐标与纵坐标，
	以及右上角的横坐标与纵坐标。

	输出：
		输出一个整数，表示有多少个单位的面积被涂上颜色。
*/
/*
#include<iostream>

using namespace std;
int main()
{
	int n;
	cin >> n;

	bool a[101][101] = { false };
	int maxx = 0, maxy = 0, minx = 101, miny = 101;
	for (int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		minx = minx <= x1 ? minx : x1;
		miny = miny <= y1 ? miny : y1;
		maxx = maxx >= x2 ? maxx : x2;
		maxy = maxy >= y2 ? maxy : y2;
		int x, y;
		for (x = x1; x < x2; x++)
			for (y = y1; y < y2; y++)
				a[x][y] = true;		
	}
	int opt = 0;
	for (int i = minx; i <= maxx; i++)
		for (int j =miny; j <= maxy; j++)
			if (a[i][j]==true)
				opt++;
	cout << opt;
	return 0;
}

//法二：使用set和pair容器，相比法一代码简练，但是时间和空间都比前者差
//#include<iostream>
//#include<set>
//#include<utility>
//using namespace std;
//
//int main()
//{
//	set<pair<int, int> > s;
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		int x, y, x1, y1, x2, y2;
//		cin >> x1 >> y1 >> x2 >> y2;
//		for (x = x1; x < x2; x++)
//			for (y = y1; y < y2; y++)
//				s.insert(pair<int, int>(x, y));
//	}
//	cout << s.size();
//	return 0;
//}
/**/