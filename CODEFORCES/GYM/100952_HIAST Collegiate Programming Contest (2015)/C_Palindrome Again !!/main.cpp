#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "algorithm"
using namespace std;
const int maxn=100005;
char in[maxn];

int func(char a,char b){
    return min(abs((int)(a-b)), (int)(26-abs((int)a-b)));
}


int main(){
    int cas;
    scanf("%d",&cas);
    while (cas--) {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(in, 0, sizeof(in));
        scanf("%s",in+1);
        int ans=0;
        int l=0,r=0;
        
        for (int i=1; i<=n/2; i++) {
            if (in[i]!=in[n+1-i]) {
                if (!l)
                    l=i;
                r=i;
                ans+=func(in[i], in[n+1-i]);
            }
        }
        
        if (!ans)
            printf("0\n");
        else {
            m= m<=(n/2)?m:(n+1-m);
            if (m<=l)
                ans+=r-m;
            else if(m>=r)
                ans+=m-l;
            else
                ans+=min(m-l+r-l, r-m+r-l);
            printf("%d\n",ans);
        }
    }
    return 0;
}