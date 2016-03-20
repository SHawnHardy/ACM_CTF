#include "cstdio"
#include "cstdlib"
#include "cstring"

typedef long long int LL;
const LL M=1000100;

bool nprm[M];
LL prm[M];



int main(){
    memset(nprm, 0, sizeof(nprm));
    memset(prm, 0, sizeof(prm));
    nprm[1]=1;
    LL p=0;
    for (LL i=2; i<M; i++) {
        if (!nprm[i])
            prm[p++]=i;
        for (LL j=0; j<p&&((i*prm[j])<M); j++) {
            nprm[i*prm[j]]=1;
            if (!(i%prm[j]))
                break;
        }
    }
    LL a,b,n;
    while(scanf("%lld%lld%lld",&a,&b,&n)){
        if(!a)
            break;
        else {
            while (nprm[a])
                a+=b;
            for(int i=1; i<n; i++){
                while(nprm[a+=b])
                    ;
            }
            printf("%lld\n",a);
        }
    }
    return 0;
}