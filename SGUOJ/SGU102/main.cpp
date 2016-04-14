#include "cstdio"
#include "cstdlib"
int pi(int x){
    int re=x,a=x;
    for(int i=2;i*i<=a;i++){
        if(a%i==0){
            re=re/i*(i-1);
            while(a%i==0) a/=i;
        }
    }
    if(a>1) re=re/a*(a-1);
    return re;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",pi(n));
    return 0;
}