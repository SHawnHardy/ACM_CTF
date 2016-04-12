#include "cstdio"
#include "cstdlib"
#include "cstring"
const int M=2;

struct Mx{
    int d[M][M];
};
Mx operator * (Mx a,Mx b) {
    Mx c;
    memset(c.d, 0, sizeof(c.d));
    for(int i=0; i<M;i++) 
        for(int j=0; j<M; j++) 
            for(int k=0;k<M;k++) 
                c.d[i][j] += a.d[i][k] * b.d[k][j];
    return c;
}
Mx operator ^ (Mx a, int k) {
    Mx c;
    memset(c.d,0,sizeof(c.d));
    for(int i=0; i<M; i++)
        c.d[i][i]=1;
    while (k>0) {
        if(k&1) c = c*a;
        k=(k>>1);
        a = a*a;
    }
    return c;
}