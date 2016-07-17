/*
 ID: shawn_w1
 PROG: combo
 LANG: C++
 */
#include "cstdio"
#include "cstdlib"
#include "cstring"
bool chk[110][110][110]={0};

int main(){
    FILE *in,*out;
    in=fopen("combo.in", "r");
    out=fopen("combo.out", "w");
    int n;
    int a1,a2,a3,b1,b2,b3;
    fscanf(in,"%d%d%d%d%d%d%d",&n,&a1,&a2,&a3,&b1,&b2,&b3);
    int ans=0;
    a1--;
    a2--;
    a3--;
    b1--;
    b2--;
    b3--;
    for (int i=-2; i<3; i++) {
        for (int j=-2; j<3; j++) {
            for (int k=-2; k<3; k++) {
                int t1=(a1+i+n)%n,t2=(a2+j+n)%n,t3=(a3+k+n)%n;
                if (!chk[t1][t2][t3]) {
                    chk[t1][t2][t3]=true;
                    ans++;
                }
                t1=(b1+i+n)%n,t2=(b2+j+n)%n,t3=(b3+k+n)%n;
                if (!chk[t1][t2][t3]) {
                    chk[t1][t2][t3]=true;
                    ans++;
                }
            }
        }
    }
    fprintf(out,"%d\n",ans);
    
    
    
    fclose(in);
    fclose(out);
}