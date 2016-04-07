#include "cstdio"
#include "cstdlib"
#include "cstring"

struct D{
    int r;
    int s;
    char na[15];
};
D d[100100];

int cmp(const void *a,const void *b){
    D *aa=(D*)a;
    D *bb=(D*)b;
    if ((aa->r)==(bb->r))
        return (bb->s)-(aa->s);
    else
        return (aa->r)-(bb->r);
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0; i<n; i++)
        scanf(" %s %d %d",d[i].na,&d[i].r,&d[i].s);
    qsort(d, n, sizeof(D), cmp);
    int p=0;
    for (int i=1; i<=m; i++) {
        if (p+2==n||d[p+2].r!=i)
            printf("%s %s\n",d[p].na,d[p+1].na);
        else {
            if (d[p+1].s==d[p+2].s)
                puts("?");
            else
                printf("%s %s\n",d[p].na,d[p+1].na);
        }
        while (d[p].r==i&&i<m)
            p++;    
    }
    return 0;
}