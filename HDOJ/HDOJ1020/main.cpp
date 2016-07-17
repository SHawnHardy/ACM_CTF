#include "cstdio"
#include "cstdlib"
#include "cstring"
char str[10010];
int main(){
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%s",str);
        int len=(int)strlen(str);
        char lc=str[0];
        int ll=1;
        for (int i=1; i<len; i++) {
            if (str[i]!=lc) {
                if (ll>1)
                    printf("%d",ll);
                putchar(lc);
                lc=str[i];
                ll=1;
            }
            else {
                ll++;
            }
        }
        if (ll>1)
            printf("%d",ll);
        putchar(lc);
        putchar('\n');
    }
    return 0;
}