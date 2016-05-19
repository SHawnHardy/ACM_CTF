#include "cstdio"
#include "cstdlib"

struct E{
    int f,t,v;
};

int p=0;
E d[300000];


int cmp(const void *a,const void *b){
    E *aa=(E*)a;
    E *bb=(E*)b;
    return (aa->v)-(bb->v);
}

int fa[510];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}




int main(){
    int T;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        p=0;
        for (int i=0; i<n; i++) {
            fa[i]=i;
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (j<=i) {
                    int tv;
                    scanf("%d",&tv);
                    continue;
                }
                else {
                    int tv;
                    scanf("%d",&tv);
                    d[p].f=i;
                    d[p].t=j;
                    d[p++].v=tv;
                }
            }
        }
        qsort(d, p, sizeof(E), cmp);
        int ans=0;
        int cn=1;
        for (int i=0; cn!=n; i++) {
            int tf=d[i].f;
            int tt=d[i].t;
            int ftf=find(tf);
            int ftt=find(tt);
            if (ftf==ftt) {
                continue;
            }
            else {
                fa[ftf]=ftt;
                ans=(ans>d[i].v?ans:(d[i].v));
                cn++;
            }
        }
        printf("%d\n",ans);
        
    }
}