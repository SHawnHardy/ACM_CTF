#include "cstdio"
#include "cstdlib"
#define M 100010
int main(){
    int n=0;
    int ans=1;
    char in[M];
    scanf("%d",&n);
    scanf("%s",in);
    for (int i=0; i<n-1; i++) {
        if (in[i]!=in[i+1]) {
            ans++;
        }
    }
    if (n<ans+2) {
        printf("%d",n);
    }
    else{
        printf("%d",ans+2);
    }
    return 0;
}
