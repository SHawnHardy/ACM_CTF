#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "algorithm"
using namespace std;
int ans[1000000];
int ansn=0;
int in[100100];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int p=1;
    for (int i=0; i<n; i++)
        scanf("%d",in+i);
    sort(in, in+n);
    for (int i=0; i<n; i++) {
        if (m<0)
            break;
        int t=in[i];
        while (t>p) {
            m-=p;
            if (m>=0)
                ans[ansn++]=p;
            else
                break;
            p++;
        }
        p++;
    }
    if (m>0) {
        while (m>=0) {
            m-=p;
            if (m>=0)
                ans[ansn++]=p;
            else break;
            p++;
        }
    }
    printf("%d\n",ansn);
    for (int i=0; i<ansn; i++) {
        printf("%d",ans[i]);
        if (i<ansn-1)
            putchar(' ');
        else 
            putchar('\n');
    }
    return 0;
}