
/*
	题目编号: 202009-1
	题目名称: 称检测点查询

	题目
	2020 年 6 月 8 日，国务院联防联控机制发布《关于加快推进新冠病毒核酸检测的实施意见》，
	提出对“密切接触者”等八类重点人群“应检尽检”，其他人群“愿检尽检”。
	某市设有n个核酸检测点，编号从1到n，其中i号检测点的位置可以表示为一个平面整数坐标
	(x_i, y_i)。
	为方便预约核酸检测，请根据市民所在位置(X, Y)，查询距其最近的三个检测点。
	多个检测点距离相同时，编号较小的视为更近。

	输入
	输入共n+1行。
	第一行包含用空格分隔的三个整数n、X和Y，表示检测点总数和市民所在位置。
	第二行到第n+1行依次输入n个检测点的坐标。第i+1行（1≤i≤n）包含用空格分隔的两个整数
	xi和yi，表示i号检测点所在位置。

	输出
	输出共三行，按距离从近到远，依次输出距离该市民最近的三个检测点编号。
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
	题目编号: 202009-2
	题目名称: 风险人群筛查

	题目
	某地疫情爆发后，出于“应检尽检”的原则，我们想要通知所有近期经过该高危区域的居民
	参与核酸检测。
	想要找出经过高危区域的居民，分析位置记录是一种简单有效的方法。
	具体来说，一位居民的位置记录包含t个平面坐标(x1, y1)，(x2, y2)，…，(xt, yt)，
	其中(xi, yi)表示该居民i时刻所在位置.
	高危区域则可以抽象为一个矩形区域（含边界），左下角和右上角的坐标分别为(x_l, y_d)
	和(x_r, y_u)，满足x_l<x_r且y_d<y_u。
	考虑某位居民的位置记录，如果其中某个坐标位于矩形内（含边界），则说明该居民经过高危
	区域；进一步地，如果其中连续k个或更多坐标均位于矩形内（含边界），则认为该居民曾在
	高危区域逗留。需要注意的是，判定经过和逗留时我们只关心位置记录中的t个坐标，而无需考
	虑该居民在i到i+1时刻之间位于何处。
	给定高危区域的范围和n位居民过去t个时刻的位置记录，试统计其中经过高危区域的人数和曾
	在高危区域逗留的人数。

	输入
	输入共n+1行。
	第一行包含用空格分隔的七个整数n、k、t、x_l、y_d、x_r和y_u，含义如上文所述。
	接下来n行，每行包含用空格分隔的2t个整数，按顺序表示一位居民过去t个时刻的位置记录
	(x_1, y_1), (x_2, y_2), … , (x_t, y_t)。

	输出
	输出共两行，每行一个整数，分别表示经过高危区域的人数和曾在高危区域逗留的人数。
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
	题目编号: 202009-3
	题目名称: 点亮数字人生

	题干:
	土豪大学的计算机系开了一门数字逻辑电路课，第一个实验叫做“点亮数字人生”，要用
	最基础的逻辑元件组装出实际可用的电路。时间已经是深夜了，尽管实验箱上密密麻麻的
	连线已经拆装了好几遍，小君同学却依旧没能让她的电路正常工作。你能帮助她模拟出电
	路的功能，成功点亮她的数字人生吗？

	本题中，你需要实现一个简单的数字逻辑电路模拟器。如果你已经有了此方面的基础，可以
	直接跳过本节。在阅读时，也可以参照前两个样例的图示和解释，这有助于你更好地理解数
	字逻辑电路的工作原理。
	数字逻辑电路是用来传输数字信号（也就是二进制信号）的电路。一般来说，数字逻辑电路可
	以分为两大类，即组合逻辑（combinational logic）电路和时序逻辑（sequential 
	logic）电路。在本题中，我们仅关注组合逻辑电路。这种电路仅由逻辑门（logical gate）
	构成。一个逻辑门可以理解为一个多输入单输出的函数，输入端连接至少一个信号，而后经过
	一定的逻辑运算输出一个信号。常见的逻辑门包括与（AND）、或（OR）、非（NOT）、
	异或（XOR）等，均与编程语言中的按位运算是对应的。
	将一系列的逻辑门连接起来，就能构成具有特定功能的电路。它的功能可能很简单（如一位二进
	制加法只需要一个异或门），也可能极其复杂（如除法）。无论复杂程度，这类电路的特点是：
	它不维持任何的状态，任何时刻输出只与输入有关，随输入变化。真实世界中的逻辑器件由于物
	理规律的限制，存在信号传播延时。为了简单起见，本题中我们模拟的组合逻辑电路不考虑延
	时：一旦输入变化，输出立刻跟着变化。
	考虑到组合逻辑电路的这一特性，设计时不能允许组合环路（combinational loop）的存
	在，即某逻辑门的输入经过了一系列器件之后又被连接到了自己的输入端。真实世界中，这种
	做法将导致电路变得不稳定，甚至损坏元器件。因此，你也需要探测可能的环路。需要注意，
	环路的存在性与逻辑门的具体功能没有任何关系；只要连接关系上存在环路，电路就无法正常
	工作。

	输入:
	输入数据包括若干个独立的问题，第一行一个整数 Q，满足 1<=Q<=Q_max 。接下来依次是这
	Q个问题的输入，你需要对每个问题进行处理，并且按照顺序输出对应的答案。
	每一个问题的输入在逻辑上可分为两部分。第一部分定义了整个电路的结构，第二部分定义了
	输入和输出的要求。实际上两部分之间没有分隔，顺序读入即可。
	第一部分
	第一行是两个空格分隔的整数 M, N，分别表示了整个电路的输入和器件的数量，满足
	1<=N<=N_max 并且 0<=M<=k_max*N。其中 k_max 和 N_max 都是与测试点编号有关
	的参数。
	接下来 N 行，每行描述一个器件，编号从 1 开始递增，格式如下：
	FUNC k L_1 L_2 ... L_k
	其中 FUNC 代表具体的逻辑功能，k 表示输入的数量，后面跟着该器件的 k 个输入端描述 L，
	格式是以下二者之一：
	I_m：表示第 m 个输入信号连接到此输入端，保证 1<=m<=M_i；
	O_n：表示第 n 个器件的输出连接到此输入端，保证 1<=n<=N。
	所有可能的 FUNC 和允许的输入端数量如下表所述：
	FUNC	最少输入数量	最多输入数量	功能描述
	NOT		1			1			非
	AND		2			k_max		与
	OR		2			k_max		或
	XOR		2			k_max		异或
	NAND	2			k_max		与非（先全部与后取非）
	NOR		2			k_max		或非（先全部或后取非）
	所有的器件均只有一个输出，但这个输出信号可以被用作多个器件的输入。
	第二部分
	第一行是一个整数 S，表示此电路需要运行 S 次。每次运行，都会给定一组输入，
	并检查部分器件的输出是否正确。 满足 1<=S<=S_max，其中 S_max 是一个与测试点编号
	有关的参数。
	接下来的 S 行为输入描述，每一行的格式如下：
	I_1 I_2 ... I_M
	每行有 M 个可能为 0 或 1 的数字，表示各个输入信号（按编号排列）的状态。
	接下来的 S 行为输出描述，每一行的格式如下：
	s_i O_1 O_2 ... O_s
	第一个整数 1<=s_i<=N(1<=i<=S) 表示需要输出的信号数量。后面共有 s_i 个在 1 到
	N 之间的数字，表示在对应的输入下，组合逻辑完成计算后，需要输出结果的器件编号。
	注意 O 序列不一定是递增的，即要求输出的器件可能以任意顺序出现。

	输出:
	对于输入中的 Q 个问题，你需要按照输入顺序输出每一个问题的答案：
	如果你检测到电路中存在组合环路，则请输出一行，内容是 LOOP，无需输出其他任何内容。
	如果电路可以正常工作，则请输出 S 行，每一行包含 s_i 个用空格分隔的数字（可能为 0
	或 1），依次表示“输出描述”中要求的各个器件的运算结果。
*/
/*
	易错点:
	1.对于电路结点val值的起始值不能初始化为0, 而需要选取能够到达该结点的val值作为
	初始值 --276/277行
	2.每次输入端ipt的数量最多为k*N_max=2500左右, 数组要开大 --225行
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

//添加结点
inline void addVer(const char* str) {
	if (strcmp(str, "NOT") == 0) vers[++vIdx].L = 1;
	else if (strcmp(str, "AND") == 0) vers[++vIdx].L = 2;
	else if (strcmp(str, "OR") == 0) vers[++vIdx].L = 3;
	else if (strcmp(str, "XOR") == 0) vers[++vIdx].L = 4;
	else if (strcmp(str, "NAND") == 0) vers[++vIdx].L = 5;
	else if (strcmp(str, "NOR") == 0) vers[++vIdx].L = 6;
	else vers[++vIdx].L = 0;
}

//添加边
inline void addEdge(int dest, char c, int src, int iptCnt) {
	int base = c == 'I' ? 0 : iptCnt;
	edges[++eIdx].dest = iptCnt + dest;
	edges[eIdx].src = base + src;
	//记录同一源点
	edges[eIdx].toNex = vers[src + base].toHead;
	vers[src + base].toHead = eIdx;
	//记录同一终点
	edges[eIdx].fromNex = vers[dest + iptCnt].fromHead;
	vers[dest + iptCnt].fromHead = eIdx;
	++vers[dest + iptCnt].sCnt;
}

//判断是否有环
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

//获取输出值
int getVal(int v) {
	//已经算出则直接返回
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
			addVer("IPT");	//添加输入结点
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