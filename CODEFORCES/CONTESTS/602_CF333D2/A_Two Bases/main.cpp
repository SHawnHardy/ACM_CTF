#include "cstdio"
#include "cstdlib"
#include "cstring"

#define LL  long long int

int main()
{
    int x[2], y[2];
    LL resultx=0, resulty=0;
    
    scanf("%d%d", &x[0], &x[1]);
    for (int i = 0; i < x[0]; i++){
        int op;
        scanf("%d",&op);
        resultx*=(LL)x[1];
        resultx+=(LL)op;
    }
    
    scanf("%d%d", &y[0], &y[1]);
    for (int i = 0; i < y[0]; i++){
        int op;
        scanf("%d",&op);
        resulty*=(LL)y[1];
        resulty+=(LL)op;
    }
    
    if (resultx > resulty)
        printf(">\n");
    else if (resultx == resulty)
        printf("=\n");
    else
        printf("<\n");
    
    return 0;
}
