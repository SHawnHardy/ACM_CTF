#include "cstdio"
#include "cstdlib"
int main(){
    int l=0;
    int r=10000;
    int k;
    scanf("%d",&k);
    while(r-l>1){
        int mid=(l+r)>>1;
        if((1+mid)*mid/2<k) l=mid;
        else                r=mid;
    }
    k-=((1+l)*l/2);
    if(r%2){
        printf("%d/%d\n",r+1-k,k);
    }
    else {
        printf("%d/%d\n",k,r+1-k);
    }
    return 0;
}