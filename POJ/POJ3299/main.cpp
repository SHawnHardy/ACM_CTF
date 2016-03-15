#include "cstdio"
#include "cmath"
#include "cstring"
#include "cmath"

int main(){
    char c;
    double t=0.0,d=0.0,h=0.0;
    int g[3];
    while (1) {
        memset(g,0,sizeof(g));
        scanf("%c",&c);
        if (c=='E') {
            break;
        }
        else {
            if (c=='T') {
                scanf("%lf",&t);
                g[0]=1;
            }
            else if (c=='D') {
                scanf("%lf",&d);
                g[1]=1;
            }
            else {
                scanf("%lf",&h);
                g[2]=1;
            }
        }
        for (int i=0; i<2; i++) {
            scanf("%c",&c);
            if (c=='T') {
                scanf("%lf",&t);
                g[0]=1;
            }
            else if (c=='D') {
                scanf("%lf",&d);
                g[1]=1;
            }
            else {
                scanf("%lf",&h);
                g[2]=1;
            }
        }
        getchar();
        
        if (!g[0])
            t=h-(0.5555)*(6.11*exp(5417.7530*((1/273.16)-(1/(d+273.16))))-10.0);
        else if (!g[1])
            d=1/((1/273.16)-log(((h-t)/0.5555+10.0)/6.11)/5417.7530)-273.16;
        else
            h=t+(0.5555)*(6.11*exp(5417.7530*((1/273.16)-(1/(d+273.16))))-10.0);
        printf("T %.1f D %.1f H %.1f\n",t,d,h);
        
    }
    return 0;
}