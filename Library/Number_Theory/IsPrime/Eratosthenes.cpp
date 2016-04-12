#include "cstdio"
#include "cstdlib"
#include "cstring"

typedef long long int LL;
const LL M=1000100;

bool nprm[M];

int main(){
    memset(nprm,0,sizeof(nprm));
    nprm[1]=1;
    for(LL i=2;i<M;i++){
        if(nprm[i])
            continue;
        else {
            for(LL j=i*2;j<M;j+=i)
                nprm[j]=1;
        }
    }
    return 0;
} 