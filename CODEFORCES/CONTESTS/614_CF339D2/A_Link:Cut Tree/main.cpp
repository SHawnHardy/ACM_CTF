#include "cstdio"
#include "cstdlib"
#include "cmath"
#define LL long long int
int main(){
    LL l,r,k;
    double chk=1.0;
    int flg=1;
    scanf("%lld%lld%lld",&l,&r,&k);
    LL ans=1;
    while (ans<l) {
        ans*=k;
        chk*=k;
        if ((double)(chk-(double)ans)>10.0||(double)((double)ans-chk)>10.0) {
            printf("-1");
            return 0;
        }
    }
    while (ans<=r) {
        flg=0;
        printf("%lld ",ans);
        ans*=k;
        chk*=k;
        if ((double)(chk-(double)ans)>10.0||(double)((double)ans-chk)>10.0) {
            break;
        }
    }
    if (flg) {
        printf("-1");
    }
    return 0;
}