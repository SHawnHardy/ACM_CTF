/*
 ID: shawn_w1
 PROG: milk2
 LANG: C++
 */
#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "algorithm"
using namespace std;
struct D{
    int t;
    int s;
};
D d[10010];

bool cmp(const D a,const D b){
    return a.t<b.t;
}


int main(){
    FILE *in,*out;
    in=fopen("milk2.in", "r");
    out=fopen("milk2.out", "w");
    int n;
    fscanf(in, "%d",&n);
    for (int i=0; i<n; i++) {
        fscanf(in, "%d %d",&d[i*2].t,&d[i*2+1].t);
        d[i*2].s=1;
        d[i*2+1].s=-1;
    }
    
    sort(d,d+(2*n),cmp);
    d[2*n].t=1001000;
    int ans1=0,ans2=0;
    int p=0,nc=0,lt=d[0].t;
    while (p<(2*n)) {
        int tc=d[p].s;
        while ((p+1)<(2*n)&&d[p].t==d[p+1].t) {
            p++;
            tc+=d[p].s;
        }
        if (nc&&((nc+tc)==0)) {
            ans1=max(ans1,d[p].t-lt);
            lt=d[p].t;
        }
        else if (nc==0&&tc>0) {
            ans2=max(ans2,d[p].t-lt);
            lt=d[p].t;
        }
        
        nc+=tc;
        p++;
    }
    fprintf(out,"%d %d\n",ans1,ans2);
    fclose(in);
    fclose(out);
    return 0;
}