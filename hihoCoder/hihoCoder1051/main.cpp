#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "cmath"
#include "algorithm"

int num[110];
using namespace std;
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n,m;
        scanf("%d%d",&n,&m);
        num[0]=0;
        for (int i=1; i<=n; i++) {
            scanf("%d",&num[i]);
        }
        if (n<=m) {
            puts("100");
            continue;
        }
        else {
            num[n+1]=101;
            int ans=0;
            for (int i=(m+1); i<=(n+1); i++) {
                ans=max(ans,num[i]-num[i-m-1]-1);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
