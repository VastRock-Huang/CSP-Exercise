/*
	��Ŀ��ţ�201503-1
	��Ŀ���ƣ�ͼ����ת

	��ɣ�
		��ת��ͼ����Ļ�������������������У�����Ҫ��һ��ͼ����ʱ����ת90�ȡ� 
	������е�ͼ���ʾ������һ����������ʾ��Ϊ����תһ��ͼ��ֻ��Ҫ����Ӧ�ľ�
	����ת���ɡ�

	���룺
		����ĵ�һ�а�����������n, m���ֱ��ʾͼ������������������ 
		������n��ÿ�а���m����������ʾ�����ͼ��
	�����
		���m�У�ÿ�а���n����������ʾԭʼ������ʱ����ת90�Ⱥ�ľ���
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
	��Ŀ��ţ�201503-2
	��Ŀ���ƣ���������

	��ɣ�
		����n����������ͳ�Ƴ�ÿ���������ֵĴ����������ִ����Ӷൽ�ٵ�˳�������

	���룺
		����ĵ�һ�а���һ������n����ʾ�������ֵĸ����� 
		�ڶ��а���n�����������ڵ�����֮����һ���ո�ָ�����ʾ��������������
	�����
		������У�ÿ�а��������������ֱ��ʾһ�������������������ֵĴ���������
	�ִ����ݼ���˳���������������������ֵĴ���һ���࣬�������ֵ��С�ģ�Ȼ��
	���ֵ�ϴ�ġ�
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