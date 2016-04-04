#include "cstdio"

typedef long long int LL;

int main(){
    LL m,c1,b,c;
    scanf("%I64d%I64d%I64d%I64d",&m,&c1,&b,&c);
    LL c2=b-c;
    if (c1<=c2||m<b) {
        printf("%I64d\n",m/c1);
    }
    else {
        LL ans=0;
        m-=b;
        ans=m/c2;
        m%=c2;
        m+=b;
        m-=c2;
        ans++;
        ans+=(m/c1);
        printf("%I64d\n",ans);
    }
    return 0;
}
