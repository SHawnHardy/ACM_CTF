#include "cstdio"
#include "cstdlib"
#include "cstring"
int main(){
    int n;
    while (scanf("%d",&n)==1) {
        n%=4;
        if (n==2)
            puts("yes");
        else
            puts("no");
    }
    return 0;
}