/*
 ID: shawn_w1
 PROG: milk
 LANG: C++
 */
#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "algorithm"
using namespace std;
struct D{
    int v;
    int c;
};
D d[5010];

bool cmp(const D a,const D b){
    return (a.v-b.v)<0;
}



int main(){
    FILE *in,*out;
    in=fopen("milk.in", "r");
    out=fopen("milk.out", "w");
    int n,m;
    fscanf(in, "%d%d",&n,&m);
    for (int i=0; i<m; i++) {
        fscanf(in, "%d%d",&d[i].v,&d[i].c);
    }
    sort(d, d+m, cmp);
    int p=0;
    int ans=0;
    while (n>0) {
        if (n>=d[p].c) {
            ans+=d[p].c*d[p].v;
            n-=d[p].c;
        }
        else {
            ans+=n*d[p].v;
            n=0;
        }
        p++;
    }
    fprintf(out,"%d\n",ans);
    fclose(in);
    fclose(out);
    return 0;
}