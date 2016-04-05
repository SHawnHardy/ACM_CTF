#include "cstdio"
#include "cstdlib"
#include "cstring"
#define LL long long int

int ans[2][4010];
LL func(int a){
    if (a==1||a==0) {
        return 0;
    }
    LL re=(LL)a;
    re*=(LL)(a-1);
    re>>=1;
    return re;
}

int main(){
    int n;
    LL re=0;
    scanf("%d",&n);
    
    while (n--) {
        int x,y;
        scanf("%d%d",&x,&y);
        ans[0][y-x+1010]++;
        ans[1][y+x+1010]++;
    }
    
    for (int i=0; i<4010; i++) {
        re+=func(ans[0][i]);
        re+=func(ans[1][i]);
    }
    
    printf("%I64d",re);
    return 0;
}
