#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "iostream"
#define LL long long int
using namespace std;
struct P{
    int num;
    int x,y;
};
P d[100010];
int cmp(const void *a,const void *b){
    P* aa=(P*)a;
    P* bb=(P*)b;
    
    if ((aa->x)-(bb->x)) return (aa->x)-(bb->x);
    else return (aa->y)-(bb->y);
}

int main(){
    int n;
    std::ios_base::sync_with_stdio(false);
    cin>>n;
    for (int i=1;i<=n; i++) {
        int xx,yy;
        cin>>xx>>yy;
        d[i-1]=(P){i,xx,yy};
    }
    qsort(d, n, sizeof(P), cmp);
    LL vx=d[1].x-d[0].x;
    LL vy=d[1].y-d[0].y;
    
    int ans=-1;
    for (int i=2; i<n; i++) {
        LL tx=d[i].x-d[1].x;
        LL ty=d[i].y-d[1].y;
        
        if (vx*ty==vy*tx) {
            continue;
        }
        else {
            ans=i;
            break;
        }
    }
    printf("%d %d %d\n",d[0].num,d[1].num,d[ans].num);
    return 0;
}
