#include "cstdio"
const double eps=1e-8;
int main(){
    double a,b;
    scanf("%lf%lf",&a,&b);
    if(-eps<a-b&&a-b<eps)    puts("yes");
    else                puts("no");
    return 0;

}
