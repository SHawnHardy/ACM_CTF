#include "cstdio"
#include "cstdlib"
#include "cstring"
int a[210]={0};


int main(){
    int T;
    scanf("%d",&T);
    while (T--) {
        memset(a, 0, sizeof(a));
        int n;
        scanf("%d",&n);
        int ans=0;
        while (n--) {
            int s,t;
            scanf("%d%d",&s,&t);
            if (s>t) {
                int tmp=s;
                s=t;
                t=tmp;
            }
            for (int i=(s-1)/2; i<=(t-1)/2; i++) {
                a[i]++;
                ans = ans>a[i]? ans: a[i];
            }
        }
        printf("%d\n",ans*10);
    }
    return 0;
}