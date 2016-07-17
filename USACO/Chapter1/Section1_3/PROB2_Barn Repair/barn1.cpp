/*
 ID: shawn_w1
 PROG: barn1
 LANG: C++
 */
#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "algorithm"
#include "queue"

using namespace std;

int b[210];

struct num {
    int x;
    bool operator < (const num &a) const {
        return x>a.x;
    }
};

priority_queue<num> q;


int main(){
    FILE *in,*out;
    in=fopen("barn1.in", "r");
    out=fopen("barn1.out", "w");
    int m,s,c;
    fscanf(in, "%d%d%d",&m,&s,&c);
    memset(b, 0, sizeof(b));
    for (int i=0; i<c; i++) {
        fscanf(in,"%d",b+i);
    }
    sort(b, b+c);
    for (int i=1; i<c; i++) {
        int t=(b[i]-b[i-1]-1);
        if (t) {
            num tt;
            tt.x=t;
            q.push(tt);
        }
    }
    int ans=c;
    while (q.size()>=m) {
        ans+=q.top().x;
        q.pop();
    }
    fprintf(out,"%d\n",ans);
    fclose(in);
    fclose(out);
    return 0;
}