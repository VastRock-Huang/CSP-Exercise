
/*
	��Ŀ���: 202012-1
	��Ŀ����: ��ĩԤ��֮��ȫָ��

	��Ŀ
	��ĩҪ���ˣ�С��ͬѧ�ҵ����Լ��ĺ����Ѷٶ٣�ϣ������Ԥ��һ���Լ���ѧ���Ƿ��ҿơ�
	���ȣ��ٶ�ѡȡ���硰���ñ��֡�������ϰʱ����������ҵ�÷֡��������Ż����ȡ��� n ��ָ
	����ΪԤ������ݡ�
	Ȼ�󣬶ٶٸ����Լ�ƽ�����С�˵İ��й۲죬�԰ٷ��Ƹ�ÿһ��ָ���֣���С��ͬѧ�� i
	��1<=i<=n����ָ��ĵ÷� score_i ��һ�� |0,100| ��Χ�ڵ�������
	����ÿһ��ָ�����Ҫ�Բ�����ͬ���ٶ���һ�� |-10,10| ��Χ�ڵ���������ʾ�� i
	��1<=i<=n����ָ�����Ҫ�̶ȡ�
	���С��ͬѧ��ĩ�İ�ȫָ�� y �������£�
					y=ReLU(\sum_{i=1}^n (score_i * w_i))

	���� ReLU(x)=max(0,x) ��һ�ֳ����ļ������
	��Ϊʹ���� ReLU ��������ȫָ��һ���Ǹ��Ǹ�ֵ��
	�����ȫָ�����ͣ�����Ϊ�㣩����˵��С��ͬѧ��ѧ�ںܿ���Ҫ�ҿ��ˡ���

	��֪ÿһ��ָ�����Ҫ�̶� w_i ����Ӧ�ĵ÷� score_i����������С��ͬѧ��ĩ�İ�ȫָ���ɡ�

	����
	�ӱ�׼����������ݡ�
	����ĵ�һ�а���һ�������� n����֤ 2<=n<=10^5��
	���������� n �У����е� i��1<=i<=n���а����ÿո�ָ����������� w_i �� score_i��
	�ֱ��ʾ�� i ��ָ�����Ҫ�̶Ⱥ�С��ͬѧ����ĵ÷֡�

	���
	�������׼�����
	���һ���Ǹ����� y����ʾС��ͬѧ��ĩ�İ�ȫָ����
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
	��Ŀ���: 202012-2
	��Ŀ����: ��ĩԤ��֮�����ֵ
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


	int curTh = ipt[0].y;	//��ǰ��
	int sum = 0;	// Ԥ��ɹ���
	// �����=ipt[0].y��ʱ���sum
	for (int i = m - 1; i >= 0; --i) {
		sum += (ipt[i].result == 1);
	}
	// ��ʼ��0*Ϊipt[0].y
	int res = ipt[0].y;
	int maxSum = sum;
	for (int i = 0; true;) {
		// ���ɨ��ֱ�������¸���
		while (i < m && ipt[i].y == curTh) {
			if (ipt[i].result) {
				--sum;
			}
			else {
				++sum;
			}
			++i;
		}
		// ���������˳�
		if (i == m) break;
		// ���µ�ǰ��
		curTh = ipt[i].y;
		// ��Ԥ������������½��
		if (maxSum <= sum) {
			maxSum = sum;
			res = curTh;
		}
	}
	printf("%d\n", res);
	return 0;
}


/*
	��Ŀ���: 202012-3
	��Ŀ����: �������ļ�ϵͳ
*/

/* 20 �� */
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

// �ĵ����
struct Node {
	FileType type;
	char name[100];
	int fileSize;
	unordered_map<string, Node*>* sub;
	long long LD, LR;
	long long useLD, useLR;
	// Ŀ¼���
	Node(const char* na) {
		type = FileType::DIR;
		strcpy(name, na);
		LD = LR = useLD = useLR = 0;
		fileSize = 0;
		sub = new unordered_map<string, Node*>();
	}
	// �ļ����
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
char* pathArr[25];	// �ָ���·��
int pathArrSz;	// ·������
int fileSize;
int LD, LR;
Node root = Node("/");	// ��Ŀ¼


// �ָ�·��, ���طָ�����ĳ���
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

// �ж�dadĿ¼�����޺�name��ͬ���ĵ�
Node* checkSame(Node* dad, const char* name) {
	auto it = dad->sub->find(string(name));
	if (it == dad->sub->end()) {
		return nullptr;
	}
	return it->second;
}

// �������, delta�ǿռ�ռ�õ�����
bool create(Node* dad, int i, int delta) {
	//printf("de %s uLD:%d, uLR:%d, LD:%d, LR:%d delta:%d\n", dad->name,
	//	dad->useLD, dad->useLR, dad->LD,dad->LR,delta);
	// ����Ŀ¼����������򷵻�ʧ��
	if (dad->LR && dad->LR - dad->useLR < delta) {
		return false;
	}
	// ���һ�����ļ�·��
	if (i == pathArrSz - 1) {
		// ����Ŀ¼��Ŀ¼������
		if (dad->LD && dad->LD - dad->useLD < delta) {
			return false;
		}
		// �ж�������ͬ�ļ�
		Node* dest = checkSame(dad, pathArr[i]);
		// ·���������Ҳ�Ϊ�ļ�����ʧ��
		if (dest) {
			if (dest->type != FileType::FILE) {
				return false;
			}
			delete dad->sub->at(pathArr[i]);
		}
		// �ļ������ڻ��ߴ���ͬ���ļ�
		dad->sub->emplace(pathArr[i], new Node(pathArr[i], fileSize));
		// ����ʹ�õ����
		dad->useLD += delta;
		dad->useLR += delta;
		return true;
	}

	// �������һ��·��
	Node* dest = checkSame(dad, pathArr[i]);
	// ��·��������
	if (dest) {
		// ��Ŀ��·��ΪĿ¼�Ҵ������ļ��ɹ�
		if (dest->type == FileType::DIR && create(dest, i + 1, delta)) {
			dad->useLR += delta;
			return true;
		}
		// ��Ŀ��·�������ļ��򴴽�ʧ��
		return false;
	}

	// ��·�����������򴴽�
	dest = new Node(pathArr[i]);
	dad->sub->emplace(pathArr[i], dest);
	// ������·��
	if (create(dest, i + 1, delta)) {
		dad->useLR += delta;
		//printf("de %s uLD:%d, uLR:%d,delta:%d\n", dad->name,
		//	dad->useLD, dad->useLR, delta);
		return true;
	}
	return false;
}

// ɾ���ļ�, ������Ҫ���ӵĺ�����LR
int remove(Node* dad, int i) {
	int ret = 0;
	Node* dest;
	// ��Ϊ���һ��·��
	if (i == pathArrSz - 1) {
		dest = checkSame(dad, pathArr[i]);
		if (dest) {
			// ��ΪĿ¼
			if (dest->type == FileType::DIR) {
				// ������Ϊ����ֵ
				ret = dest->useLR;
			}
			else { // ��Ϊ�ļ�
				// ����ֵΪ�ļ���С
				ret = dest->fileSize;
				// �޸ĸ�Ŀ¼ʹ�õ�Ŀ¼���LD
				dad->useLD -= ret;
			}
			// ɾ�����
			dad->sub->erase(pathArr[i]);
		}
	}
	else {	// ��Ϊ���һ��·��
		dest = checkSame(dad, pathArr[i]);
		// ��·��������ΪĿ¼��ݹ�
		if (dest && dest->type == FileType::DIR) {
			ret = remove(dest, i + 1);
		}
	}
	// ���¸�Ŀ¼ʹ��LR���
	dad->useLR -= ret;
	//printf("de %s uld:%d, ulr:%d, ld:%d, lr:%d\n", dad->name,
	//	dad->useLD, dad->useLR, dad->LD, dad->LR);
	return ret;
}

// �������
bool query(Node* dad, int i) {
	//printf("de %s uld:%d, ulr:%d, ld:%d, lr:%d\n", dad->name,
	//	dad->useLD, dad->useLR, dad->LD, dad->LR);
	// ��ʱ�����Ϊ�����ĵ�
	if (i == pathArrSz) {
		// �ܹ�����
		if ((LD == 0 || LD >= dad->useLD)
			&& (LR == 0 || LR >= dad->useLR)) {
			dad->LD = LD, dad->LR = LR;
			return true;
		}
		return false;
	}
	// ��Ϊ���··����ݹ�
	dad = checkSame(dad, pathArr[i]);
	// ��ͬ����Ŀ¼
	if (dad && dad->type == FileType::DIR) {
		return query(dad, i + 1);
	}
	return false;
}

// �ж�����·�����Ƿ��и��ļ�, ���create�����滻�ļ�
// ����ͬ���ļ���С
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