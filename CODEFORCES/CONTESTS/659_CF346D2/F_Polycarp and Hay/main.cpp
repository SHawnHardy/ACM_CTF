#include "cstdio"
#include "cstdlib"
#include "cstring"
typedef long long int LL;
int fa[1000100];
LL l[1000100];

int bc(int x){
    return x==fa[x]?x:fa[x]=bc(fa[x]);
}
struct D{
    int h;
    int s;
};
int n,m;
LL tar=0;
int tarf=0;
D d[1000100];
int List[1010][1010]={0};
int vis[1010][1010]={0};
LL answ=0;
int Listp[1010][1010]={0};

int cmp(const void *a,const void *b){
    D *aa=(D*)a;
    D *bb=(D*)b;
    return (bb->h)-(aa->h);
}
void DFS(int x,int y){
    vis[x][y]=1;
    
    if (!tar) {
        return;
    }
    if (bc(x*m+y)==tarf) {
        if (!(List[x][y])) {
            List[x][y]=1;
            tar--;
        }
        if (tar) {
            if (x>0) {
                if (!(vis[x-1][y])) {
                    DFS(x-1,y);
                }
            }
            if (x<n-1) {
                if (!(vis[x+1][y])) {
                    DFS(x+1, y);
                }
            }
            if (y>0) {
                if (!(vis[x][y-1])) {
                    DFS(x, y-1);
                }
            }
            if (y<m-1) {
                if (!(vis[x][y+1])) {
                    DFS(x, y+1);
                }
            }
            
        }
        
    }
}



int main(){
    LL k;
    scanf("%d%d%I64d",&n,&m,&k);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int ts=i*m+j;
            d[ts].s=ts;
            scanf("%d",&d[ts].h);
        }
    }
    qsort(d, n*m, sizeof(D), cmp);
    for (int i=0; i<n*m; i++) {
        fa[i]=i;
        l[i]=1;
    }
    int flag=1;
    for (int i=0; i<n*m; i++) {
        int ts=d[i].s;
        LL w=(LL)d[i].h;
        int tx=ts/m;
        int ty=ts%m;
        Listp[tx][ty]=1;
        if (tx>0&&(Listp[tx-1][ty])) {
            int ffa=bc(ts);
            int ffb=bc(ts-m);
            if (ffa!=ffb&&Listp[ffb/m][ffb%m]) {
                fa[ffa]=ffb;
                l[ffb]+=l[ffa];
            }
        }
        if (tx<n-1&&Listp[tx+1][ty]) {
            int ffa=bc(ts);
            int ffb=bc(ts+m);
            if (ffa!=ffb&&Listp[ffb/m][ffb%m]) {
                fa[ffa]=ffb;
                l[ffb]+=l[ffa];
            }
        }
        if (ty>0&&Listp[tx][ty-1]) {
            int ffa=bc(ts);
            int ffb=bc(ts-1);
            if (ffa!=ffb&&Listp[ffb/m][ffb%m]) {
                fa[ffa]=ffb;
                l[ffb]+=l[ffa];
            }
        }
        if (ty<m-1&&Listp[tx][ty+1]) {
            int ffa=bc(ts);
            int ffb=bc(ts+1);
            if (ffa!=ffb&&Listp[ffb/m][ffb%m]) {
                fa[ffa]=ffb;
                l[ffb]+=l[ffa];
            }
        }
        if (l[bc(ts)]*w>=k&&(!(k%w))) {
            printf("YES\n");
            flag=0;
            tar=k/w;
            tarf=bc(ts);
            DFS(tx, ty);
            answ=w;
            break;
        }
        
    }
    if (flag) {
        puts("NO");
    }
    else {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (List[i][j]) {
                    printf("%I64d",answ);
                }
                else {
                    printf("0");
                }
                if (j!=m-1) {
                    printf(" ");
                }
                else{
                    printf("\n");
                }
            }
        }
    }
    return 0;
}