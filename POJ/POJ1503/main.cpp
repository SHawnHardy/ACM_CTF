#include "cstdio"
#include "cstdlib"
#include "cstring"

char in[110];
char ans[110];

int main(){
    memset(ans, 0, sizeof(ans));
    ans[0]='0';
    while (scanf("%s",in)) {
        if (strlen(in)==1&&in[0]=='0') {
            break;
        }
        int l,r;
        for (l=0,r=(int)(strlen(in)-1); l<r; l++,r--) {
            char t=in[l];
            in[l]=in[r];
            in[r]=t;
        }
        int flag=0,p=0;
        for (p=0; p<strlen(in); p++) {
            int t=in[p]-'0'+flag;
            if (p<strlen(ans))
                t+=ans[p]-'0';
            flag=0;
            if (t>9) {
                flag=1;
                t-=10;
            }
            ans[p]=t+'0';
            
        }
        while (flag) {
            if(ans[p]=='\0'){
                ans[p+1]='\0';
                ans[p]='1';
                flag=0;
            }
            else {
                ans[p]++;
                flag=0;
                if (ans[p]>'9') {
                    ans[p]-=10;
                    flag=1;
                }
            }
            p++;
        }
    }
    for (int i=(int)(strlen(ans)-1); i>=0; i--) {
        putchar(ans[i]);
    }
    putchar('\n');
    return 0;
}