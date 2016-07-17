#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "algorithm"
using namespace std;
int head[20010],cost[20010];
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)){
        if ((n+m)==0)
            return 0;
        memset(head, 0, sizeof(head));
        memset(cost, 0, sizeof(cost));
        for (int i=0; i<n; i++)
            scanf("%d",&head[i]);
        for (int i=0; i<m; i++)
            scanf("%d",&cost[i]);
        sort(head, head+n);
        sort(cost, cost+m);
        int flag=0,ans=0,p=0;
        for (int i=0; i<n; i++) {
            for (; ; p++) {
                if ((n-i)>(m-p)) {
                    flag=1;
                    break;
                }
                if (cost[p]>=head[i]) {
                    ans+=cost[p];
                    p++;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        if (flag) {
            puts("Loowater is doomed!");
        }
        else {
            printf("%d\n",ans);
        }
    }
    return 0;
}