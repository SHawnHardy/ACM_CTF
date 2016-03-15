#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;


int num[2010];
int main(){
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(num, 0, sizeof(num));
        for (int i=0; i<n+m; i++) {
            scanf("%d",num+i);
        }
        sort(num, num+n+m);
        int ans=0;
        for (int i=0; i<n; i++) {
            ans+=num[i];
        }
        printf("%d\n",ans);
    }
    return 0;
    
}