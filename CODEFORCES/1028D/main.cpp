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

const int MAXN = 200 + 10;
const int INF = 2E9;
const ll mod = 1E9 + 7;

set<int> st;
int a, b, c, d;
ll ans = 1;
ll tans;

void add(int x) {
	if (ans == 0)
		return ;

	if (st.empty()) {
		st.insert(x);
		a = 0;
		b = x;
		c = x;
		d = INF;
		tans = 2;
		return ;
	}
	st.insert(x);
	
	
	if (x < a || x > d) {
		return ;
	}
	tans++;
	
	if (b == -1) {
		b = c = x;
		return ;
	}
	
	if (x < b) {
		b = x;
		return ;
	}
	if (x > c) {
		c = x;
		return ;
	}
}
void accept(int x) {
	if (ans == 0)
		return ;
	if (st.find(x) == st.end()) {
		ans = 0;
		return ;
	}
	if (x < a || x > d) {
		ans = 0;
		return ;
	}
	
	st.erase(x);
	
	if (x > a & x < d) {
		ans *= 2;
		ans %= mod;
	}
	tans = 1;
	
	if (st.empty()) {
		return ;
	}
	
	b = c = -1;
	auto oprd = st.upper_bound(x);
	if (oprd == st.end()) {
		d = INF;
	}
	else {
		d = *oprd;
	}
	if (oprd == st.begin()) {
		a = 0;
	}
	else {
		a = *(--oprd);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char opr[10];
		int x;
		cin >> opr >> x;
		if (opr[1] == 'D') {
			add(x);
		}
		else {
			accept(x);	
		}
	}
	cout << (ans * tans) % mod << endl;
	return 0;
}
