#include "cstdlib"
#include "cstdio"
#include "cstring"
#include "string"
#include "map"

using namespace std;
int ans[1010]={0};
int main(){
    int n;
    while (scanf("%d",&n)!=EOF) {
        char as[20];
        if (!n) {
            return 0;
        }
        memset(ans, 0, sizeof(ans));
        map<string,int> m;
        int p=0;
        while (n--) {
            char in[20];
            scanf("%s",in);
            if (m.find(in)==m.end()) {
                m.insert(pair<string, int>{in,++p});
                int t=m.find(in)->second;
                ans[t]++;
                if (ans[0]<ans[t]) {
                    ans[0]=ans[t];
                    strcpy(as, in);
                }
            }
            else{
                int t=m.find(in)->second;
                ans[t]++;
                if (ans[0]<ans[t]) {
                    ans[0]=ans[t];
                    strcpy(as, in);
                }
            }
            
        }
        printf("%s\n",as);
    }
    return 0;
}