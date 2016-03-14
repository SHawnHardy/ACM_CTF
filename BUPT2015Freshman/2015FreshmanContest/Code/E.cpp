#include "cstdio"
#include "cstdlib"
#include "cstring"
//#define MAX(a,b) (int)a>(int)b ? (int)a : (int)b ;
#define M 20100
typedef long long int LL;
//const int INF=1000000010;

using namespace std;
int n,m;
int t[M];

inline int MAX(int a,int b){
    return a > b ? a:b;
}



inline int lb(int x){
    return x&(-x);
}
void add(int x,int c){
    for (int i=x; i<M; i+=lb(i)) {
        t[i]+=c;
    }
}
int ask(int x){
    int sum=0;
    while (x) {
        sum+=t[x];
        x-=lb(x);
    }
    return sum;
}

int BS(int a){
    
    int sl=1;
    int sr=n;
    if (ask(sr)<a) {
        return n;
    }
    if (ask(sl)>=a) {
        return 1;
    }
    while (sr-sl>1) {
        int sm=(sr+sl)>>1;
        if (ask(sm)<a) {
            sl=sm;
        }
        else    sr=sm;
    }
     
    
        //
    /*for (int i=1; i<=n; i++) {
        if (ask(i)>=a) {
            return i;
        }
    }
    return 0;
     */
    //
    return sr;
}


//int xdt[M*4];
/*void XG(int x,int c,int ll,int rr,int s){
    xdt[s]=MAX(xdt[s], c);
    if (ll==rr) {
        return;
    }
    
    
    int mid=(ll+rr)>>1;
    if (x<=mid) {
        XG(x, c, ll, mid, s*2+1);
    }
    else {
        XG(x, c, mid+1, rr, s*2+2);
    }
    


}*/

void DF(int ll,int rr){
    int lll=BS(ll);
    int rrr=BS(rr);
    //printf("\n%d %d\n%d %d\n",ll,lll,rr,rrr);

    if (lll==rrr) {
        add(lll, rr-ll+1);
        //XG(lll,ask(lll)-ask(lll-1),1,n,0);
        return;
    }
    else {
        int lz=ask(lll)-ll+1;
        int rz=rr-ask(rrr-1);
        add(lll, lz);
        //XG(lll,ask(lll)-ask(lll-1),1,n,0);
        add(rrr, rz);
        //XG(rrr,ask(rrr)-ask(rrr-1),1,n,0);
        for (int i=lll+1; i<rrr; i++) {
            int ad=ask(i)-ask(i-1);
            add(i, ad);
            //XG(i,ask(i)-ask(i-1),1,n,0);
        }
    }
}
/*
int XC(int s,int xl,int xr,int llll,int rrrr){
    int re=0;
    if (llll>rrrr) {
        return 0;
    }
    else if (llll==rrrr){
        return ask(llll)-ask(llll-1);
    }
    else {
        if (xr<llll||xl>rrrr) {
            return 0;
        }
        else if(llll<=xl&&xr<=rrrr){
            return xdt[s];
        }
        else {
            int mid=(xl+xr)>>1;
            re=MAX(re,XC(s*2, xl, mid, llll, rrrr));
            re=MAX(re,XC(s*2+1, mid+1, xr, llll, rrrr));
        
            return re;
        }
        
    }
    
}
 */
int XC(int s,int xl,int xr,int lll,int rrr){
    int re=0;
    if (lll>rrr) {
        return 0;
    }
    for (int i=lll; i<=rrr; i++) {
        re=MAX(re, ask(i)-ask(i-1));
    }
    return re;
}



void QF(int ll,int rr){
    int lll=BS(ll);
    int rrr=BS(rr);
    //printf("\n%d %d\n%d %d\n",ll,lll,rr,rrr);
    if (lll==rrr) {
        if (rr>ask(n)) {
            rr=ask(n);
        }
        printf("%d\n",rr-ll+1);
        return;
    }
    int ans=0;
    ans=MAX(ans, ask(lll)-ll+1);
    ans=MAX(ans, rr-ask(rrr-1));
    ans=MAX(ans, XC(1, 1, n, lll+1, rrr-1));
    printf("%d\n",ans);
}



int main(){
    //freopen("o.out", "w", stdout);
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        memset(t, 0, sizeof(t));
        //memset(xdt, 0, sizeof(xdt));
        for (int i=1; i<=n; i++) {
            add(i, 1);
        }
        /*for (int i=1; i<M*40; i++) {
            xdt[i]=1;
        }*/
        /*for (int i=1; i<=n; i++) {
            printf("%d ",ask(i));
        }
        printf("\n");
        for (int i=1; i<=n; i++) {
            printf("%d ",ask(i)-ask(i-1));
        }
        printf("\n");
        */
        getchar();
        while (m--) {
            char op;
            int l,r;
            scanf("%c %d %d",&op,&l,&r);
            getchar();
            if (op=='D') {
                DF(l,r);
                /*for (int i=1; i<=n; i++) {
                    printf("%d ",ask(i));
                }
                printf("\n");
                for (int i=1; i<=n; i++) {
                    printf("%d ",ask(i)-ask(i-1));
                }
                printf("\n");
                 */
                
            }
            else {
                QF(l,r);
            }
        }
    }
    return 0;
}