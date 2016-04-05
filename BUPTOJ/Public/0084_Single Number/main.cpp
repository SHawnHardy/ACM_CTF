#include "cstdio"
#include "cstdlib"
#include "cstring"

int N=0;
typedef unsigned long long int LL;

LL one=0,two=0,t1=0,t2=0,in=0;

int main(){
    while (scanf("%d",&N)!=EOF) {
        int n=N;
        while (n--) {
            scanf("%llu",&in);
            t1=t2=in;
            t1&=one;
            t2&=two;
            in^=(t1+t2);
            two-=t2;
            one-=t1;
            one+=in;
            two+=t1;
        }
        printf("%llu\n",one);
        one=two=t1=t2=in=0;
    }
    return 0;
}