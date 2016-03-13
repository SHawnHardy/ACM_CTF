#include <stdio.h>
#include <stdlib.h>
#define Max 100010
int main(){
    int n,k;
    int ans=-1;
    int in[Max]={0};
    scanf("%d%d",&n,&k);
    int m=n;
    while (n--) scanf("%d",in+n);
    n=m;
    int r=2*k;
    int l=-1;
    
    if (k>(n/2)) ans=in[0];
    
    while ((--r)>(++l)) {
        if (ans<(in[r]+in[l])) {
            ans=in[r]+in[l];
        }
    }
    printf("%d",ans);
    return 0;
    
}
