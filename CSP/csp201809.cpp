/*
	��Ŀ��ţ�201809-1
	��Ŀ���ƣ�����

	��ɣ�
		��һ��������n�����˵��̵꣬��1��n��˳���ų�һ�ţ���Щ�̵궼��һ����
	�ˡ���һ�죬ÿ���̵궼�Լ�����һ���۸񡣵�����ϣ���Լ��Ĳ˼ۺ������̵��
	һ�£��ڶ��죬ÿһ���̵궼��������Լ��������̵�ļ۸�����Լ��ļ۸񡣾�
	��ģ�ÿ���̵궼�Ὣ�ڶ���Ĳ˼�����Ϊ�Լ��������̵��һ��˼۵�ƽ��ֵ
	����ȥβ��ȡ������ע�⣬���Ϊ1���̵�ֻ��һ�����ڵ��̵�2�����Ϊn���̵�ֻ
	��һ�����ڵ��̵�n-1���������Ϊi���̵����������ڵ��̵�i-1��i+1��������һ
	������̵�Ĳ˼ۣ������ڶ���ÿ���̵�Ĳ˼ۡ�

	���룺
		����ĵ�һ�а���һ������n����ʾ�̵���������ڶ��а���n�����������α�ʾ
	ÿ���̵��һ��Ĳ˼ۡ�
	�����
		���һ�У�����n�������������α�ʾÿ���̵�ڶ���Ĳ˼ۡ�
*/
/*
#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int* input = new int[n];
	for (int i = 0; i < n; i++)
		cin >> input[i];
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			cout << (input[0] + input[1]) / 2 << ' ';
		else if (i == n - 1)
			cout << (input[i] + input[i - 1]) / 2;
		else
			cout << (input[i - 1] + input[i] + input[i + 1]) / 3 << ' ';
	}

	delete[] input;
	return 0;
}


/*
	��Ŀ��ţ�201809-2
	��Ŀ���ƣ����

	��ɣ�
		СH��СW������һ�����ϣ����˷ֿ���ˣ�������˵Ĺ��̿�������Ϊ��ȥ������
	һЩ��Ȼ��ȥ�Աߵ�һ���㳡�Ѳ�װ�ϳ������˶�Ҫ��n�ֲˣ�����Ҳ��Ҫװn�γ�����
	��ģ�����СH��˵��n�����ཻ��ʱ���[a1,b1],[a2,b2]��[an,bn]��װ��������СW
	��˵��n�����ཻ��ʱ���[c1,d1],[c2,d2]��[cn,dn]��װ�������У�һ��ʱ���[s, t]
	��ʾ���Ǵ�ʱ��s��ʱ��t���ʱ�䣬ʱ��Ϊt-s��
		���������Ǻ����ѣ����Ƕ��ڹ㳡��װ����ʱ������죬������֪�����ǿ����Ķ�
	��ʱ�䡣

	���룺
		����ĵ�һ�а���һ��������n����ʾʱ��ε�������������n��ÿ��������ai��bi��
	����СH�ĸ���װ����ʱ��Ρ�������n��ÿ��������ci��di������СW�ĸ���װ����ʱ
	��Ρ�
	�����
		���һ�У�һ������������ʾ���˿����Ķ೤ʱ�䡣

*/
/*
//��һ��ʱ�临�Ӷ�O(n^2)
//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	int** h = new int *[n];
//	int i;
//	for (i = 0; i < n; i++)
//		h[i] = new int[2];
//	for (i = 0; i < n; i++)
//	{
//		cin >> h[i][0] >> h[i][1];
//	}
//	long long opt = 0;
//	for (int j = 0; j < n; j++)
//	{
//		int w1, w2;
//		cin >> w1 >> w2;
//		int min, max;
//		for (i = 0; i < n; i++)
//		{
//			if (h[i][0] >= w2 || h[i][1] <= w1)
//				continue;
//			min = (w1 >= h[i][0]) ? w1 : h[i][0];
//			max = (w2 <= h[i][1]) ? w2 : h[i][1];
//			opt += (long long)(max - min);
//		}
//
//	}
//	cout << opt;
//	for (i = 0; i < n; i++)
//		delete[] h[i];
//	delete[] h;
//	return 0;
//}

	//�״��㣺����ؼ�����СH��СW�����ݶβ���һһ��Ӧ��������Ҫ����ѭ�����б���


//������ʱ�临�Ӷ�O(n)
#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int** h = new int* [n];
	int** w = new int* [n];
	int i, j;
	for (i = 0; i < n; i++)
	{
		h[i] = new int[2];
		w[i] = new int[2];
	}
	for (i = 0; i < n; i++)
	{
		cin >> h[i][0] >> h[i][1];
	}
	long long opt = 0;
	for (j = 0; j < n; j++)
		cin >> w[j][0] >> w[j][1];

	i = 0, j = 0;
	while (i < n && j < n)	//i��h������j��w����
	{
		int max, min;
		if (w[j][1] <= h[i][0])
		{	//�޽�������wʱ��ƫ���ȡ��һ��w����
			j++;
			continue;
		}
		else if (w[j][0] >= h[i][1])
		{	//�޽�������hʱ��ƫ���ȡ��һ��h����
			i++;
			continue;
		}
		//���¾�Ϊ�н������
		//h����ʱ����ʱ��ȡ��һ��w���ݣ�w����ʱ����ʱ��ȡ��һ��h����
		//maxȡh��w����ʱ��С�ߣ�minȡh��w��ʼʱ�����
		//ע��min�ļ���������i��j����ǰ����������
		else if (w[j][1] < h[i][1])
		{
			max = w[j][1];
			min = ((w[j][0] >= h[i][0]) ? w[j][0] : h[i][0]);
			j++;
		}
		else if (w[j][1] >= h[i][1])
		{
			max = h[i][1];
			min = ((w[j][0] >= h[i][0]) ? w[j][0] : h[i][0]);
			i++;
		}
		opt += (long long)max - min;
	}
	cout << opt;
	for (i = 0; i < n; i++)
	{
		delete[] h[i], w[i];
	}
	delete[] h, w;
	return 0;
}



/*
	��Ŀ���: 201809-3
	��Ŀ����: Ԫ��ѡ����
*/


#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

struct Edge {
	int parent, child;
	int nex;
};

struct Vertex {
	int toHead;
	string label;
	string id;
};

Edge edges[1500];
Vertex vers[150];
int eIdx, vIdx;

void addVer(const string& lable, const string& id) {
	vers[++vIdx].label = lable;
	vers[vIdx].id = id;
}

void addEdge(int parent, int child) {
	edges[++eIdx].parent = parent;
	edges[eIdx].child = child;
	edges[eIdx].nex = vers[parent].toHead;
	vers[parent].toHead = eIdx;
}

int getLevel(string& str) {
	int level = str.find_first_not_of('.') / 2;
	str.erase(0, level);
	return level;
}

string getLabel(string& str) {
	auto t = str.find_first_of(' ');

}

int main() {
	int n, m;
	cin >> n >> m;
	string str;
	vector<int> levelArr;
	for (int i = 0; i < n; ++i) {
		getline(cin, str);
		int level = getLevel(str);
		
		if(level+1>levelArr.size()) levelArr.push_back()
	}
}

/**/