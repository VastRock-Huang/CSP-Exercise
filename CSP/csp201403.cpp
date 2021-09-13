/*
	题目编号：201403-1
	题目名称：相反数

	题干：
		有 N 个非零且各不相同的整数。请你编一个程序求出它们中有多少对相反数(a 和 -a
	为一对相反数)。

	输入：
		第一行包含一个正整数 N。(1 ≤ N ≤ 500)。 
		第二行为 N 个用单个空格隔开的非零整数,每个数的绝对值不超过1000,保证这些整数
	各不相同。
	输出：
		只输出一个整数,即这 N 个数中包含多少对相反数。

*/
/*
#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[1000] = { 0 };
	int opt = 0;
	for (int i = 0, ipt; i < n; i++)
	{
		cin >> ipt;
		ipt = (ipt > 0 ? ipt : -ipt);
		if (++a[ipt] == 2)
			opt++;
	}
	cout << opt;
	return 0;
}


/*
	题目编号：201403-2
	题目名称：窗口

	题干：
		在某图形操作系统中,有 N 个窗口,每个窗口都是一个两边与坐标轴分别平行的
	矩形区域。窗口的边界上的点也属于该窗口。窗口之间有层次的区别,在多于一个窗
	口重叠的区域里,只会显示位于顶层的窗口里的内容。 
		当你点击屏幕上一个点的时候,你就选择了处于被点击位置的最顶层窗口,并且这
	个窗口就会被移到所有窗口的最顶层,而剩余的窗口的层次顺序不变。如果你点击的
	位置不属于任何窗口,则系统会忽略你这次点击。 
		现在我们希望你写一个程序模拟点击窗口的过程。

	输入：
		输入的第一行有两个正整数,即 N 和 M。(1 ≤ N ≤ 10,1 ≤ M ≤ 10)
		接下来 N 行按照从最下层到最顶层的顺序给出 N 个窗口的位置。 每行包含四个
	非负整数 x1, y1, x2, y2,表示该窗口的一对顶点坐标分别为 (x1, y1) 和 (x2, y2)。
	保证 x1 < x2, y1 < y2。
		接下来 M 行每行包含两个非负整数 x, y,表示一次鼠标点击的坐标。
		题目中涉及到的所有点和矩形的顶点的 x, y 坐标分别不超过 2559 和 1439 。
	输出：
		输出包括 M 行,每一行表示一次鼠标点击的结果。如果该次鼠标点击选择了一个窗口,
	则输出这个窗口的编号(窗口按照输入中的顺序从 1 编号到 N);如果没有,则输出
	”IGNORED”(不含双引号)。
*/
/*
#include<iostream> 
#include<list>

using namespace std;

struct Node
{
	int num;
	int x1, y1;
	int x2, y2;
	Node(int i,int a, int b, int c, int d) :num(i), x1(a), y1(b), x2(c), y2(d) {}
};

int main()
{
	list<Node> lis;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		lis.push_front(Node(i+1, a, b, c, d));
	}
	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		list<Node>::iterator it;
		for (it = lis.begin(); it != lis.end(); ++it)
		{
			if (x >= it->x1 && x <= it->x2 && y >= it->y1 && y <= it->y2)
			{
				cout << it->num << endl;
				lis.push_front(*it);
				lis.erase(it);
				it = lis.begin();	//防止迭代器失效
				break;
			}
		}
		if (it == lis.end())
			cout << "IGNORED" << endl;
	}
	return 0;	
}

	//易错点：①正向迭代器iterator只能和begin(),end()搭配；反向迭代器reverse_iterator
	//只能和rbegin()，rend()搭配。而且成员函数erase()的参数不能为反向迭代器
	//②成员函数erase(it)之后迭代器it失效，若后续对该迭代器仍有操作，则必须在
	//erase()之后对迭代器it赋值。如上，在for-it循环后要判断迭代器it是否到达结尾，要保
	//证it不失效，因此it=lis.begin(),之所以不使用it=lis.erase(it)，是因为后文要判断it
	//和lis.end()是否相等，若使用上述语句可能会在重新赋值时恰好把lis.end()赋值给it

/**/