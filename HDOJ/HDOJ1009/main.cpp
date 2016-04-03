#include "cstdio"
#include "cstdlib"
#include "cstring"
#define Max 1010
struct D{
    int c;
    int f;
};

inline int func(const void *a,const void *b){
    D* aa=(D*)a;
    D* bb=(D*)b;
    if ((!aa->f)&&(!bb->f)) {
        return bb->c-aa->c;
    }
    else if(!aa->f)
        return -1;
    else if(!bb->f)
        return 1;
    double va=(double)aa->c;
    va/=(double)aa->f;
    double vb=(double)bb->c;
    vb/=(double)bb->f;
    if (va<vb)
        return 1;
    else
        return -1;
}

D da[Max];
int main(){
    int M,N;
    while (scanf("%d%d",&M,&N)!=EOF) {
        memset(da, 0, sizeof(da));
        double ans=0;
        int nn=N;
        int ja,fd;
        if (M==-1)
            return 0;
        while (nn--) {
            scanf("%d%d",&ja,&fd);
            if (!ja) continue;
            da[N-nn-1].c=ja;
            da[N-nn-1].f=fd;
        }
        
        qsort(da, N, sizeof(D), func);
        for (int i=0; i<N; i++) {
            if (M>=da[i].f) {
                ans+=da[i].c;
                M-=da[i].f;
            }
            else{
                double v=(double)da[i].c;
                v/=(double)da[i].f;
                ans+=((double)M)*v;
                break;
            }
        }
        printf("%.3f\n",ans);
    }
    return 0;
}