#include "cstdio"
#include "cstdlib"
#include "cstring"

char in[300];

int main(){
    while (fgets(in,300,stdin)!=NULL) {
        int ans=0;
        if (in[0]=='#')
            break;
        for (int i=0; i<strlen(in)-1; i++) {
            if (in[i]==' ')
                continue;
            ans+=(in[i]-'A'+1)*(i+1);
            
        }
        printf("%d\n",ans);
    }
    return 0;
}