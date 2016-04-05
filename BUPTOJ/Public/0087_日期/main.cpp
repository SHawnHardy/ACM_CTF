#include "cstdio"
#include "cstdlib"
#include "cstring"

int main(){
    int T=0;
    int D[13]={0,0,31,59,90,120,151,181,212,243,273,304,334};
    int X=0,Y=0,Z=0;
    scanf("%d",&T);
    while (T--) {
        scanf("%d:%d:%d",&X,&Y,&Z);
        if(X%100){
            if (X%4)
                printf("%d\n",D[Y]+Z);
            else if(Y>2)
                printf("%d\n",D[Y]+Z+1);
            else
                printf("%d\n",D[Y]+Z);
        }
        else{
            if (X%400)
                printf("%d\n",D[Y]+Z);
            else if(Y>2)
                printf("%d\n",D[Y]+Z+1);
            else
                printf("%d\n",D[Y]+Z);
        }
    }
    return 0;
}
