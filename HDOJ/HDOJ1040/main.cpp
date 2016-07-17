#include "cstdio"
#include "cstdlib"
#include "algorithm"
using namespace std;
int in[1010];
int main(){
    int T;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        for (int i=0; i<n; i++) {
            scanf("%d",in+i);
        }
        sort(in, in+n);
        for (int i=0; i<n; i++) {
            printf("%d%c",in[i],i==(n-1)?'\n':' ');
        }
    }
    return 0;
}