#include "cstdio"
#include "cstdlib"
#include "cstring"
//123
//456
//789           0 1 2 3 4 5 6 7 8 9
int jg[10][10]={0,0,0,0,0,0,0,0,0,0,
                0,0,0,2,0,0,0,4,0,5,//1
                0,0,0,0,0,0,0,0,5,0,//2
                0,2,0,0,0,0,0,5,0,6,//3
                0,0,0,0,0,0,5,0,0,0,//4
                0,0,0,0,0,0,0,0,0,0,//5
                0,0,0,0,5,0,0,0,0,0,//6
                0,4,0,5,0,0,0,0,0,8,//7
                0,0,5,0,0,0,0,0,0,0,//8
                0,5,0,6,0,0,0,8,0,0};//9


int mem[10];
typedef long long LL;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int flag=1;
        LL th=0,la=0;
        memset(mem,0,sizeof(mem));
        for (int i=0; i<n; i++) {
            la=th;
            scanf("%lld",&th);
            if(!flag) continue;
            
            if (th>9||th<=0) {
                th=0;
                flag=0;
                continue;
            }
            if (mem[th]) {
                flag=0;
                continue;
            }
            mem[th]=1;
            if (jg[la][th]) {
                if (mem[jg[la][th]]==0) {
                    flag=0;
                }
            }
        }
        if (n<4) {
            flag=0;
        }
        if (flag) {
            printf("valid\n");
        }
        else {
            printf("invalid\n");
        }
    }
    return 0;
}