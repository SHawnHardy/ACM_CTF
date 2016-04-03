#include "cstdio"
typedef long long int LL;
int main() {
    LL n=0;
    LL ans=0;
    while (scanf("%lld",&n)!=EOF) {
        ans=(1+n)*n/2;
        printf("%lld\n\n",ans);
    }
    return 0;
}