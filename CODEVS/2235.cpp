#include "cstdio"
int main(){
    double a,b;
    scanf("%lf%lf",&a,&b);
    a*=b;
    a/=100.0;
    a+=0.5
    int ans=(int)a;
    ans*=10;
    printf("%d",ans);
    return 0;
}