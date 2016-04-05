#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "vector"
#include "queue"
#define M 100010
typedef long long int LL;
using namespace std;
int VI[M][2]={0};
int n,m;
struct Ed{
    int f,t;
};

vector<Ed> E;
vector<int> G[M];

int main(){
    scanf("%d%d",&n,&m);
    int mm=m;
    while (m--) {
        int fr,to;
        scanf("%d%d",&fr,&to);
        if (fr<to) {
            int t=to;
            to=fr;
            fr=t;
        }
        E.push_back((Ed){fr,to});
        G[fr].push_back((int)E.size()-1);
        VI[fr][0]++;
        VI[to][0]++;
    }
    m=mm;
    LL ans=-1;
    
    for (int i=1; i<=n; i++) {
        VI[i][1]=1;
        for (int j=0; j<G[i].size(); j++) {
            int t=E[G[i][j]].t;
            if (VI[t][1]+1>VI[i][1]) {
                VI[i][1]=VI[t][1]+1;
            }
        }
        LL t=(LL)VI[i][0]*(LL)VI[i][1];
        if (t>ans) 
            ans=t;
    }
    printf("%I64d",ans);
    return 0;
}
