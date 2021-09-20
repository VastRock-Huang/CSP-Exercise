
/*
	题目编号: 202012-1
	题目名称: 期末预测之安全指数

	题目
	期末要到了，小菜同学找到了自己的好朋友顿顿，希望可以预测一下自己这学期是否会挂科。
	首先，顿顿选取了如“课堂表现”、“自习时长”、“作业得分”、“社团活动参与度”等 n 项指
	标作为预测的依据。
	然后，顿顿根据自己平日里对小菜的暗中观察，以百分制给每一项指标打分，即小菜同学第 i
	（1<=i<=n）项指标的得分 score_i 是一个 |0,100| 范围内的整数。
	鉴于每一项指标的重要性不尽相同，顿顿用一个 |-10,10| 范围内的整数来表示第 i
	（1<=i<=n）项指标的重要程度。
	最后，小菜同学期末的安全指数 y 定义如下：
					y=ReLU(\sum_{i=1}^n (score_i * w_i))

	其中 ReLU(x)=max(0,x) 是一种常见的激活函数。
	因为使用了 ReLU 函数，安全指数一定是个非负值。
	如果安全指数过低（甚至为零），则说明小菜同学这学期很可能要挂科了……

	已知每一项指标的重要程度 w_i 和相应的得分 score_i，快来算算小菜同学期末的安全指数吧。

	输入
	从标准输入读入数据。
	输入的第一行包含一个正整数 n，保证 2<=n<=10^5。
	接下来输入 n 行，其中第 i（1<=i<=n）行包含用空格分隔的两个整数 w_i 和 score_i，
	分别表示第 i 项指标的重要程度和小菜同学该项的得分。

	输出
	输出到标准输出。
	输出一个非负整数 y，表示小菜同学期末的安全指数。
*/
/*
#include <cstdio>
#include <iostream>
using namespace std;

int ReLU(int x) {
	return max(0, x);
}

int main() {
	int n;
	scanf("%d", &n);
	int w, score, sum = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &w, &score);
		sum += w * score;
	}
	printf("%d\n",ReLU(sum));
	return 0;
}


/*
	题目编号: 202012-2
	题目名称: 期末预测之最佳阈值
*/
/*
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 100005;

struct Pair {
	int y;
	int result;
	bool operator<(const Pair& x) const {
		return y < x.y;
	}
};

Pair ipt[MAX];

int main() {
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &ipt[i].y, &ipt[i].result);
	}

	sort(ipt, ipt + m);


	int curTh = ipt[0].y;	//当前θ
	int sum = 0;	// 预测成功数
	// 计算θ=ipt[0].y的时候的sum
	for (int i = m - 1; i >= 0; --i) {
		sum += (ipt[i].result == 1);
	}
	// 初始化0*为ipt[0].y
	int res = ipt[0].y;
	int maxSum = sum;
	for (int i = 0; true;) {
		// 向后扫描直到遇到下个θ
		while (i < m && ipt[i].y == curTh) {
			if (ipt[i].result) {
				--sum;
			}
			else {
				++sum;
			}
			++i;
		}
		// 到结束则退出
		if (i == m) break;
		// 更新当前θ
		curTh = ipt[i].y;
		// 若预测数更多则更新结果
		if (maxSum <= sum) {
			maxSum = sum;
			res = curTh;
		}
	}
	printf("%d\n", res);
	return 0;
}


/*
	题目编号: 202012-3
	题目名称: 带配额的文件系统
*/

/* 20 分 */
/*
#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <string>
#include <cstring>

using namespace std;

enum class FileType {
	FILE,
	DIR
};

// 文档结点
struct Node {
	FileType type;
	char name[100];
	int fileSize;
	unordered_map<string, Node*>* sub;
	long long LD, LR;
	long long useLD, useLR;
	// 目录结点
	Node(const char* na) {
		type = FileType::DIR;
		strcpy(name, na);
		LD = LR = useLD = useLR = 0;
		fileSize = 0;
		sub = new unordered_map<string, Node*>();
	}
	// 文件结点
	Node(const char* na, int fileSz) {
		type = FileType::FILE;
		strcpy(name, na);
		fileSize = fileSz;
		LD = LR = useLD = useLR = 0;
		sub = nullptr;
	}
	~Node() {
		delete sub;
	}
};


int n;
char inst;
char path[105];
char* pathArr[25];	// 分割后的路径
int pathArrSz;	// 路径长度
int fileSize;
int LD, LR;
Node root = Node("/");	// 根目录


// 分割路径, 返回分割数组的长度
int getFileSplit(char* path, char** pathArr) {
	if (path[1] == 0) return 0;
	int idx = 0;
	int pre = 1;
	for (int i = 1; path[i]; ++i) {
		if (path[i] == '/') {
			path[i] = 0;
			pathArr[idx++] = &path[pre];
			pre = i + 1;
		}
	}
	pathArr[idx++] = &path[pre];
	return idx;
}

// 判断dad目录下有无和name相同的文档
Node* checkSame(Node* dad, const char* name) {
	auto it = dad->sub->find(string(name));
	if (it == dad->sub->end()) {
		return nullptr;
	}
	return it->second;
}

// 创建结点, delta是空间占用的增量
bool create(Node* dad, int i, int delta) {
	//printf("de %s uLD:%d, uLR:%d, LD:%d, LR:%d delta:%d\n", dad->name,
	//	dad->useLD, dad->useLR, dad->LD,dad->LR,delta);
	// 若父目录后代配额不满足则返回失败
	if (dad->LR && dad->LR - dad->useLR < delta) {
		return false;
	}
	// 最后一级的文件路径
	if (i == pathArrSz - 1) {
		// 若父目录的目录配额不满足
		if (dad->LD && dad->LD - dad->useLD < delta) {
			return false;
		}
		// 判断有无相同文件
		Node* dest = checkSame(dad, pathArr[i]);
		// 路径名存在且不为文件返回失败
		if (dest) {
			if (dest->type != FileType::FILE) {
				return false;
			}
			delete dad->sub->at(pathArr[i]);
		}
		// 文件不存在或者存在同名文件
		dad->sub->emplace(pathArr[i], new Node(pathArr[i], fileSize));
		// 更新使用的配额
		dad->useLD += delta;
		dad->useLR += delta;
		return true;
	}

	// 若非最后一级路径
	Node* dest = checkSame(dad, pathArr[i]);
	// 若路径名存在
	if (dest) {
		// 若目标路径为目录且创建子文件成功
		if (dest->type == FileType::DIR && create(dest, i + 1, delta)) {
			dad->useLR += delta;
			return true;
		}
		// 若目标路径是子文件或创建失败
		return false;
	}

	// 若路径名不存在则创建
	dest = new Node(pathArr[i]);
	dad->sub->emplace(pathArr[i], dest);
	// 创建子路径
	if (create(dest, i + 1, delta)) {
		dad->useLR += delta;
		//printf("de %s uLD:%d, uLR:%d,delta:%d\n", dad->name,
		//	dad->useLD, dad->useLR, delta);
		return true;
	}
	return false;
}

// 删除文件, 返回需要增加的后代配额LR
int remove(Node* dad, int i) {
	int ret = 0;
	Node* dest;
	// 若为最后一级路径
	if (i == pathArrSz - 1) {
		dest = checkSame(dad, pathArr[i]);
		if (dest) {
			// 若为目录
			if (dest->type == FileType::DIR) {
				// 后代配额为返回值
				ret = dest->useLR;
			}
			else { // 若为文件
				// 返回值为文件大小
				ret = dest->fileSize;
				// 修改父目录使用的目录配额LD
				dad->useLD -= ret;
			}
			// 删除结点
			dad->sub->erase(pathArr[i]);
		}
	}
	else {	// 不为最后一级路径
		dest = checkSame(dad, pathArr[i]);
		// 若路径存在且为目录则递归
		if (dest && dest->type == FileType::DIR) {
			ret = remove(dest, i + 1);
		}
	}
	// 更新父目录使用LR配额
	dad->useLR -= ret;
	//printf("de %s uld:%d, ulr:%d, ld:%d, lr:%d\n", dad->name,
	//	dad->useLD, dad->useLR, dad->LD, dad->LR);
	return ret;
}

// 设置配额
bool query(Node* dad, int i) {
	//printf("de %s uld:%d, ulr:%d, ld:%d, lr:%d\n", dad->name,
	//	dad->useLD, dad->useLR, dad->LD, dad->LR);
	// 此时父结点为最后的文档
	if (i == pathArrSz) {
		// 能够设置
		if ((LD == 0 || LD >= dad->useLD)
			&& (LR == 0 || LR >= dad->useLR)) {
			dad->LD = LD, dad->LR = LR;
			return true;
		}
		return false;
	}
	// 不为最后路路径则递归
	dad = checkSame(dad, pathArr[i]);
	// 有同名子目录
	if (dad && dad->type == FileType::DIR) {
		return query(dad, i + 1);
	}
	return false;
}

// 判断整个路径下是否有该文件, 配合create用于替换文件
// 返回同名文件大小
int checkFullPath() {
	Node* dad = &root;
	for (int i = 0; i < pathArrSz - 1; ++i) {
		dad = checkSame(dad, pathArr[i]);
		if (!dad || dad->type != FileType::DIR) {
			return 0;
		}
	}
	dad = checkSame(dad, pathArr[pathArrSz - 1]);
	if (dad && dad->type == FileType::FILE) {
		return dad->fileSize;
	}
	return 0;
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		bool res;
		getchar();
		scanf("%c %s", &inst, path);
		switch (inst) {
		case 'C': {
			scanf("%d", &fileSize);
			pathArrSz = getFileSplit(path, pathArr);
			int delta = fileSize - checkFullPath();
			res = create(&root, 0, delta);
		}
				break;
		case 'R':
			pathArrSz = getFileSplit(path, pathArr);
			remove(&root, 0);
			res = true;
			break;
		case 'Q':
			scanf("%d %d", &LD, &LR);
			pathArrSz = getFileSplit(path, pathArr);
			res = query(&root, 0);
			break;
		default:
			res = false;
			break;
		}
		printf("%c\n", res ? 'Y' : 'N');
	}

	return 0;
}

/**/