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

const int MAXN = 140000 + 10;

struct rect {
	pii x;
	pii y;
	rect() {
		
	}
	rect(int x1, int y1, int x2, int y2) {
		x = make_pair(x1, x2);
		y = make_pair(y1, y2);
	}
	rect operator &(const rect &b) {
		rect re(0, 0, 0, 0);
		re.x.first = max(this->x.first, b.x.first);
		re.x.second = min(this->x.second, b.x.second);
		
		re.y.first = max(this->y.first, b.y.first);
		re.y.second = min(this->y.second, b.y.second);
		return re;
	}
	bool chk() {
		return x.first <= x.second && y.first <= y.second;
	}
};
rect r[MAXN];
rect a[MAXN];
rect b[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		r[i] = rect(x1, y1, x2, y2);
		if (i) {
			a[i] = r[i] & a[i - 1];
		}
		else {
			a[i] = r[i];
		}
	}
	b[n - 1] = r[n - 1];
	for (int i = (n - 2); i >= 0; i--) {
		b[i] = b[i + 1] & r[i];
	}
	
	if (b[1].chk()) {
		printf("%d %d\n", b[1].x.first, b[1].y.first);
		return 0;
	}
	
	if (a[n - 2].chk()) {
		printf("%d %d\n", a[n - 2].x.first, a[n - 2].y.first);
		return 0;
	}
	
	for (int i = 1; i < (n - 1); i++) {
		if (a[i - 1].chk() && b[i + 1].chk()) {
			rect c = a[i - 1] & b[i + 1];
			if (c.chk()) {
				printf("%d %d\n", c.x.first, c.y.first);
				return 0;
			}
		}
	}
	return 0;
}

