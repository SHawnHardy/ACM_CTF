#include "cstdio"
#include "cstdlib"
#include "cstring"
int main(){
    char n;
    while (n=getchar()) {
        if (n=='0')
            break;
        else {
            int ans=n-'0';
            while (n=getchar()) {
                if (n>'9'||n<'0')
                    break;
                else
                    ans+=n-'0';
            }
            while (ans>9) {
                int t=0;
                while (ans) {
                    t+=ans%10;
                    ans/=10;
                }
                ans=t;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}