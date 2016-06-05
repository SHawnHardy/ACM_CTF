/*
 ID: shawn_w1
 PROG: ride
 LANG: C++
 */
#include "cstdio"
#include "cstdlib"
#include "cstring"
char a[7];
char b[7];

int main(){
    FILE *in,*out;
    in=fopen("ride.in", "r");
    out=fopen("ride.out", "w");
    fscanf(in, "%s%s",a,b);
    int aa=1;
    int bb=1;
    for (int i=0; i<strlen(a); i++) {
        aa*=(int)(a[i]-'A'+1);
        aa%=47;
    }
    for (int i=0; i<strlen(b); i++) {
        bb*=(int)(b[i]-'A'+1);
        bb%=47;
    }
    if (aa==bb)   
        fprintf(out, "GO\n");
    else        
        fprintf(out, "STAY\n");
    return 0;
}