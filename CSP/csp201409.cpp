/*
	��Ŀ��ţ�201409-1
	��Ŀ���ƣ���������

	��ɣ�
		����n����ͬ������������Щ�����ж��ٶ����������ǵ�ֵ�������1��

	���룺
		����ĵ�һ�а���һ������n����ʾ���������ĸ����� 
		�ڶ��а�����������n��������
	�����
		���һ����������ʾֵ�������1�����Եĸ�����
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
	��Ŀ��ţ�201409-2
	��Ŀ���ƣ���ͼ

	��ɣ�
		��һ��������ֱ������ϵ��ֽ�ϣ���һ��(x1,y1)��(x2,y2)�ľ���ָ�������귶
	Χ��x1��x2�������귶Χ��y1��y2֮�������Ϳ����ɫ�� 
		��ͼ������һ�������������ε����ӡ���һ��������(1,1) ��(4, 4)������ɫ��
	��ɫ��ʾ���ڶ���������(2, 3)��(6, 5)������ɫ����ɫ��ʾ��ͼ�У�һ����15����
	λ�������Ϳ����ɫ��������ɫ���ֱ�Ϳ�����Σ����ڼ������ʱֻ����һ�Ρ���ʵ
	�ʵ�Ϳɫ�����У����еľ��ζ�Ϳ��ͳһ����ɫ��ͼ����ʾ��ͬ��ɫ��Ϊ˵�����㡣 

	���룺
		����ĵ�һ�а���һ������n����ʾҪ���ľ��εĸ����� 
		������n�У�ÿ��4���Ǹ��������ֱ��ʾҪ���ľ��ε����½ǵĺ������������꣬
	�Լ����Ͻǵĺ������������ꡣ

	�����
		���һ����������ʾ�ж��ٸ���λ�������Ϳ����ɫ��
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

//������ʹ��set��pair��������ȷ�һ�������������ʱ��Ϳռ䶼��ǰ�߲�
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