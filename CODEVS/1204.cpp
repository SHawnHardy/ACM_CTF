#include "cstdio"
#include "cstdlib"
#include "cstring"
#define M 110
int main(){
    char a[M];
    char b[M];
    scanf("%s%s",a,b);
    int flag=0;
    for(int i=0;i<strlen(a);i++){
        if(a[i]==b[0]){
            flag=1;
            for(int j=0;j<strlen(b);j++){
                if(a[i+j]!=b[j]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                printf("%d\n",i+1);
                return 0;
            }
        }
    }


}