#include "cstdio"
#include "cstdlib"
#include "cstring"
int GCD(int x,int y){
    return x%y==0?y:GCD(y,x%y);
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        int ans=0;
        scanf("%d",&ans);
        for (int i=1; i<n; i++) {
            int t;
            scanf("%d",&t);
            int g=GCD(ans, t);
            ans/=g;
            ans*=t;
        }
        printf("%d\n",ans);
    }
    return 0;
}