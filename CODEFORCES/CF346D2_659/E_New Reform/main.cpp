#include "cstdio"
#include "cstdlib"
#include "cstring"

int fa[100100];
int s[100100];
int l[100100];

int bc(int x){
    return x==fa[x]?x:fa[x]=bc(fa[x]);
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1; i<=n; i++) {
        fa[i]=i;
        s[i]=1;
        l[i]=1;
    }
    while (m--) {
        int a,b;
        scanf("%d%d",&a,&b);
        int ffa=bc(a);
        int ffb=bc(b);
        if (ffa==ffb) {
            s[ffa]=0;
        }
        else {
            if (s[ffa]) {
                fa[ffa]=ffb;
                l[ffb]+=l[ffa];
            }
            else {
                fa[ffb]=ffa;
                l[ffa]+=l[ffb];
            }
            
        }
    }
    int ans=0;
    for (int i=1; i<=n; i++) {
        if (s[bc(i)]) {
            ans++;
            s[bc(i)]=0;
        }
    }
    printf("%d\n",ans);
    return 0;
}