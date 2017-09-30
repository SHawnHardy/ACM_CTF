#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "cmath"
#include "ctime"
#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "queue"
#include "stack"
#include "set"
#include "map"

using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<int,string> pis;

const int maxn=10010;

ll gcd(ll a,ll b) {
	return a%b==0?b:gcd(b,a%b);
}

ll fpow(ll a,ll x,ll mod) {
	ll re=1;
	ll t=a;
	while (x) {
		if (x&1)
			re=(re*t)%mod;
		t=(t*t)%mod;
		x>>=1;
	}
	return re;
}

inline ll modMtp(ll a,ll b,ll mod){
	a%=mod,b%=mod;
	ll ans=0;
	for(;b;b>>=1){
		if(b&1){
			ans+=a;
			if(ans>=mod)
				ans-=mod;
		}
		a<<=1;
		if(a>=mod)
			a-=mod;
	}
	if(ans>=mod)
		ans-=mod;
	else if(ans<0)
		ans+=mod;
	return ans;
}

ll fpow_s(ll a,ll x,ll mod) {
	ll re=1;
	ll t=a;
	while (x) {
		if (x&1)
			re=modMtp(re, t, mod);
		t=modMtp(t, t, mod);
		x>>=1;
	}
	return re;
}
//todo
bool isPrimeMR(ll x) {
	if (n==2)
		return true;
	if (x<2||n%2==0)
		return false;
	int a[]={2,7,61};
	int num=3;
//    int a[]={2,325,9375,28178,450775,9780504,1795265022};
//    int num=7;
	int t
}


int main() {
	return 0;
}