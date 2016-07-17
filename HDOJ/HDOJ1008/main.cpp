#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "cmath"
int T(int s,int t){
    if (s>t)
        return 4*(s-t);
    else
        return 6*(t-s);
}
int main(){
    int n;
    while (scanf("%d",&n)) {
        if (!n)
            break;
        else {
            int p=0,ans=0;
            for (int i=0; i<n; i++) {
                int t;
                scanf("%d",&t);
                ans+=T(p, t);
                p=t;
                ans+=5;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}