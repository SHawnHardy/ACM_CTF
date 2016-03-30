#include "cstdio"
#include "cstdlib"
#include "cstring"
const int MX=32100;
const int MN=15100;
int T[MX]={0};
int ans[MN]={0};

int lb(int x){
    return x&(-x);
}
void Add(int x){
    while (x<MX) {
        T[x]++;
        x+=lb(x);
    }
}
int Ask(int x){
    int ans=0;
    while (x>0) {
        ans+=T[x];
        x-=lb(x);
    }
    return ans;
}


int main(){
    int N;
    scanf("%d",&N);
    for (int i=0; i<N; i++) {
        int ix,iy;
        scanf("%d%d",&ix,&iy);
        ans[Ask(ix+1)]++;
        Add(ix+1);
    }
    for (int i=0; i<N; i++) {
        printf("%d\n",ans[i]);
    }
    return 0;
}