#include "cstdio"
#include "cstdlib"
#include "cstring"

const int M=100010;
int main(){
    int zf=0;
    int uf=0;
    int t=0;
    char in[M];
    char ub[M];
    memset(ub, 0, sizeof(ub));
    ub[0]='1';
    int n=0;
    scanf("%d",&n);
    while (n--) {
        scanf("%s",in);
        int l=strlen(in);
        if (in[0]=='0')
            zf=1;
        if (zf)
            continue;
        if (uf) {
            t+=l-1;
            continue;
        }
        else{
            if (in[0]!='1')
                uf=1;
            else{
                for (int i=1; i<l; i++) {
                    if (in[i]=='0')
                        continue;
                    else{
                        uf=1;
                        break;
                    }
                }
            }
            
            if (uf)
                strcpy(ub, in);
            else
                t+=l-1;
        }
    }
    if (zf) {
        printf("0");
        return 0;
    }
    printf("%s",ub);
    for (int i=1; i<=t; i++)
        printf("0");
    return 0;
}

