#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
#define P 1000000007

typedef long long int LL;
const LL mod=1e9+7;
LL l=0;
LL ans=0;
int in[1000100];
int main(){
    int n;
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        scanf("%d",in+i);
    }
    if (n==1) {
        printf("%d",in[1]-1);
        return 0;
    }
    else {
        l=min(in[1],in[2])-1;
        ans+=in[1]-1;
        for (int i=2;i<=n;i++)
        {
            ans+=(l*(min(in[i],in[i-1])-1))%mod+in[i]-1;
            ans%=mod;
            l=(l*(min(min(in[i], in[i-1]),in[i+1])-1))%mod+min(in[i],in[i+1])-1;
            l%=mod;
        }
    }
    printf("%I64d\n",ans);
    return 0;
}