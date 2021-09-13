/*
	题目编号：201412-1
	题目名称：门禁系统

	题干：
		涛涛最近要负责图书馆的管理工作，需要记录下每天读者的到访情况。每位读者
	有一个编号，每条记录用读者的编号来表示。给出读者的来访记录，请问每一条记录
	中的读者是第几次出现。

	输入：
		输入的第一行包含一个整数n，表示涛涛的记录条数。 
		第二行包含n个整数，依次表示涛涛的记录中每位读者的编号。
	输出：
		输出一行，包含n个整数，由空格分隔，依次表示每条记录中的读者编号是第几次
	出现。
*/
/*
#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int* a = new int[n] {0};
	int i,ipt;
	for (i = 0; i < n; i++)
	{
		cin >> ipt;
		a[ipt - 1]++;
		cout << a[ipt - 1] << ' ';
	}

	delete[] a;
	return 0;
}


/*
	题目编号：201412-2
	题目名称：Z字形扫描

	题干：
		在图像编码的算法中，需要将一个给定的方形矩阵进行Z字形扫描(Zigzag Scan)。
	给定一个n×n的矩阵，Z字形扫描的过程如下图所示：

	对于下面的4×4的矩阵，
		1 5 3 9
		3 7 5 6
		9 4 6 4
		7 3 1 3
	对其进行Z字形扫描后得到长度为16的序列：
		1 5 3 9 7 3 9 5 4 7 3 6 6 4 1 3
		请实现一个Z字形扫描的程序，给定一个n×n的矩阵，输出对这个矩阵进行Z字形扫
	描的结果。

	输入：
		输入的第一行包含一个整数n，表示矩阵的大小。
		输入的第二行到第n+1行每行包含n个正整数，由空格分隔，表示给定的矩阵。
	输出：
		输出一行，包含n×n个整数，由空格分隔，表示输入的矩阵经过Z字形扫描后的结果。
*/

/*
//法一：需要两重循环
//#include<iostream>
//
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	int** a = new int* [n];
//	for (int i = 0; i < n; i++)
//		a[i] = new int[n];
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			cin >> a[i][j];
//
//	int i = 0, j = 0,sum=0;
//	while (sum<2*n-1)
//	{
//		cout << a[i][j] << ' ';
//		sum++;
//		if (i == 0 && j < n - 1)
//		{
//			j++;
//			for (; j > 0; j--,i=sum-j)
//			{
//				cout << a[i][j]<<' ';
//			}
//		}
//		else if (j == 0 && i < n - 1)
//		{
//			i++;
//			for (; i > 0; i--, j = sum - i)
//			{
//				cout << a[i][j] << ' ';
//			}
//		}
//		else if (i == n - 1 && j < n - 1)
//		{
//			j++;
//			for (; j < n-1; j++, i = sum - j)
//			{
//				cout << a[i][j] << ' ';
//			}
//		}
//		else if (j == n - 1 && i < n - 1)
//		{
//			i++;
//			for (; i < n-1; i++, j = sum - i)
//			{
//				cout << a[i][j] << ' ';
//			}
//		}
//		
//	}
//
//	for (int i = 0; i < n; i++)
//		delete[] a[i];
//	delete[] a;
//	return 0;
//}

//法二：使用一重循环
#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	int i = 0, j = 0;
	int d = 0;	//d用来倾斜走，1是向左下走、-1是向右上走
	while (1)
	{
		cout << a[i][j] << ' ';
		if (i == 0 && j < n - 1)	//if语句用来调整边界
		{
			j++;
			d = 1;
			cout << a[i][j] << ' ';
		}
		else if (j == 0 && i < n - 1)
		{
			i++;
			d = -1;
			cout << a[i][j] << ' ';
		}
		//理论上后两个if分支不需要与n-1比较，但不加只能90分，原因未知
		else if (i == n - 1&& j < n - 1)	
		{
			j++;
			d = -1;
			cout << a[i][j] << ' ';
		}
		else if (j == n - 1&& i < n - 1)
		{
			i++;
			d = 1;
			cout << a[i][j] << ' ';
		}
		if (i == n - 1 && j == n - 1)
			break;		
		i += d;	//用来倾斜走
		j -= d;	
	}
	
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

	//注：实践得知，C语言中的scanf和printf比C++中的cin和cout速度快

/**/