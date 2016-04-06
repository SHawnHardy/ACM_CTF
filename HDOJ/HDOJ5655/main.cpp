#include "cstdio"
#include "cstdlib"
#include "algorithm"
typedef long long int LL;
int main(){
    int T;
    scanf("%d",&T);
    LL in[5];
    while (T--) {
        for (int i=0; i<4; i++) 
            scanf("%lld",in+i);
        std::sort(in, in+4);
        LL l=in[3];
        if (in[0]==0) {
            puts("No");
            continue;
        }
        int flag=0;
        for (int i=0; i<3; i++) {
            l-=in[i];
            if (l<0) 
                flag=1;
        }
        if (flag) 
            puts("Yes");
        else puts("No");
        
    }
    return 0;
}