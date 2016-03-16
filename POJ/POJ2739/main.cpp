#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "algorithm"
#include "map"
#define M 10010
int p[M];
int sp[M];
int s[760000];

int main(){
    memset(p, 0, sizeof(p));
    memset(sp, 0, sizeof(sp));
    memset(s, 0, sizeof(s));
    int t=1;
    for (int i=2; i<M; i++) {
        if (p[i]) {
            continue;
        }
        else {
            sp[t]=sp[t-1]+i;
            t++;
            for (int j=2; i*j<M; j++) {
                p[i*j]=1;
            }
        }
    }
    int tt=0;
    for (int i=1; i<t; i++) {
        for (int j=0; j<i; j++) {
            s[tt++]=sp[i]-sp[j];
        }
    }
    std::sort(s,s+tt);
    int in;
    while (scanf("%d",&in)) {
        if (!in) {
            break;
        }
        else {
            printf("%ld\n",std::upper_bound(s, s+tt, in)-std::lower_bound(s, s+tt, in));
        }
    }
    return 0;
}