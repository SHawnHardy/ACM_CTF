#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "cmath"
#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "queue"
#include "stack"
#include "set"
#include "map"

using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<int,string> pis;

const int maxn=500100;

struct nd {
    int v[2][2];
    int tag;
    nd *l;
    nd *r;
};

ll dp[32][2];

int arr[maxn];
nd *tr;
int tag=0;

void ist(int val,int w,nd *p,int wt,int c) {
    if (p->tag!=tag) {
        p->tag=tag;
        p->v[0][0]=0;
        p->v[0][1]=0;
        p->v[1][0]=0;
        p->v[1][1]=0;
    }
    else {
        dp[w][0]-=((p->v[0][0])*(p->v[1][1]));
        dp[w][1]-=((p->v[0][1])*(p->v[1][0]));
    }
    p->v[wt][val&(1<<w)?1:0]+=c;
    dp[w][0]+=((p->v[0][0])*(p->v[1][1]));
    dp[w][1]+=((p->v[0][1])*(p->v[1][0]));
    if (w==0)
        return ;
    else {
        nd *nxt=NULL;
        if (val&(1<<w)) {
            if (p->r==NULL) {
                (p->r)=(nd *)malloc(sizeof(nd));
                ((p->r)->tag)=-1;
                ((p->r)->l)=NULL;
                ((p->r)->r)=NULL;
            }
            nxt=p->r;
        }
        else {
            if (p->l==NULL) {
                (p->l)=(nd *)malloc(sizeof(nd));
                ((p->l)->tag)=-1;
                ((p->l)->l)=NULL;
                ((p->l)->r)=NULL;
            }
            nxt=(p->l);
        }
        ist(val,w-1,nxt,wt,c);
    }
}

int main() {
    int T;
    scanf("%d",&T);
    tr=(nd *)malloc(sizeof(nd));
    tr->tag=-1;
    tr->l=NULL;
    tr->r=NULL;
    while (T--) {
        memset(dp,0,sizeof(dp));
        tag++;
        int n;
        scanf("%d",&n);
        for (int i=0; i<n; i++) {
            scanf("%d",&arr[i]);
        }
        ist(arr[0], 30, tr, 0, 1);
        
        for(int i=1; i<n; i++) {
            ist(arr[i], 30, tr, 1, 1);
        }
        ll ans=0;
        for (int i=1; i<(n-1); i++) {
            ist(arr[i], 30, tr, 1, -1);
            int num=arr[i];
            for (int i=0; i<=30; i++) {
                ans+=dp[i][num&(1<<i)?1:0];
            }
            ist(arr[i], 30, tr, 0, 1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
