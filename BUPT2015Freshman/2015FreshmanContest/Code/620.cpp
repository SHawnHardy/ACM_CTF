#include "cstdio"
#include "cstdlib"
#include "algorithm"
using namespace std;




int main(){
    int n;
    scanf("%d",&n);
    while (n--) {
        int in[4];
        int flag=0;
        scanf("%d%d%d%d",in,in+1,in+2,in+3);
        sort(in, in+4);
        for (int i=0; i<4; i++) {
            int b[3];
            int p=0;
            for (int j=0; j<4; j++) {
                if (j==i) continue;
                else {
                    b[p++]=in[j];
                }
            }
            if (b[2]<b[0]+b[1]&&b[2]>b[1]-b[0]) {
                flag=1;
                break;
            }
        }
        if (flag) {
            puts("YES");
        }
        else {
            puts("NO");
        }
    }
    return 0;
}