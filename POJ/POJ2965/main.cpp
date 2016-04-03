#include "cstdio"
#include "cstdlib"
#include "cstring"
int in[4][4];
int func[4][4];
int ansn;
int ans;

int CK(int a[][4]){
    int c=1;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            c&=a[i][j];
        }
    }
    return c;
}
int main(){
    ans=-1;
    ansn=17;
    for (int i=0; i<4; i++) {
        char ins[5];
        scanf("%s",ins);
        getchar();
        for (int j=0; j<4; j++) {
            in[i][j]=(ins[j]=='-');
        }
    }
    for (int i=0; i<(1<<16); i++) {
        memset(func, 0, sizeof(func));
        int ti=i;
        int tans=0;
        for (int j=0; j<16; j++) {
            func[j/4][j%4]=ti&1;
            tans+=ti&1;
            ti>>=1;
        }
        if (tans>=ansn) {
            continue;
        }
        int tin[4][4];
        memcpy(tin, in, sizeof(in));
        for (int j=0; j<4; j++) {
            for (int k=0; k<4; k++) {
                if (func[j][k]==0)
                    continue;
                for (int l=0; l<4; l++) {
                    tin[j][l]^=1;
                    tin[l][k]^=1;
                }
                tin[j][k]^=1;
            }
        }
        if (CK(tin)) {
            if (tans<ansn) {
                ansn=tans;
                ans=i;
            }
        }
    }
    printf("%d\n",ansn);
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (ans&(1<<(i*4+j))) {
                printf("%d %d\n",i+1,j+1);
            }
        }
    }
    return 0;
}