#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "cmath"
#include "algorithm"
#include "string"
#include "vector"
#include "queue"
#include "stack"
#include "set"
#include "map"
#include "iostream"
#include "complex"

#define pb push_back
#define fi first
#define se second
#define dbg(...) cerr<< "[" << #__VA_ARGS__ ":" << (__VA_ARGS__) << "]" <<endl;

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;

const int MAXN=100010;

int n,m;
int tar[MAXN];
pii Q[MAXN];

int main() {
    int T;
    scanf("%d",&T);
    for (int cas=1; cas<=T; cas++) {
        scanf("%d%d",&n,&m);
        for (int i=0; i<n; i++) {
            scanf("%d %d",&Q[i].fi,&Q[i].se);
        }
        for (int i=0; i<m; i++) {
            scanf("%d",&tar[i]);
        }
        sort(Q,Q+n);
        sort(tar,tar+m);
        int ans=0;
        priority_queue<int, vector<int>, greater<int> > q;
        for (int i=0,j=0; i<m; i++) {
            while (j<n&&Q[j].fi<=tar[i])
                q.push(Q[j++].se);
            while (!q.empty()&&q.top()<tar[i])
                q.pop();
            if (q.empty()) {
                ans=-1;
                break;
            }
            ans=max(ans,n-(int)q.size());
            q.pop();
        }
        if (ans==-1)
            printf("Case #%d: IMPOSSIBLE!\n", cas);
        else
            printf("Case #%d: %d\n", cas, ans + 1);
        
    }
    return 0;
}
