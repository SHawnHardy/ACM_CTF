#include "cstdio"
#include "cstring"
const int M=100010;

int in[M];
int a[M];
int l[M];
int main(){
    int n=0;
    scanf("%d",&n);
    int nn=n;
    while (n--) {
        memset(in, 0, sizeof(in));
        memset(a, 0, sizeof(a));
        memset(l, 0, sizeof(l));
        int m=0;
        int ans=0;
        int ap=0;
        scanf("%d",&m);
        int mm=m;
        m--;
        scanf("%d",in+mm-m);
        a[mm-m]=in[mm-m];
        l[mm-m]=1;
        ans=a[mm-m];
        ap=1;
        while (m--) {
            int p=mm-m;
            scanf("%d",in+p);
            if (a[p-1]>=0) {
                a[p]=a[p-1]+in[p];
                l[p]=l[p-1];
            }
            else {
                a[p]=in[p];
                l[p]=p;
            }
            if (ans<a[p]) {
                ans=a[p];
                ap=p;
            }
        }
        printf("Case %d:\n",nn-n);
        printf("%d %d %d",ans,l[ap],ap);
        if (n)
            printf("\n\n");
        else printf("\n");
    }
    return 0;
}