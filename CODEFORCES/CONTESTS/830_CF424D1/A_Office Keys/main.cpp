#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "cmath"
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

int a[maxn];
int b[maxn];

int main() {
    int n,k,p;
    scanf("%d %d %d",&n,&k,&p);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    for (int i=0; i<k; i++) {
        scanf("%d",&b[i]);
    }
    sort(a,a+n);
    sort(b,b+k);
    
    ll ans=0x3f3f3f3f3f3f3f3f;
    for (int i=0; (n-1+i)<k; i++) {
        ll tans=0;
        for (int j=0; j<n; j++) {
            tans=max(tans,(ll)abs(a[j]-b[j+i])+(ll)abs(b[j+i]-p));
        }
        ans=min(ans,tans);
    }
    
    
    printf("%I64d\n",ans);
    return 0;
}