#include "cstdio"
#include "cstdlib"
#include "cstring"
int main(){
    int list[50];
    int a=1,b=1;
    list[1]=1;
    list[2]=2;
    for (int i=3; i<50; i++) {
        int tans=a+b;
        list[i]=tans+list[i-1];
        a=b;
        b=tans;
    }
    int n;
    scanf("%d",&n);
    printf("%d\n",list[n]);
    return 0;
}