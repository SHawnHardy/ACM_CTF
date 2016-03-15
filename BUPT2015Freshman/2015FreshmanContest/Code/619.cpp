#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "algorithm"
using namespace std;

int in[50010];


int main(){
    int T;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        memset(in, 0, sizeof(in));
        for (int i=0; i<n; i++) {
            scanf("%d",in+i);
        }
        sort(in,in+n);
        int q;
        scanf("%d",&q);
        while (q--) {
            int w;
            scanf("%d",&w);
            int l=0,r=n-1;//l<=w r>w
            if (in[r]<=w) {
                printf("%d\n",n);
                continue;
            }
            else if(in[l]>w) {
                printf("0\n");
                continue;
            }
            else {
                while (r-l>1) {
                    int mid=(l+r)>>1;
                    if (in[mid]<=w)     l=mid;
                    else            r=mid;
                }
                printf("%d\n",l+1);
            }
        }
    }
    
    return 0;
    
}