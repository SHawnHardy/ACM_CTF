#include "cstdio"
#include "cstdlib"
#define M 200010
struct D{
    int x,y;
};
D d[M];

int cmpx(const void *a,const void *b){
    D *aa=(D*)a;
    D *bb=(D*)b;
    if ((bb->x)-(aa->x)) {
        return ((bb->x) - (aa->x));
    }
    else
        return ((bb->y) - (aa->y));
}

int cmpy(const void *a,const void *b){
    D *aa=(D*)a;
    D *bb=(D*)b;
    if ((bb->y)-(aa->y)) {
        return ((bb->y) - (aa->y));
    }
    else
        return ((bb->x) - (aa->x));
}

typedef long long LL;
int main(){
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d%d",&d[i].x,&d[i].y);
    }
    LL ans=0;
    qsort(d, n, sizeof(D), cmpx);
    int lx=d[0].x;
    int ly=d[0].y;
    LL tn=1;
    LL tc=1;
    for (int i=1; i<n; i++) {
        int tx=d[i].x;
        int ty=d[i].y;
        if (tx==lx&&ty==ly)
            tc++;
        else {
            ans-=tc*(tc-1);
            tc=1;
        }
        if (lx==tx)
            tn++;
        else {
            ans+=tn*(tn-1);
            tn=1;
        }
        lx=tx;
        ly=ty;
    }
    ans-=tc*(tc-1);
    ans+=tn*(tn-1);
    
    qsort(d, n, sizeof(D), cmpy);
    tn=1;
    lx=d[0].x;
    ly=d[0].y;
    for (int i=1; i<n; i++) {
        int tx=d[i].x;
        int ty=d[i].y;
        if (ly==ty)
            tn++;
        else {
            ans+=tn*(tn-1);
            tn=1;
        }
        lx=tx;
        ly=ty;
    }
    ans+=tn*(tn-1);
    printf("%I64d\n",ans/2);
    return 0;
}