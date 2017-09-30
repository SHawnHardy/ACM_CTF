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

int main() {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%lld\n",fpow(a,b,c));
    return 0;
}

