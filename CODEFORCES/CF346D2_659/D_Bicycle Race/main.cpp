#include "cstdio"
#include "cstdlib"
#include "cstring"
int main(){
    int ans=0;
    int n;
    scanf("%d",&n);
    int tar=0;
    int sx,sy;
    int ssx,ssy;
    scanf("%d%d%d%d",&sx,&sy,&ssx,&ssy);
    if (sx==ssx)
        tar=1;
    else
        tar=0;

    for (int i=2; i<=n; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        int v1x=ssx-sx,v1y=ssy-sy;
        int v2x=x-ssx,v2y=y-ssy;
        if ((v1x*v2y-v1y*v2x)>0) {
            if (tar)
                ans++;
        }
        else {
            if (!tar)
                ans++;
        }
        sx=ssx;
        sy=ssy;
        ssx=x;
        ssy=y;
    }
    printf("%d\n",ans);
    return 0;
}