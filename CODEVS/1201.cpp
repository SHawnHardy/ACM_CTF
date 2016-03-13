#include "cstdio"
int main(){
    int T;
    scanf("%d",&T);
    int mmax,mmin;
    scanf("%d",&mmax);
    mmin=mmax;
    while(--T){
        int tmp;
        scanf("%d",&tmp);
        mmax= mmax> tmp? mmax :tmp;
        mmin= mmin< tmp? mmin :tmp;
    }
    printf("%d %d\n",mmin,mmax);
    return 0;
}