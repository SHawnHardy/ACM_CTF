#include "cstdio"
#include "cstdlib"
#include "queue"
#define INF 500
using namespace std;
queue<int> q;
int V,E;
bool G[410][410]={0};
int val[410]={0};
int BFS(bool flag);

int main(){
    //init
    int ans=0;
    scanf("%d%d",&V,&E);
    int f,t;
    while (E--) {
        scanf("%d%d",&f,&t);
        G[f][t]=true;
        G[t][f]=true;
    }
    if(G[1][V]) ans=BFS(false);
    else        ans=BFS(true);
    if (ans==INF) {
        printf("-1");
        return 0;
    }
    printf("%d",ans);
    return 0;
}
bool chk(int f,int t,bool fg){
    if (fg&&G[f][t]) return true;
    else if((!fg)&&(!G[f][t])) return true;
    else    return false;
}
int BFS(bool flag){
    for (int i=1; i<=V; i++) {
        val[i]=INF;
    }
    q.push(1);
    val[1]=0;
    while (!q.empty()) {
        int n=q.front();
        q.pop();
        for (int i=1; i<=V; i++) {
            if (i==n) continue;
            if (chk(n, i, flag)) {
                if (val[i]==INF) {
                    q.push(i);
                    val[i]=val[n]+1;
                }
            }
            
        }
    }
    return val[V];
    
}
