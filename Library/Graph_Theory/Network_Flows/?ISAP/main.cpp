#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "vector"
#include "queue"
using namespace std;

const int maxv=210;
const int INF=0x3f3f3f3f;

struct Edge{
    int from,to,cap,flow;
};

int st,ed;
int vn,en;
int cur[maxv];//点i的上一个弧
int dis[maxv];//点i的距离
int num[maxv];//距离为i的个数
int path[maxv];//增广路径
bool vis[maxv];

vector<int> G[maxv];
vector<Edge> E;

void add(int u,int v,int c){
    Edge in;
    in.from=u;
    in.to=v;
    in.cap=c;
    in.flow=0;
    E.push_back(in);
    G[u].push_back((int)(E.size()-1));
}
bool bfs()
{
    memset(vis, 0, sizeof(vis));
    //就是这里！！！加上就wa
    //memset(dis, (char)(0x3f), sizeof(dis));
    //memset(dis,0,sizeof(dis));
    for(int i=1;i<=vn;i++)
        dis[i]=0;
    queue<int> q;
    q.push(ed);
    vis[ed] = 1;
    dis[ed] = 0;
    while (!q.empty()) {
        int tp = q.front();
        q.pop();
        for (int i=0; i<G[tp].size(); i++) {
            Edge &te = E[G[tp][i]^1];
            //G[u][i]是反向边,管道是G[u][i]-1
            if (!vis[te.from] && te.cap>te.flow) {
                vis[te.from] = true;
                dis[te.from] = dis[tp] + 1;
                q.push(te.from);
            }
        }
    }
    return vis[st];
}

int augment(){
    int tmf=INF;
    int p=ed;
    while (p!=st) {
        int te=path[p];
        tmf=min(tmf, E[te].cap-E[te].flow);
        p=E[te].from;
    }
    p=ed;
    while (p!=st) {
        int te=path[p];
        E[te].flow+=tmf;
        E[te^1].flow-=tmf;
        p=E[te].from;
    }
    return tmf;
}


int isap(){
    //构造层次图
    int maxflow=0;
    if(!bfs()){
        //puts("W");
        return 0;
    }
    memset(num,0,sizeof(num));
    for (int i=0;i<vn;i++)
        num[dis[i]]++;
    int tp=st;
    memset(cur, 0, sizeof(cur));
    
    while (dis[st]<vn) {
        //当距离t为vn时表示s->t 之间没有增广路
        if (tp==ed) {
            //到达t，找到增广路
            maxflow+=augment();
            tp=st;
        }
        int flag=1;
        //是否需要更新dis(无有可行弧)
        for (int i=cur[tp]; i<G[tp].size(); i++) {
            Edge& te=E[G[tp][i]];
            if (te.cap>te.flow&&(dis[tp]==dis[te.to]+1)) {
                flag=0;
                path[te.to]=G[tp][i];
                cur[tp]=i;
                tp=te.to;
                break;
            }
        }
        
        if (flag) {
            int tdis=vn-1;
            for (int i=0; i<G[tp].size(); i++) {
                if (E[G[tp][i]].cap>E[G[tp][i]].flow)
                    tdis=min(tdis, dis[E[G[tp][i]].to]);
            }
            if ((--num[dis[tp]]) == 0)
                break;
            num[dis[tp]=(tdis+1)]++;
            cur[tp]=0;
            if (tp!=st)
                tp=E[path[tp]].from;
        }
    }
    return maxflow;
}






int main(){
    while(scanf("%d%d",&en,&vn)!=EOF){
        E.clear();
        for (int i=0; i<maxv; i++) {
            G[i].clear();
        }
        st=1;
        ed=vn;
        for (int i=0; i<en; i++) {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            add(u,v,c);
            add(v,u,0);
        }
        printf("%d\n",isap());
    }
    return 0;
}