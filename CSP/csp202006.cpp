/*
	题目编号: 202006-1
	题目名称: 线性分类器

	题目:
	考虑一个简单的二分类问题——将二维平面上的点分为A 和B 两类。
	训练数据包含 n 个点，其中第 i 个点（1 ≤ i ≤ n）可以表示为一个三元组
	(x_{i}, y_{i}, type_{i})，即该点的横坐标、纵坐标和类别。
	在二维平面上，任意一条直线可以表示为θ_{0} + θ_{1}x + θ_{2}y = 0
	的形式，即由θ_{0}、θ_{1}和 θ_{2}三个参数确定该直线，且满足θ_{1}、θ_{2}
	不同时为 0。
	基于这 n 个已知类别的点，我们想要在平面上找到一条直线作为一个线性分类器。
	具体来说，这条线要把训练数据中的A、B 两类点完. 美. 分. 隔. 开来，即一侧
	只有A 类点、另一侧只有B 类点。这样，对于任意一个的未知类别的点，我们就可以
	根据它是位于直线的哪一侧来预测它的类别了。
	在本题中我们仅需要处理 m 个如下查询：给定一条直线，判断它是否能将训练数据中
	的A、B 两类点完美分开。

	输入:
	从标准输入读入数据。
	输入共 n + m + 1 行。
	第一行包含用空格分隔的两个正整数 n 和 m，分别表示点和查询的个数。
	第二行到第 n + 1 行依次输入 n 个点的信息。第 i + 1 行（1 ≤ i ≤ n）包含用
	空格分隔的三项x_{i}、y_{i}和 type_{i}，分别表示第 i 个点的横、纵坐标和类别，
	其中坐标为整数、类别为一个大写英文字母A 或B。 
	第 n + 2 行到第 n + m + 1 行依次输入 m 个查询。
	第 j + n + 1 行（1 ≤ j ≤ m）包含用空格分隔的三个整数 θ_{0}、θ_{1}和 θ_{2}，
	表示第 j 个查询中给定直线的三个参数。

	输出
	输出到标准输出。
	输出共 m 行，每行输出一个字符串。
	第 j 行（1 ≤ j ≤ m）输出的字符串对应第 j 个查询的结果：
	如果给定直线可以完美分隔A、B 两类点，则输出Yes；否则输出No。
*/
/*  
#include <cstdio>
using namespace std;

struct Dot {
	long long x, y;
	char type;
};

Dot d[1005];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) 
		scanf("%lld %lld %c", &d[i].x, &d[i].y, &d[i].type);
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		char type = d[0].type;
		long long sd = a + b * d[0].x + c * d[0].y;
		if (sd == 0) {
			printf("No\n");
			continue;
		}
		bool yes = true;
		for (int i = 1; i < n; ++i) {
			long long v= a + b * d[i].x + c * d[i].y;
			if (d[i].type == type) {
				if (v * sd <= 0) {
					yes = false;
					break;
				}
			}
			else if (v * sd >= 0) {
				yes = false;
				break;
			}
		}
		if (yes) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}


/*
	题目编号: 202006-2
	题目名称: 稀疏向量

	题目
	对于一个 n 维整数向量 v ∈ Zn，其在第 index 个维度上的取值记作 v_index。
	这里我们约定 index 的取值从 1 开始，即 v = (v1, v2, · · · , vn)。下面介绍
	一种向量的稀疏表示方法。
	如果 v 仅在少量维度上的取值不为 0，则称其为稀疏向量。
	例如当 n = 10 时，v = (0, 0, 0, 5, 0, 0, -3, 0, 0, 1) 就是一个稀疏向量。
	由于稀疏向量的非零值较少，我们可以通过仅存储非零值的方式来节省空间。具体来说，每个
	非零值都可以用一个 (index, value) 对来表示，即该向量在第 index 个维度上的取值
	v_index = value ≠ 0。在上面的例子中，v 就可以表示为 [(4, 5), (7, -3), 
	(10, 1)]。
	接下来给出这种稀疏表示一般化的定义。
	• 对于任意一个 n 维整数向量 v ∈ Zn，如果其在且仅在 a 个维度上取值不为 0，则可以
	唯一表示为：
	[(index_1, value_1), (index_2, value_2), · · · , (index_a, value_a)] 
	• 其中所有的 index 均为整数且满足：
	1 ≤ index_1 < index_2 < · · · < index_a ≤ n
	• value_i 表示向量 v 在对应维度 index_i 上的非零值。
	给出两个 n 维整数向量 u, v ∈ Zn 的稀疏表示，试计算它们的内积。
	u · v = ∑_{i=1}^{n} u_i · v_i

	输入
	从标准输入读入数据。
	输入的第一行包含用空格分隔的三个正整数 n、a 和 b，其中 n 表示向量 u、v 的维数，
	a 和 b 分别表示两个向量所含非零值的个数。
	第二行到第 a + 1 行输入向量 u 的稀疏表示。
	第 i + 1 行（1 ≤ i ≤ a）包含用空格分隔的两个整数 index_i 和 value_i，表示
	v_index_i = value_i ≠ 0。 
	第 a + 2 行到第 a + b + 1 行输入向量 v 的稀疏表示。
	第 j + a + 1 行（1 ≤ j ≤ b）包含用空格分隔的两个整数 index_j 和 value_j，
	表示 v_index_j = value_j ≠ 0

	输出
	输出到标准输出。
	输出一个整数，表示向量 u 和 v 的内积 u · v。
*/
/*
#include <cstdio>
using namespace std;

struct Svector {
	int idx;
	long long val;
};

Svector u[500005],v[500005];

int main() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 0; i < a; ++i) scanf("%d%lld", &u[i].idx, &u[i].val);
	for (int i = 0; i < b; ++i) scanf("%d%lld", &v[i].idx, &v[i].val);

	long long s = 0;
	int i = 0, j = 0;
	while (i < a && j < b) {
		int delta = u[i].idx - v[j].idx;
		if (delta == 0) {
			s += u[i].val * v[j].val;
			++i, ++j;
		}
		else if (delta < 0) ++i;
		else ++j;
	}
	printf("%lld", s);

	return 0;
}


/*
	题目编号: 202006-3
	题目名称: Markdown渲染器

	题干:
	Markdown是一种轻量级的标记语言，它可以用较为简单的符号来标记文本中的成
	分的意义。通过套用适当的样式，即可生成一份美观的文档。Markdown 由于其轻量级
	的特性，深受喜爱，并在各种方面得到了广泛的运用。本题需要你解析并渲染简化的
	Markdown文档。
	本题中，你需要按照下述要求，在终端屏幕上渲染简单的Markdown文档。终端屏
	幕，可以被视为宽度为w单位，长度为无限长单位的方格，每个方格中可以被填充至多
	一个字符。可选地，每个方格中的字符可以带有一定的样式。在这个终端屏幕中，可以
	按照下列方法，渲染Markdown文档中的各个元素。
		段落
	在Markdown文档中，换行符将文档分为若干行。仅包含零个或多个空格的行被称
	为“空白行”。空白行将整个文档分割成了若千段落。例如，下面的示例文档中包含有5
	个空白行，行号分别是2、6、7、9、10,他们将该文档分成了3个段落。为了能够便于
	你阅读,"_"符号表示空格。“-|”符号表示换行符。
	在渲染一个段落前，应该去掉每行首尾的连续空格。如果一个段落包含有多行文本，
	那么将各个行用一个空格连接起来，形成一个不含换行符的连续的段落文本。渲染段落
	时，应当首先与之前的段落或项目列表空出一行的间距，从新的一行开始连续将段落中
	的文本从左至右渲染在屏幕上。如果段落中的字符超出了终端的宽度，那么则应当从终
	端的下一行开始继续渲染其余的文本。如果余下的文本恰好是以空格字符开头，那么应
	该将这些连续的空格字符删除。上述文本按照这样的规则，在一个宽度为10的终端中
	渲染，其结果为: 

		项目列表
	“项目”由连续的若千行文本组成，其中第一行必须以星号和空格(*_) 开头，其
	余的行(如果有)为以两个空格(__)开头的非空白行。“项目列表”由连续的一个或.
	多个项目组成，其中各个项目之间没有空白行或开头不是两个空格的行。如果两个项目
	列表之间没有空白行或开头不是两个空格的行，那么它们应当被视为一个项目列表。例
	如，下列文本中，行1、行3-5、行6-7、行9和行10组成了5个项目，它们分别属于
	3个项目列表，因为它们被空行(行3)、段落(行8)分隔开来。
	在渲染一个个项目列表时，应当首先与之前的段落或项目列表空出一行的间距，从新
	的一行开始连续渲染每个项目。在渲染一个项目前，先把这个项目的各个文本行首的
	两个空格字符或星号空格字符去掉。渲染时，从新的一行开始，输出空格、点号、空格
	(_·_)符号，然后按照渲染一个段落的规则，渲染该项目中的各个文本行。但是，在
	终端上输出一个项目的随后的行时，应当插入三个空格(___)，以使这些行与第一行对
	齐。特别地，如果一个项目的首行除行首的星号空格字符外，没有其它的字符，那么应
	当直接从项目的余下的行开始渲染该项目(例如上述文本第6行);如果仅有一行，那
	么认为这个项目渲染结束(例如.上述文本第10行)。上述文本按照该规则，在一个宽度
	为10 的终端中渲染，其结果为:

	这里，原文本第2行是空白行，将前后两个项目分成了两个项目列表，因此在输出
	终端中，二者之间有空行分隔。原文本第8行，开头不是星号和空格，因此是一个单独
	的段落。

	输入:
	从标准输入读入数据。
	输入第一行包含一个数字w，是终端宽度。随后从第二行开始，是被渲染的文本。

	输出:
	输出到标准输出。
	输出一行，是一个数字，表示渲染所需终端行数。
*/
/*
	易错点:
	1. 一个段落的多行之间/项目头和项目/项目和项目之间 在 字符未超出屏幕时要
	在之间加一个空格  --296行
	2. 无内容的项目头与下一行的项目之间不加空格 --290行 
	3. 要去掉开头的空行, 其他情况遇到空行才会将行数+2 --271行
	4. 项目头与空行/段落间要空一行, 而与另一个项目间不需空行 --278/279行
*/
/*
#include <iostream>
#include <string>
using namespace std;

enum LineType {
	BEGIN, BLANK, TXT, ITEMHEAD, ITEM
};

string str;

bool isBlank(const string& str) {
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] != ' ') return false;
	}
	return true;
}

bool isItemHead(string& str) {
	if (str.substr(0, 2) == "* ") {
		str.erase(0, 2);
		return true;
	}
	return false;
}

bool isItem(const string& str) {
	if (str.substr(0, 2) == "  ") return true;
	return false;
}

void strstrip(string& str) {
	int start = str.find_first_not_of(' ');
	str.erase(0, start);
	int end = str.find_last_not_of(' ');
	str.erase(end + 1);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int w;
	cin >> w;
	int lineNo = 0;
	int colNo = 0;
	LineType preType = BEGIN, curType;
	bool has = false;	//标志是否有渲染的文本
	getline(cin, str);
	while (getline(cin, str)) {
		//判断空行
		if (isBlank(str)) {
			preType = BLANK;
			continue;
		}
		//前一行是空行且不为开头的空行
		else if (preType == BLANK && has) {
			lineNo += 2;
			colNo = 0;
		}
		if (isItemHead(str)) {
			if (preType == ITEM || preType == ITEMHEAD) ++lineNo;
			else if (preType == TXT) lineNo += 2;
			colNo = 3;
			curType = ITEMHEAD;
		}
		else if ((preType == ITEMHEAD || preType == ITEM)
			&& isItem(str)) {
			curType = ITEM;
		}
		else {
			curType = TXT;
			if (preType == ITEMHEAD || preType == ITEM)
				lineNo += 2, colNo = 0;
		}
		//去除头尾空格
		strstrip(str);
		//空的项目列表头, 后面跟列表时不留空格, 因此-1用于抵消后面+1
		if (curType == ITEMHEAD && str.length() == 0) --colNo;
		//不为屏幕末尾且段落有多行时, 用空格分开
		if (colNo != w && 
			(preType == TXT && curType == TXT
			|| preType==ITEM &&curType==ITEM
			|| preType==ITEMHEAD&&curType==ITEM)
			) {
			++colNo;
		}

		for (int i = 0; i < str.length(); ++i) {
			//到屏幕末尾(该换行)
			if (colNo == w) {
				//后面是空格, 则跳过, 一直到非空格
				if (str[i] == ' ')	continue;
				//行数+1, 列数=0
				++lineNo;
				if (curType == TXT) colNo = 0;
				else colNo = 3;
			}
			++colNo;
		}
		//更新前一行类型为文本
		preType = curType;
		//若运行到这里,证明不是空行,用于去除开头的空行, 则行数+1
		if (!has) has = true, ++lineNo;
	}
	cout << lineNo;
	
	return 0;
}



/**/














/**/