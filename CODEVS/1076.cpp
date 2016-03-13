#include "cstdio"
#include "algorithm"
#include "cstring"
using namespace std;
int D[100010];

int main(){
    memset(D,0,sizeof(D));
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",D+i);
    }
    sort(D,D+T);
    for(int i=0;i<T;i++){
        printf("%d",D[i]);
        if(i!=T-1){
            printf(" ");
        }
        else{
            printf("\n");
            break;
        }
    }
    return 0;
}