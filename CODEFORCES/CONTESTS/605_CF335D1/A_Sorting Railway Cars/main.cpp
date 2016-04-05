#include "cstdio"
#include "cstdlib"
#include "cstring"

#define M 100010

int n=0;
int T[M]={0};

int main(){
    scanf("%d",&n);
    int m=n;
    int in=0;
    while (m--) {
        scanf("%d",&in);
        T[in]=T[in-1]+1;
    }
    int ans=0;
    for (int i=1; i<=n; i++) {
        if (ans<T[i]) {
            ans=T[i];
        }
    }

    printf("%d",n-ans);
    return 0;
    
}
