#include "cstdio"
#include "cstdlib"
int ans[60];
int main(){
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        int max=0;
        for (int j=0; j<n; j++) {
            int in;
            scanf("%d",&in);
            if (in>max) {
                max=in;
            }
        }
        ans[i]=max;
    }
    int flag=1;
    for (int i=0; i<n; i++) {
        if (ans[i]==n-1) {
            if (flag) {
                ans[i]=n;
                flag=0;
            }
        }
        printf("%d ",ans[i]);
    }
    return 0;
    
}
