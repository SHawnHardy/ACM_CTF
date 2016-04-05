#include "cstdio"
#include "cstdlib"
#include "cstring"

int main(){
    int T=0;
    scanf("%d",&T);
    while (T--) {
        int N=0;
        scanf("%d",&N);
        int m1=-1,m2=-2;
        while (N--) {
            int in=0;
            scanf("%d",&in);
            if (in>m1){
                m2=m1;
                m1=in;
            }
            if ((in<m1)&&(in>m2))
                m2=in;
        }
        printf("%d %d\n",m1,m2);
        
    }
    return 0;
}
