#include "cstdio"
#include "cstdlib"
#include "cstring"
#define M 20100
typedef long long int LL;

int n,m;
LL t[M];

inline LL MAX(LL a,LL b){
    return a > b ? a:b;
}

inline LL lb(LL x){
    return x&(-x);
}
void add(int x,LL c){
    for (int i=x; i<M; i+=lb(i))
        t[i]+=c;
}
LL ask(int x){
    LL sum=0;
    while (x) {
        sum+=t[x];
        x-=lb(x);
    }
    return sum;
}

int BS(LL a){
    int sl=1;
    int sr=n;
    if (ask(sl)>=a)
        return 1;
    while (sr-sl>1) {
        int sm=(sr+sl)>>1;
        if (ask(sm)<a) {
            sl=sm;
        }
        else    sr=sm;
    }
    
    return sr;
}

void DF(LL ll,LL rr){
    int lll=BS(ll);
    int rrr=BS(rr);
    if (lll==rrr)
        add(lll, rr-ll+1);
    else {
        LL lz=ask(lll)-ll+1;
        LL rz=rr-ask(rrr-1);
        add(lll, lz);
        add(rrr, rz);
        for (int i=lll+1; i<rrr; i++) {
            LL ad=ask(i)-ask(i-1);
            add(i, ad);
        }
    }
}
LL XC(int lll,int rrr){
    LL re=0;
    if (lll>rrr)
        return 0;
    for (int i=lll; i<=rrr; i++)
        re=MAX(re, ask(i)-ask(i-1));
    return re;
}



void QF(LL ll,LL rr){
    int lll=BS(ll);
    int rrr=BS(rr);
    if (lll==rrr) {
        if (rr>ask(n))
            rr=ask(n);
        printf("%lld\n",rr-ll+1);
        return;
    }
    LL ans=0;
    ans=MAX(ans, ask(lll)-ll+1);
    ans=MAX(ans, rr-ask(rrr-1));
    ans=MAX(ans, XC(lll+1, rrr-1));
    printf("%lld\n",ans);
}



int main(){
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        memset(t, 0, sizeof(t));
        for (int i=1; i<=n; i++)
            add(i, 1);
        getchar();
        while (m--) {
            char op;
            LL l,r;
            scanf("%c %lld %lld",&op,&l,&r);
            getchar();
            if (op=='D')    DF(l,r);
            else            QF(l,r);
        }
    }
    return 0;
}