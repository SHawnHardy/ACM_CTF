#include "cstdio"
#include "cstdlib"
int main(){
    int n,m;
    int ans=0;
    scanf("%d%d",&n,&m);
    int t[110]={0};
    while (n--) {
        int i=0;
        scanf("%d",&i);
        while (i--) {
            int in=0;
            scanf("%d",&in);
            if (!t[in]) {
                ans++;
                t[in]=1;
            }
        }
    }
    if (ans==m) 
        puts("YES");
    else
        puts("NO");
    return 0;
}