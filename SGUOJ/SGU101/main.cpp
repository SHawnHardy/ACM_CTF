#include "cstdio"
#include "cstdlib"
#include "vector"
#include "stack"
#include "algorithm"
using namespace std;
const int MAXN=7;

typedef pair<int, int> pii;

vector<pii> G[MAXN][MAXN];
int d[MAXN]={0};
stack<int> ans;

void Dfs(int x){
    if(!d[x])
        return ;
    else {
        for(int i=0;i<7;i++){
            for(int j=0;j<G[min(x, i)][max(x,i)].size();j++){
                if (G[min(x, i)][max(x,i)][j].second) {
                    G[min(x, i)][max(x,i)][j].second=0;
                    d[x]--;
                    d[i]--;
                    Dfs(i);
                    ans.push(((G[min(x, i)][max(x,i)][j].first)*(x<=i?1:-1)));
                }
            }
        }
    }
}
int Fleury(int s){
    Dfs(s);
    for(int i=0;i<7;i++){
        if (d[i])
            return 0;
    }
    return 1;
}
int main(){
    int en;
    scanf("%d",&en);
    for(int i=1;i<=en;i++){
        int tf,tt;
        scanf("%d%d",&tf,&tt);
        G[min(tf,tt)][max(tf, tt)].push_back((pii){i*((tf<=tt)?1:-1),1});
        d[tf]++;
        d[tt]++;
        
    }
    int chk=0;
    int s=0;
    for(int i=0;i<7;i++){
        if(d[i]%2){
            chk++;
            s=i;
        }
    }
    if (!d[s]) {
        for (int i=0; i<7; i++) {
            if (d[i]) {
                s=i;
                break;
            }
        }
    }
    if(chk==0||chk==2){
        if(Fleury(s)){
            while (!ans.empty()) {
                int t=ans.top();
                ans.pop();
                printf("%d %c\n",abs(t),((t>0)?'+':'-'));
            }
        }
        else
            puts("No solution");
    }
    else
        puts("No solution");
    return 0;
}