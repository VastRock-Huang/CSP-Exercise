/*
	题目编号：201512-1
	题目名称：数位之和

	题干：
		给定一个十进制整数n，输出n的各位数字之和。

	输入：
		输入一个整数n。
	输出：
		输出一个整数，表示答案。
*/
/*
#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int sum = 0;
	do
	{
		sum += n % 10;
		n /= 10;
	} while (n);
	cout << sum;
	return 0;
}

/*
	题目编号：201512-2
	题目名称：消除类游戏

	题干：
		消除类游戏是深受大众欢迎的一种游戏，游戏在一个包含有n行m列的游戏棋盘上
	进行，棋盘的每一行每一列的方格上放着一个有颜色的棋子，当一行或一列上有连续
	三个或更多的相同颜色的棋子时，这些棋子都被消除。当有多处可以被消除时，这些
	地方的棋子将同时被消除。 
		现在给你一个n行m列的棋盘，棋盘中的每一个方格上有一个棋子，请给出经过一
	次消除后的棋盘。 
		请注意：一个棋子可能在某一行和某一列同时被消除。

	输入：
		输入的第一行包含两个整数n, m，用空格分隔，分别表示棋盘的行数和列数。 
		接下来n行，每行m个整数，用空格分隔，分别表示每一个方格中的棋子的颜色。
	颜色使用1至9编号。
	输出：
		输出n行，每行m个整数，相邻的整数之间使用一个空格分隔，表示经过一次消除
	后的棋盘。如果一个方格中的棋子被消除，则对应的方格输出0，否则输出棋子的颜
	色编号。
*/
/*
#include<iostream>

using namespace std;

struct Node
{
	int color;
	int flag;
};

int main()
{
	int n, m;
	cin >> n >> m;
	Node** a = new Node * [n];
	for (int i = 0; i < n; i++)
		a[i] = new Node[m];
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j].color;
			a[i][j].flag = 1;
		}

	for (int i = 0; i < n; i++)
	{
		int j = 0;
		while (j<m-2)
		{
			if (a[i][j].color == a[i][j + 1].color && a[i][j].color == a[i][j + 2].color)
				for (int temp = a[i][j].color;j < m && a[i][j].color == temp; j++)
					//注意此处要带上j<m，下面j<n同
					a[i][j].flag = 0;
			else
				j++;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int j = 0;
		while (j<n-2)
		{
			if (a[j][i].color == a[j + 1][i].color && a[j][i].color == a[j + 2][i].color)
				for (int temp = a[j][i].color; j < n && a[j][i].color == temp; j++)
					a[j][i].flag = 0;
			else
				j++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << a[i][j].color * a[i][j].flag << ' ';
		cout << endl;
	}

	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

	//易错点：在内部循环中对外部循环变量有改变时，要在内部循环的判断语句中加入
	//外部循环的判断语句

/**/