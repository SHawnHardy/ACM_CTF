#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "cmath"
#include "algorithm"
#include "string"
#include "vector"
#include "queue"
#include "stack"
#include "set"
#include "map"
#include "iostream"
#include "complex"

#define pb push_back
#define fi first
#define se second
#define dbg(...) cerr<< "[" << #__VA_ARGS__ ":" << (__VA_ARGS__) << "]" <<endl;

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;

const int MAXN=200+10;

char p[MAXN][MAXN];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", &p[i][1]);
	}
	int ax, ay;
	for (int i = 1; i <= n; i++) {
		bool flag = false;
		for (int j = 1; j <= m; j++) {
			if (p[i][j] == 'B') {
				ax = i;
				ay = j;
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}
	int bx = ax;
	int by = ay;
	while (p[bx][by + 1] == 'B') {
		by++;
	}
	while (p[bx + 1][by] == 'B') {
		bx++;
	}
	printf("%d %d\n", (ax + bx) >> 1, (ay + by) >> 1);
	return 0;
}
