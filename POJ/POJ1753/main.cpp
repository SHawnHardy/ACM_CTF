#include "cstdio"
#include "cstdlib"
#include "cstring"
char in[4][6];
int iin[4][4];
void CG(int x,int y,int p[4][4]){
    p[x][y]^=1;
    if (x!=0)
        p[x-1][y]^=1;
    if (x<3)
        p[x+1][y]^=1;
    if (y!=0)
        p[x][y-1]^=1;
    if (y<3)
        p[x][y+1]^=1;
}

int CK(int p[4][4]){
    int a=1,o=0;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            a&=p[i][j];
            o|=p[i][j];
        }
    }
    return (a||(!o));
}

int main(){
    int ans=17;
    for (int i=0; i<4; i++) {
        scanf("%s",in[i]);
    }
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (in[i][j]=='b')
                iin[i][j]=1;
            else
                iin[i][j]=0;
        }
    }
    for (int i=0; i<(1<<16); i++) {
        int  tin[4][4];
        int ti=i;
        int tans=0;
        memcpy(tin, iin, sizeof(iin));
        for (int i=0; i<16; i++) {
            int t=ti&1;
            ti>>=1;
            if (t) {
                tans++;
                CG(i/4, i%4, tin);
            }
        }
        if (CK(tin))
            ans=ans<tans?ans:tans;
    }
    if (ans==17)
        puts("Impossible");
    else
        printf("%d\n",ans);
    return 0;
}