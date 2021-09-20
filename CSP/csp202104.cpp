/*
	题目编号: 202104-1
	题目名称: 灰度直方图
*/
/*
#include <iostream>
#include <cstdio>

using namespace std;

int h[260];

int main() {
	int n, m, L;
	scanf("%d %d %d", &n, &m, &L);
	int ipt;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &ipt);
			++h[ipt];
		}
	}
	for (int i = 0; i < L; ++i) {
		printf("%d ", h[i]);
	}
	return 0;
}


/*
	题目编号: 202104-2
	题目名称: 邻域均值
*/
/*
#include <iostream>
#include <cstdio>

using namespace std;

int sum[605][605];
int n, L, r, t;

bool isDark(int x, int y) {
	int up = x - r >= 1 ? x - r : 1, down = x + r <= n ? x + r : n;
	int left = y - r >= 1 ? y - r : 1, right = y + r <= n ? y + r : n;
	// 邻域的像素灰度和
	int s = sum[down][right] - sum[down][left - 1]
		- sum[up - 1][right] + sum[up - 1][left - 1];
	// 邻域像素个数
	int sz = (down - up + 1) * (right - left + 1);
	return s <= sz * t;
}

int main() {
	scanf("%d %d %d %d", &n, &L, &r, &t);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &sum[i][j]);
			sum[i][j] += sum[i][j - 1];
		}
	}
	// sum[i][j]最终表示二维前缀和
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			sum[i][j] += sum[i - 1][j];
		}
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			res += isDark(i, j);
		}
	}
	printf("%d\n", res);
	return 0;
}


/*
	题目编号: 202104-3
	题目名称: DHCP服务器
*/

/* 90 分 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

enum class IpState {
	NOT_ALLOC,
	WAIT_ALLOC,
	USING,
	TIME_OUT
};

struct IpNode {
	IpState stat;
	int outTime;
	char user[24];
};

struct Ipt {
	int t;
	char sender[24], recver[24], pkgType[4];
	int ip, outTime;
};

const char* PKG_DIS = "DIS";
const char* PKG_OFR = "OFR";
const char* PKG_REQ = "REQ";
const char* PKG_ACK = "ACK";
const char* PKG_NAK = "NAK";


IpNode ipPool[10005];
Ipt ipt;

int N, T_def, T_max, T_min;
char H[24];
int n;
int sendTime;


void printPkg(const char* sender, const char* recver,
	const char* pkgType, int ip, int outTime) {
	printf("%s %s %s %d %d\n", sender, recver, pkgType, ip,
		outTime);
}


void initDHCP() {
	for (int i = 1; i <= N; ++i) {
		IpNode& dest = ipPool[i];
		dest.stat = IpState::NOT_ALLOC;
		dest.user[0] = 0;
		dest.outTime = 0;
	}
}

void setIpOutTime(int ip) {
	IpNode& dest = ipPool[ip];
	if (ipt.outTime == 0) {
		dest.outTime = ipt.t + T_def;
	}
	else if (ipt.outTime - ipt.t < T_min) {
		dest.outTime = ipt.t + T_min;
	}
	else if (ipt.outTime - ipt.t > T_max) {
		dest.outTime = ipt.t + T_max;
	}
	else {
		dest.outTime = ipt.outTime;
	}
}

void flashIpPool(int curTime) {
	for (int i = 1; i <= N; ++i) {
		IpNode& cur = ipPool[i];
		if (cur.stat != IpState::WAIT_ALLOC
			&& cur.stat != IpState::USING) {
			continue;
		}
		if (curTime >= cur.outTime) {
			if (cur.stat == IpState::WAIT_ALLOC) {
				cur.stat = IpState::NOT_ALLOC;
				cur.user[0] = 0;
				cur.outTime = 0;
			}
			else {
				cur.stat = IpState::TIME_OUT;
				cur.outTime = 0;
			}
		}
	}
}

int getIp() {
	flashIpPool(ipt.t);
	int destIp = 0;
	for (int i = 1; i <= N; ++i) {
		if (strcmp(ipPool[i].user, ipt.sender) == 0) {
			destIp = i;
			goto GotIp;
		}
	}
	for (int i = 1; i <= N; ++i) {
		if (ipPool[i].stat == IpState::NOT_ALLOC) {
			destIp = i;
			goto GotIp;
		}
	}
	for (int i = 1; i <= N; ++i) {
		if (ipPool[i].stat == IpState::TIME_OUT) {
			destIp = i;
			goto GotIp;
		}
	}
	return 0;

GotIp:
	ipPool[destIp].stat = IpState::WAIT_ALLOC;
	strcpy(ipPool[destIp].user, ipt.sender);

	setIpOutTime(destIp);

	return destIp;
}

void handleDiscover() {
	int ip = getIp();
	if (ip == 0) return;
	printPkg(H, ipt.sender, PKG_OFR, ip, ipPool[ip].outTime);
}


void handleRequest() {
	if (strcmp(ipt.recver, H) != 0) {
		for (int i = 1; i <= N; ++i) {
			if (strcmp(ipPool[i].user, ipt.sender) == 0
				&& ipPool[i].stat == IpState::WAIT_ALLOC) {
				ipPool[i].stat = IpState::NOT_ALLOC;
				ipPool[i].user[0] = 0;
				ipPool[i].outTime = 0;
			}
		}
		return;
	}
	if (ipt.ip<1 || ipt.ip>N
		|| strcmp(ipt.sender, ipPool[ipt.ip].user) != 0) {
		printPkg(H, ipt.sender, PKG_NAK, ipt.ip, 0);
		return;
	}
	ipPool[ipt.ip].stat = IpState::USING;
	setIpOutTime(ipt.ip);
	printPkg(H, ipt.sender, PKG_ACK, ipt.ip, ipPool[ipt.ip].outTime);
}

int main() {
	scanf("%d %d %d %d %s", &N, &T_def, &T_max, &T_min, H);
	scanf("%d", &n);
	initDHCP();

	for (int i = 0; i < n; ++i) {
		scanf("%d %s %s %s %d %d", &ipt.t, ipt.sender, ipt.recver,
			ipt.pkgType, &ipt.ip, &ipt.outTime);

		if (strcmp(ipt.recver, "*") == 0 || strcmp(ipt.recver, H) == 0) {
			if (strcmp(ipt.recver, "*") == 0
				&& strcmp(ipt.pkgType, PKG_DIS) != 0
				|| strcmp(ipt.recver, H) == 0
				&& strcmp(ipt.pkgType, PKG_DIS) == 0) {
				continue;
			}
			if (strcmp(ipt.pkgType, PKG_DIS) == 0) {
				handleDiscover();
			}
			else if (strcmp(ipt.pkgType, PKG_REQ) == 0) {
				handleRequest();
			}
		}
		else if (strcmp(ipt.pkgType, PKG_REQ) == 0) {
			handleRequest();
		}

	}
	return 0;
}


/**/