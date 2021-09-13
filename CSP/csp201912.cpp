
/*
	�����ţ�201912-1
	�������ƣ�����

	��Ŀ������
		���ұ���������һ����������Ϸ����ʱ�䡣��Ϸ����Ϊ�ĸ��˴�1��ʼ
	�������б������������Ҫ����������7�ı�����������7��ֱ��������
	������Լ�������ܹ�������n�����󣨲����뱻������������Ϸ������������Ҫ��
	����æͳ�ƣ���Ϸ������ÿ���˸��������˼��Ρ�

	�����ʽ��
		�ӱ�׼����������ݡ�
		�����һ�У�����һ��������n����ʾ�����˶��ٸ�������Ϸ������
	�����ʽ��
		�������׼�����
		��������У�ÿ��һ�����������α�ʾ���ұ�����������Ϸ�����������Ĵ�����
*/

/*
#include<iostream>

using namespace std;

int jumpCall(int call)
{
	if (call % 7 == 0)
		return 1;
	do
	{
		if (call % 10 == 7)
			return 1;
		call /= 10;
	} while (call);
	return 0;
}

int main()
{
	int n;
	cin >> n;
	int i, turn, call;
	int per[4] = { 0 };
	for (i = 1,call=1,turn=0; i <= n; call++)
	{

		if (jumpCall(call))
		{
			per[turn]++;
		}
		else
			i++;
		turn = (turn + 1) % 4;
	}
	for (i = 0; i < 4; i++)
		cout << per[i] << endl;
	return 0;
}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//int judgeI(int i)
//{
//	if (i % 7 == 0)
//		return 1;
//	do
//	{
//		if (i % 10 == 7)
//			return 1;
//		i = i / 10;
//	} while (i);
//	return 0;
//}
//
//int main()
//{
//	int n;
//	int i = 1;	//i����(������������)
//	int j = 0;	//j����������¼δ���������ĸ���
//	int turn = 0;	//��Ӧ��
//	int person[4] = { 0 };
//
//	scanf("%d", &n);
//
//	while (j<n)
//	{
//		if (judgeI(i))
//			person[turn]++;
//		else
//			j++;
//
//		i++;
//		turn = (turn + 1) % 4;
//	}
//
//	for (i = 0; i < 4; i++)
//		printf("%d\n", person[i]);
//
//	return 0;
//}


/*
	�����ţ�2019212-2
	�������ƣ�����վѡַ

	��Ŀ������
		ͨ�����˻����������Ѿ�֪����n���д����������λ�ã����е�i��1<=i<=n��
		��������Ϊ��x��y������֤���е������Ϊ������
		����ϣ�����������еĵط�����Щ����վ��������˵������һ��λ�ã�x, y��
		�Ƿ��ʺϽ�������վ��������Ҫ�������¼��㣺
			��x, y���������������꣬�Ҹô��������������������ĸ��ھ�λ�ã���
			��x, y+1������x, y-1������x+1, y���ͣ�x-1, y����������ȫ��������
			������һ���أ����ǻ��������������������ѡַ�������֣�����Ϊ����
			��4����Ȼ������ʾ�ڣ�x��1��y��1���ĸ��Խ�λ�����м�������������
			���ڣ�����ͳ��һ��ÿ�ֵ÷ֵ�ѡַ������
	
	�����ʽ��
		�ӱ�׼����������ݡ������ܹ���n+1�С�
		��1�а���һ��������n����ʾ�Ѳ����������������
		��1+i�У�1<=i<=n��������һ���ո�ָ�����������xi��yi����ʾ��i�����������ꡣ
		��֤�����n�����껥����ͬ��
	�����ʽ��
		�������׼�����
		��������У�ÿ��һ�����������α�ʾ�÷�Ϊ0��1��2��3��4�Ļ���վѡַ������
*/

/*
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//
//int main()
//{
//	int n;
//	int* x, * y;
//	int i,j;
//	int score[5] = { 0 };
//	int counti = 0;
//	int scorei = 0;
//
//	scanf("%d", &n);
//	x = (int*)malloc(sizeof(int)*n);
//	y = (int*)malloc(sizeof(int)*n);
//	for (i = 0; i < n; i++)
//		scanf("%d %d", x + i, y + i);
//
//	for (i = 0; i < n; i++)
//	{
//		counti = 0;
//		scorei = 0;
//		for (j = 0; j < n; j++)
//		{
//			if ((x[j] - x[i]) * (y[j] - y[i]) == 0 && (abs(x[j] - x[i]) == 1 || abs(y[j] - y[i]) == 1))
//				counti++;
//			if (abs(x[j] - x[i]) * abs(y[j] - y[i]) == 1)
//				scorei++;
//		}
//		if (counti == 4)
//			score[scorei]++;
//	}
//
//	for (i = 0; i < 5; i++)
//		printf("%d\n", score[i]);
//
//
//	free(x);
//	free(y);
//	return 0;
//}

#include<iostream>
#include<set>

using namespace std;

struct node
{
	int x, y;
	node(int x1,int y1):x(x1),y(y1){}
	bool operator<(const node& oth)const
	{
		if (x != oth.x)
			return x < oth.x;
		return y < oth.y;
	}
};

set<node> s;

bool findNode(int x,int y)
{
	if (s.find(node(x,y)) != s.end())
		return 1;
	return 0;
}

int main()
{
	int n;
	cin >> n;
	int opt[5] = { 0 };
	
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		s.insert(node(x, y));
	}

	for (set<node>::iterator it = s.begin(); it != s.end();it++)
	{
		int x = it->x, y = it->y;
		if (findNode(x, y + 1) && findNode(x, y - 1) && findNode(x + 1, y) && findNode(x - 1, y))
		{
			int cnt = 0;
			if (findNode(x + 1, y + 1))
				cnt++;
			if (findNode(x + 1, y - 1))
				cnt++;
			if (findNode(x - 1, y + 1))
				cnt++;
			if (findNode(x - 1, y - 1))
				cnt++;
			opt[cnt]++;
		}
	}
	for (int i = 0; i < 5; i++)
		cout << opt[i] << endl;

	return 0;
		
}

	//ע�����ַ�����һ�ֱȽϱ����ڶ���������set���ݽṹ�������˵ʱ�临�Ӷȵڶ�
	//	�����ţ���һ�ֿռ�ʹ�úʹ��볤������
	



/**/