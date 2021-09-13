/*
	题目编号：201503-1
	题目名称：图像旋转

	题干：
		旋转是图像处理的基本操作，在这个问题中，你需要将一个图像逆时针旋转90度。 
	计算机中的图像表示可以用一个矩阵来表示，为了旋转一个图像，只需要将对应的矩
	阵旋转即可。

	输入：
		输入的第一行包含两个整数n, m，分别表示图像矩阵的行数和列数。 
		接下来n行每行包含m个整数，表示输入的图像。
	输出：
		输出m行，每行包含n个整数，表示原始矩阵逆时针旋转90度后的矩阵。
*/
/*
#include<iostream>

using namespace std;

int main()
{
	int n, m;
	int i, j;
	cin >> n >> m;
	int** a = new int* [n];
	for (i = 0; i < n; i++)
		a[i] = new int[m];

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> a[i][j];

	for (i = m - 1; i >= 0; i--)
	{
		for (j = 0; j < n; j++)
			cout << a[j][i] << ' ';
		cout << endl;
	}

	for (i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

/*
	题目编号：201503-2
	题目名称：数字排序

	题干：
		给定n个整数，请统计出每个整数出现的次数，按出现次数从多到少的顺序输出。

	输入：
		输入的第一行包含一个整数n，表示给定数字的个数。 
		第二行包含n个整数，相邻的整数之间用一个空格分隔，表示所给定的整数。
	输出：
		输出多行，每行包含两个整数，分别表示一个给定的整数和它出现的次数。按出
	现次数递减的顺序输出。如果两个整数出现的次数一样多，则先输出值较小的，然后
	输出值较大的。
*/
/*
#include<iostream>
#include<algorithm>

using namespace std;

struct Node
{
	int num;
	int cnt;
};

bool cmpCnt(Node a, Node b)
{
	if (a.cnt == b.cnt)
		return a.num < b.num;
	return a.cnt > b.cnt;
}

int main()
{
	int n;
	cin >> n;
	Node a[1001];
	for (int i = 0; i < 1001; i++)
	{
		a[i].num = i;
		a[i].cnt = 0;
	}
	for (int i = 0; i < n; i++)
	{
		int ipt;
		cin >> ipt;
		a[ipt].cnt++;
	}
	sort(a, a + 1001, cmpCnt);
	int i = 0;
	while (a[i].cnt)
	{
		cout << a[i].num << ' ' << a[i].cnt << endl;
		i++;
	}
	return 0;
}

/**/