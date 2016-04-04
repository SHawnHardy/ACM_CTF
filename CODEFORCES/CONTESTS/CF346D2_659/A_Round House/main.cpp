#include "cstdio"
#include "cstdlib"
#include "cstring"
int main(){
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    int t=a+b;
    while (t<0)
        t+=n;
    if (t%n)
        printf("%d\n",t%n);
    else
        printf("%d\n",n);
    return 0;
}