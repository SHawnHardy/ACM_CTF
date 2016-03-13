#include "cstdio"
int main(){
    int T;
    int ans=0;
    scanf("%d",&T);
    while(T--){
        int tmp;
        scanf("%d",&tmp);
        ans+=tmp;
    }
    printf("%d\n",ans);
    return 0;
}