/*
	题目编号：201703-1
	题目名称：分蛋糕

	题干：
		小明今天生日，他有n块蛋糕要分给朋友们吃，这n块蛋糕（编号为1到n）的重量
	分别为a1, a2, …, an。小明想分给每个朋友至少重量为k的蛋糕。小明的朋友们已
	经排好队准备领蛋糕，对于每个朋友，小明总是先将自己手中编号最小的蛋糕分给他，
	当这个朋友所分得蛋糕的重量不到k时，再继续将剩下的蛋糕中编号最小的给他，直到
	小明的蛋糕分完或者这个朋友分到的蛋糕的总重量大于等于k。 
		请问当小明的蛋糕分完时，总共有多少个朋友分到了蛋糕。

	输入：
		输入的第一行包含了两个整数n, k，意义如上所述。 
		第二行包含n个正整数，依次表示a1, a2, …, an。
	输出：
		输出一个整数，表示有多少个朋友分到了蛋糕。
*/
/*
#include<iostream>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int ipt;
	int cake = 0;
	int per = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> ipt;
		cake += ipt;
		if (cake >= k)
		{
			cake = 0;
			per++;
		}
	}
	if (cake)
		per++;

	cout << per;
	return 0;
}


/*
	题目编号：201703-2
	题目名称：学生排队

	题干：
		体育老师小明要将自己班上的学生按顺序排队。他首先让学生按学号从小到大的顺
	序排成一排，学号小的排在前面，然后进行多次调整。一次调整小明可能让一位同学出
	队，向前或者向后移动一段距离后再插入队列。 
	例如，下面给出了一组移动的例子，例子中学生的人数为8人。 
　　	0）初始队列中学生的学号依次为1, 2, 3, 4, 5, 6, 7, 8； 
　		1）第一次调整，命令为“3号同学向后移动2”，表示3号同学出队，向后移动2名同
	学的距离，再插入到队列中，新队列中学生的学号依次为1, 2, 4, 5, 3, 6, 7, 8； 
　　	2）第二次调整，命令为“8号同学向前移动3”，表示8号同学出队，向前移动3名同
	学的距离，再插入到队列中，新队列中学生的学号依次为1, 2, 4, 5, 8, 3, 6, 7； 
　　	3）第三次调整，命令为“3号同学向前移动2”，表示3号同学出队，向前移动2名同
	学的距离，再插入到队列中，新队列中学生的学号依次为1, 2, 4, 3, 5, 8, 6, 7。 
		小明记录了所有调整的过程，请问，最终从前向后所有学生的学号依次是多少？ 
		请特别注意，上述移动过程中所涉及的号码指的是学号，而不是在队伍中的位置。在
	向后移动时，移动的距离不超过对应同学后面的人数，如果向后移动的距离正好等于对应
	同学后面的人数则该同学会移动到队列的最后面。在向前移动时，移动的距离不超过对应
	同学前面的人数，如果向前移动的距离正好等于对应同学前面的人数则该同学会移动到队
	列的最前面。

	输入：
		输入的第一行包含一个整数n，表示学生的数量，学生的学号由1到n编号。 
		第二行包含一个整数m，表示调整的次数。 
		接下来m行，每行两个整数p, q，如果q为正，表示学号为p的同学向后移动q，如果q为
	负，表示学号为p的同学向前移动-q。
	输出：
		输出一行，包含n个整数，相邻两个整数之间由一个空格分隔，表示最终从前向后所有
	学生的学号。
*/
/*
//法一：使用list（双向链表）
#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	list<int> lis;
	for (int i = 0; i < n; i++)
		lis.push_back(i + 1);

	for (int i = 0; i < m; i++)
	{
		int p, q;
		cin >> p >> q;
		list<int>::iterator temp = find(lis.begin(), lis.end(), p);
		temp = lis.erase(temp);
		if (q > 0)
			for (int c = 0; c < q; c++)
				++temp;
		else
			for (int c = 0; c < -q; c++)
				--temp;
		lis.insert(temp, p);
		
	}
	for (list<int>::iterator it = lis.begin(); it != lis.end(); ++it)
		cout << *it << ' ';
	return 0;
}

//法二：使用vector
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<int> lis;
//	for (int i = 0; i < n; i++)
//		lis.push_back(i + 1);
//
//	for (int i = 0; i < m; i++)
//	{
//		int p, q;
//		cin >> p >> q;
//		vector<int>::iterator temp = find(lis.begin(), lis.end(), p);
//		temp = lis.erase(temp);
//		lis.insert(temp + q, p);
//	}
//	for (vector<int>::iterator it = lis.begin(); it != lis.end(); ++it)
//		cout << *it << ' ';
//	return 0;
//}

	//易错点：find()函数在<algorithm>库中

	//注：	使用list与vector区别：vector类似于动态数组，能随机访问（即可以temp+q），而
	//list为双向链表，只支持顺序访问，因此只能逐次找到待访问的元素
	//整体上，list在插删时更快而查找速率较慢，而vector插入删除会有内存拷贝速度较慢
	//此题，理论上法一list速度更快
	//erase()方法返回删除元素下一个元素的迭代器

/**/