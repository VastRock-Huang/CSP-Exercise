
/*
	��Ŀ���: 202009-1
	��Ŀ����: �Ƽ����ѯ

	��Ŀ
	2020 �� 6 �� 8 �գ�����Ժ�������ػ��Ʒ��������ڼӿ��ƽ��¹ڲ����������ʵʩ�������
	����ԡ����нӴ��ߡ��Ȱ����ص���Ⱥ��Ӧ�쾡�족��������Ⱥ��Ը�쾡�족��
	ĳ������n��������㣬��Ŵ�1��n������i�ż����λ�ÿ��Ա�ʾΪһ��ƽ����������
	(x_i, y_i)��
	Ϊ����ԤԼ�����⣬�������������λ��(X, Y)����ѯ����������������㡣
	������������ͬʱ����Ž�С����Ϊ������

	����
	���빲n+1�С�
	��һ�а����ÿո�ָ�����������n��X��Y����ʾ������������������λ�á�
	�ڶ��е���n+1����������n����������ꡣ��i+1�У�1��i��n�������ÿո�ָ�����������
	xi��yi����ʾi�ż�������λ�á�

	���
	��������У�������ӽ���Զ��������������������������������š�
*/
/*
#include <cstdio>
#include <algorithm>
using namespace std;

struct Pos {
	int dist2, idx;
	bool operator<(const Pos& x) const {
		if (dist2 != x.dist2) return dist2 < x.dist2;
		return idx < x.idx;
	}
};

Pos p[205];

inline int getDist2(int x, int y, int x0, int y0) {
	return (x - x0) * (x - x0) + (y - y0) * (y - y0);
}

int main() {
	int n, X, Y;
	scanf("%d%d%d", &n, &X, &Y);
	int x, y;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x, &y);
		p[i].dist2 = getDist2(x, y, X, Y);
		p[i].idx = i + 1;
	}
	sort(p, p + n);
	for (int i = 0; i < 3; ++i) printf("%d\n", p[i].idx);
	return 0;
}


/*
	��Ŀ���: 202009-2
	��Ŀ����: ������Ⱥɸ��

	��Ŀ
	ĳ�����鱬���󣬳��ڡ�Ӧ�쾡�족��ԭ��������Ҫ֪ͨ���н��ھ����ø�Σ����ľ���
	��������⡣
	��Ҫ�ҳ�������Σ����ľ��񣬷���λ�ü�¼��һ�ּ���Ч�ķ�����
	������˵��һλ�����λ�ü�¼����t��ƽ������(x1, y1)��(x2, y2)������(xt, yt)��
	����(xi, yi)��ʾ�þ���iʱ������λ��.
	��Σ��������Գ���Ϊһ���������򣨺��߽磩�����½Ǻ����Ͻǵ�����ֱ�Ϊ(x_l, y_d)
	��(x_r, y_u)������x_l<x_r��y_d<y_u��
	����ĳλ�����λ�ü�¼���������ĳ������λ�ھ����ڣ����߽磩����˵���þ��񾭹���Σ
	���򣻽�һ���أ������������k������������λ�ھ����ڣ����߽磩������Ϊ�þ�������
	��Σ����������Ҫע����ǣ��ж������Ͷ���ʱ����ֻ����λ�ü�¼�е�t�����꣬�����迼
	�Ǹþ�����i��i+1ʱ��֮��λ�ںδ���
	������Σ����ķ�Χ��nλ�����ȥt��ʱ�̵�λ�ü�¼����ͳ�����о�����Σ�������������
	�ڸ�Σ��������������

	����
	���빲n+1�С�
	��һ�а����ÿո�ָ����߸�����n��k��t��x_l��y_d��x_r��y_u������������������
	������n�У�ÿ�а����ÿո�ָ���2t����������˳���ʾһλ�����ȥt��ʱ�̵�λ�ü�¼
	(x_1, y_1), (x_2, y_2), �� , (x_t, y_t)��

	���
	��������У�ÿ��һ���������ֱ��ʾ������Σ��������������ڸ�Σ��������������
*/
/*
#include <cstdio>
using namespace std;

int xl, yd, xr, yu;

inline bool inArea(int x, int y) {
	if (x >= xl && x <= xr && y >= yd && y <= yu) return true;
	return false;
}


int main() {
	int n, k, t;
	scanf("%d%d%d%d%d%d%d", &n, &k, &t, &xl, &yd, &xr, &yu);
	int s1 = 0, s2 = 0;
	int x, y;
	for (int i = 0; i < n; ++i) {
		bool f1 = false, f2 = false;
		int cnt = 0;
		for (int j = 0; j < t; ++j) {
			scanf("%d%d", &x, &y);
			if(f2) continue;
			if (inArea(x, y)) {
				f1 = true;
				++cnt;
				if (cnt >= k) f2 = true;
			}
			else cnt = 0;
		}
		if (f1) ++s1;
		if (f2) ++s2;
	}
	printf("%d\n%d", s1, s2);

	return 0;
}


/*
	��Ŀ���: 202009-3
	��Ŀ����: ������������

	���:
	������ѧ�ļ����ϵ����һ�������߼���·�Σ���һ��ʵ�����������������������Ҫ��
	��������߼�Ԫ����װ��ʵ�ʿ��õĵ�·��ʱ���Ѿ�����ҹ�ˣ�����ʵ���������������
	�����Ѿ���װ�˺ü��飬С��ͬѧȴ����û�������ĵ�·�������������ܰ�����ģ�����
	·�Ĺ��ܣ��ɹ�������������������

	�����У�����Ҫʵ��һ���򵥵������߼���·ģ������������Ѿ����˴˷���Ļ���������
	ֱ���������ڡ����Ķ�ʱ��Ҳ���Բ���ǰ����������ͼʾ�ͽ��ͣ�������������õ������
	���߼���·�Ĺ���ԭ��
	�����߼���·���������������źţ�Ҳ���Ƕ������źţ��ĵ�·��һ����˵�������߼���·��
	�Է�Ϊ�����࣬������߼���combinational logic����·��ʱ���߼���sequential 
	logic����·���ڱ����У����ǽ���ע����߼���·�����ֵ�·�����߼��ţ�logical gate��
	���ɡ�һ���߼��ſ������Ϊһ�������뵥����ĺ������������������һ���źţ����󾭹�
	һ�����߼��������һ���źš��������߼��Ű����루AND������OR�����ǣ�NOT����
	���XOR���ȣ������������еİ�λ�����Ƕ�Ӧ�ġ�
	��һϵ�е��߼����������������ܹ��ɾ����ض����ܵĵ�·�����Ĺ��ܿ��ܼܺ򵥣���һλ����
	�Ƽӷ�ֻ��Ҫһ������ţ���Ҳ���ܼ��临�ӣ�������������۸��ӳ̶ȣ������·���ص��ǣ�
	����ά���κε�״̬���κ�ʱ�����ֻ�������йأ�������仯����ʵ�����е��߼�����������
	����ɵ����ƣ������źŴ�����ʱ��Ϊ�˼����������������ģ�������߼���·��������
	ʱ��һ������仯��������̸��ű仯��
	���ǵ�����߼���·����һ���ԣ����ʱ����������ϻ�·��combinational loop���Ĵ�
	�ڣ���ĳ�߼��ŵ����뾭����һϵ������֮���ֱ����ӵ����Լ�������ˡ���ʵ�����У�����
	���������µ�·��ò��ȶ���������Ԫ��������ˣ���Ҳ��Ҫ̽����ܵĻ�·����Ҫע�⣬
	��·�Ĵ��������߼��ŵľ��幦��û���κι�ϵ��ֻҪ���ӹ�ϵ�ϴ��ڻ�·����·���޷�����
	������

	����:
	�������ݰ������ɸ����������⣬��һ��һ������ Q������ 1<=Q<=Q_max ����������������
	Q����������룬����Ҫ��ÿ��������д������Ұ���˳�������Ӧ�Ĵ𰸡�
	ÿһ��������������߼��Ͽɷ�Ϊ�����֡���һ���ֶ�����������·�Ľṹ���ڶ����ֶ�����
	����������Ҫ��ʵ����������֮��û�зָ���˳����뼴�ɡ�
	��һ����
	��һ���������ո�ָ������� M, N���ֱ��ʾ��������·�����������������������
	1<=N<=N_max ���� 0<=M<=k_max*N������ k_max �� N_max ��������Ե����й�
	�Ĳ�����
	������ N �У�ÿ������һ����������Ŵ� 1 ��ʼ��������ʽ���£�
	FUNC k L_1 L_2 ... L_k
	���� FUNC ���������߼����ܣ�k ��ʾ�����������������Ÿ������� k ����������� L��
	��ʽ�����¶���֮һ��
	I_m����ʾ�� m �������ź����ӵ�������ˣ���֤ 1<=m<=M_i��
	O_n����ʾ�� n ��������������ӵ�������ˣ���֤ 1<=n<=N��
	���п��ܵ� FUNC �������������������±�������
	FUNC	������������	�����������	��������
	NOT		1			1			��
	AND		2			k_max		��
	OR		2			k_max		��
	XOR		2			k_max		���
	NAND	2			k_max		��ǣ���ȫ�����ȡ�ǣ�
	NOR		2			k_max		��ǣ���ȫ�����ȡ�ǣ�
	���е�������ֻ��һ����������������źſ��Ա�����������������롣
	�ڶ�����
	��һ����һ������ S����ʾ�˵�·��Ҫ���� S �Ρ�ÿ�����У��������һ�����룬
	����鲿������������Ƿ���ȷ�� ���� 1<=S<=S_max������ S_max ��һ������Ե���
	�йصĲ�����
	�������� S ��Ϊ����������ÿһ�еĸ�ʽ���£�
	I_1 I_2 ... I_M
	ÿ���� M ������Ϊ 0 �� 1 �����֣���ʾ���������źţ���������У���״̬��
	�������� S ��Ϊ���������ÿһ�еĸ�ʽ���£�
	s_i O_1 O_2 ... O_s
	��һ������ 1<=s_i<=N(1<=i<=S) ��ʾ��Ҫ������ź����������湲�� s_i ���� 1 ��
	N ֮������֣���ʾ�ڶ�Ӧ�������£�����߼���ɼ������Ҫ��������������š�
	ע�� O ���в�һ���ǵ����ģ���Ҫ���������������������˳����֡�

	���:
	���������е� Q �����⣬����Ҫ��������˳�����ÿһ������Ĵ𰸣�
	������⵽��·�д�����ϻ�·���������һ�У������� LOOP��������������κ����ݡ�
	�����·��������������������� S �У�ÿһ�а��� s_i ���ÿո�ָ������֣�����Ϊ 0
	�� 1�������α�ʾ�������������Ҫ��ĸ�����������������
*/
/*
	�״��:
	1.���ڵ�·���valֵ����ʼֵ���ܳ�ʼ��Ϊ0, ����Ҫѡȡ�ܹ�����ý���valֵ��Ϊ
	��ʼֵ --276/277��
	2.ÿ�������ipt���������Ϊk*N_max=2500����, ����Ҫ���� --225��
/
/*
#include <cstdio>
#include <cstring>
using namespace std;

struct Edge {
	int src, dest;
	int toNex, fromNex;
};

struct Vertex {
	int L;
	int val;
	int sCnt = 0;
	int toHead = 0;
	int fromHead = 0;
	bool vis = false;
};

Edge edges[4005];
Vertex vers[4000];
int eIdx, vIdx;
int ipt[10005][2505];

//��ӽ��
inline void addVer(const char* str) {
	if (strcmp(str, "NOT") == 0) vers[++vIdx].L = 1;
	else if (strcmp(str, "AND") == 0) vers[++vIdx].L = 2;
	else if (strcmp(str, "OR") == 0) vers[++vIdx].L = 3;
	else if (strcmp(str, "XOR") == 0) vers[++vIdx].L = 4;
	else if (strcmp(str, "NAND") == 0) vers[++vIdx].L = 5;
	else if (strcmp(str, "NOR") == 0) vers[++vIdx].L = 6;
	else vers[++vIdx].L = 0;
}

//��ӱ�
inline void addEdge(int dest, char c, int src, int iptCnt) {
	int base = c == 'I' ? 0 : iptCnt;
	edges[++eIdx].dest = iptCnt + dest;
	edges[eIdx].src = base + src;
	//��¼ͬһԴ��
	edges[eIdx].toNex = vers[src + base].toHead;
	vers[src + base].toHead = eIdx;
	//��¼ͬһ�յ�
	edges[eIdx].fromNex = vers[dest + iptCnt].fromHead;
	vers[dest + iptCnt].fromHead = eIdx;
	++vers[dest + iptCnt].sCnt;
}

//�ж��Ƿ��л�
bool isLoop() {
	int cover = 0;
	while (cover < vIdx) {
		int i;
		for (i = 1; i <= vIdx; ++i) {
			if (!vers[i].vis && vers[i].sCnt == 0) {
				++cover;
				vers[i].vis = true;
				for (int j = vers[i].toHead; j != 0; j = edges[j].toNex) {
					int dest = edges[j].dest;
					--vers[dest].sCnt;
				}
				break;
			}
		}
		if (i > vIdx) return true;
	}
	return false;
}

//��ȡ���ֵ
int getVal(int v) {
	//�Ѿ������ֱ�ӷ���
	if (vers[v].val != -1) return vers[v].val;
	int i = vers[v].fromHead;
	vers[v].val = getVal(edges[i].src);

	if (vers[v].L == 1)
		vers[v].val = !vers[v].val;
	else if (vers[v].L == 2) {
		for (i = edges[i].fromNex; i != 0; i = edges[i].fromNex) {
			vers[v].val &= getVal(edges[i].src);
		}
	}
	else if (vers[v].L == 3) {
		for (i = edges[i].fromNex; i != 0; i = edges[i].fromNex) {
			vers[v].val |= getVal(edges[i].src);
		}
	}
	else if (vers[v].L == 4) {
		for (i = edges[i].fromNex; i != 0; i = edges[i].fromNex) {
			vers[v].val ^= getVal(edges[i].src);
		}
	}
	else if (vers[v].L == 5) {
		for (i = edges[i].fromNex; i != 0; i = edges[i].fromNex) {
			vers[v].val &= getVal(edges[i].src);
		}
		vers[v].val = !vers[v].val;
	}
	else if (vers[v].L == 6) {
		for (i = edges[i].fromNex; i != 0; i = edges[i].fromNex) {
			vers[v].val |= getVal(edges[i].src);
		}
		vers[v].val = !vers[v].val;
	}
	return vers[v].val;
}

void init() {
	vIdx = eIdx = 0;
	memset(edges, 0, sizeof(edges));
	memset(vers, 0, sizeof(vers));
}

int main() {
	int Q;
	scanf("%d", &Q);
	char L[5];

	for (int i = 0; i < Q; ++i) {
		init();
		int M, N;
		scanf("%d%d", &M, &N);
		for (int j = 1; j <= M; ++j) {
			addVer("IPT");	//���������
		}
		int sCnt, src;
		char c;
		for (int j = 1; j <= N; ++j) {
			scanf("%s %d", L, &sCnt);
			addVer(L);
			for (int k = 0; k < sCnt; ++k) {
				scanf(" %c%d", &c, &src);
				addEdge(j, c, src, M);
			}
		}
		bool loop = isLoop();
		int S;
		scanf("%d", &S);
		for (int j = 0; j < S; ++j) {
			for (int k = 1; k <= M; ++k) scanf("%d", &ipt[j][k]);
		}
		int si, opt;
		for (int j = 0; j < S; ++j) {
			for (int k = 1; k <= vIdx; ++k) 
				vers[k].val = -1;
			for (int k = 1; k <= M; ++k) {
				vers[k].val = ipt[j][k];
			}
			scanf("%d", &si);
			for (int k = 0; k < si; ++k) {
				scanf("%d", &opt);
				if (!loop) printf("%d ", getVal(opt + M));
			}
			if (!loop) putchar('\n');
		}
		if (loop) printf("LOOP\n");
	}
}


/**/