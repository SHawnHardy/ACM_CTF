#include "cstdio"
#include "cstdlib"
#include "cstring"
int t[1100];
int main(){
    memset(t,0,sizeof(t));
    int T;
    int ans=0;
    scanf("%d",&T);
    while(T--){
        int tmp;
        scanf("%d",&tmp);
        if(!t[tmp]){
            ans++;
            t[tmp]=1;
        }
        
    }
    printf("%d\n",ans);
    for(int i=0;ans;i++){
        if(t[i]){
            printf("%d",i);
            ans--;
            if(ans)
                printf(" ");
        }
    }
    printf("\n");
    return 0;
}