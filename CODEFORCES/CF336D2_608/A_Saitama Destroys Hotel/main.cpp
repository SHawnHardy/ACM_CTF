#include "cstdio"
#include "cstdlib"
#include "cstring"
#define M 110

struct d{
    int c,t;
};

d in[M];

int f(const void *a,const void *b){
    d *aa=(d*)a;
    d *bb=(d*)b;
    return (bb->c)-(aa->c);
}

int main(){
    int n=0,s=0,ans=0;
    scanf("%d%d",&n,&s);
    int m=n;
    while (n--) {
        int cc,tt;
        scanf("%d%d",&cc,&tt);
        in[n].c=cc;
        in[n].t=tt;
    }
    in[m].c=0;
    in[m].t=0;
    qsort(in, m+1, sizeof(d), f);
    n=-1;
    int l=s;
    while ((++n)<=m) {
        ans+=(l-in[n].c);
        if (ans<in[n].t) {
            ans=in[n].t;
        }
        l=in[n].c;
    }
    printf("%d",ans);
    return 0;
}
