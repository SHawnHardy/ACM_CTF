#include "cstdio"
#include "cstdlib"
#include "cstring"
const int M=2;

struct Mx{
    int d[M][M];
};
Mx in;
int mm=7;
Mx operator * (Mx a,Mx b) {
    Mx c;
    memset(c.d, 0, sizeof(c.d));
    for(int i=0; i<M;i++) {
        for(int j=0; j<M; j++) {
            for(int k=0;k<M;k++) {
                c.d[i][j] += a.d[i][k] * b.d[k][j];
                c.d[i][j]%=mm;
            }
        }
    }
    return c;
}
Mx operator ^ (Mx a, int k) {
    Mx c;
    for(int i = 0; i < M; i++)
        for(int j = 0; j < M; j++)
            c.d[i][j] = (i == j);
    
    while (k>0) {
        if(k&1) c = c*a;
        k=(k>>1);
        a = a*a;
    }
    return c;
}
int main(){
    int A,B,k;
    while(scanf("%d%d%d",&A,&B,&k)!=EOF){
        if ((!A)&&(!B)&&(!k)) {
            break;
        }
        memset(in.d, 0, sizeof(in.d));
        in.d[0][0]=A;
        in.d[0][1]=1;
        in.d[1][0]=B;
        in.d[1][1]=0;
        if (k<3){
            printf("1\n");
            continue;
        }
        else{
            k-=2;
            in=in^k;
            int ans=in.d[0][0]+in.d[1][0];
            ans%=7;
            printf("%d\n",ans);
        }
    }
    return 0;
}