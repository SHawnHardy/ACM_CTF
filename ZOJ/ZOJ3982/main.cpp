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
#define mp(a,b) make_pair(a,b)

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;

const int MAXN=2000100;

int n;
ll mod;
ll a[MAXN];
ll asum[MAXN];
ll fac[MAXN];
ll inv[MAXN];

ll interval(int l,int r) {
    return (asum[r]-asum[l-1]+mod)%mod;
}
ll C(int n,int m) {
    if (m<0)
        return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}

ll mypow(ll a,ll x) {
    ll re=1;
    while (x) {
        if (x&1)
            re=re*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return re;
}

ll catalan(int x) {
    return (C(2*x,x)-C(2*x,x-1)+mod)%mod;
}

int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%lld",&n,&mod);
        ll b;
        scanf("%lld",&b);
        ll A,B;
        scanf("%lld%lld",&A,&B);
        a[0]=0;
        for (int i=1; i<=(2*n); i++) {
            b=(A*b+B)%mod;
            a[i]=a[i-1]+b+1;
        }
        fac[0]=1;
        for (int i=1; i<=(2*n); i++) {
            fac[i]=(fac[i-1]*i)%mod;
        }
        inv[2*n]=mypow(fac[2*n],mod-2);
        for (int i=(2*n); i>=1; i--) {
            inv[i-1]=inv[i]*i%mod;
        }
        
        asum[0]=0;
        for (int i=1; i<=(2*n); i++) {
            asum[i]=asum[i-1]+a[i];
            asum[i]%=mod;
        }
        ll ans=0;
        for (int i=1; i<=n; i++) {
            ans+=(((catalan(n-i)*catalan(i-1))%mod)*(((interval(2*i,2*n)-interval(1,2*n-2*i+1))+mod)%mod))%mod;
                ans=(ans+mod)%mod;
        }
        ans*=mypow(catalan(n),mod-2);
        ans%=mod;
        ans=(ans+mod)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
