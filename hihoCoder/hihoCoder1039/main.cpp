#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "cmath"
#include "algorithm"

using namespace std;
char str[110];
char tstr[110];

void insert(int x,char c) {
    memset(tstr,0,sizeof(tstr));
    memcpy(tstr,str,x*sizeof(char));
    tstr[x]=c;
    memcpy(tstr+x+1,str+x,strlen(str)-x);
    tstr[strlen(str)+1]='\0';

}

int func() {
    int flag=1;
    int rst=0;
    while (flag) {
        flag=0;
        int p=0;
        for (int i=0; i<strlen(tstr); i++) {
            int tflag=0;
            int trst=1;
            while (i+1<strlen(tstr)&&tstr[i]==tstr[i+1]) {
                tflag=1;
                flag=1;
                i++;
                trst++;
            }
            if (tflag) {
                rst+=trst;
            }
            else {
                tstr[p++]=tstr[i];
            }
        }
        tstr[p]='\0';
    }
    return rst;
}
int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        memset(str,0,sizeof(str));
        scanf("%s",str);
        int len=(int)strlen(str);
        int ans=0;
        for (int i=0; i<=len; i++) {
            insert(i,'A');
            ans=max(ans,func());
            insert(i,'B');
            ans=max(ans,func());
            insert(i,'C');
            ans=max(ans,func());
        }
        printf("%d\n",ans);
    }
    return 0;
}
