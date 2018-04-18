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
#define mp(a,b) make_pair(a,b)

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;

const int MAXN=1000+10;

int gcd(int x,int y) {
    return x%y==0?y:gcd(y,x%y);
}
int n;

int mv[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

int input[MAXN][2];
set<pii> st;
bool chk(int x,int y) {
    return x>=0 && x<n && y>=0 && y<n && (st.find(mp(x,y))==st.end());
}

int main() {
    int T;
    scanf("%d",&T);
    for (int cas=1; cas<=T; cas++) {
        int k;
        scanf("%d%d",&n,&k);
        st.clear();
        int ansq=5*n*n-4*n;
        int ansp=(1+n)*n*5/2-2-2*n;
        for (int i=0; i<k; i++) {
            scanf("%d%d",&input[i][0],&input[i][1]);
            st.insert(mp(input[i][0],input[i][1]));
        }
        for (int i=0; i<k; i++) {
            int x=input[i][0],y=input[i][1];
            for (int j=0; j<4; j++) {
                if (chk(x+mv[j][0],y+mv[j][1])) {
                    ansq--;
                    if ((x+mv[j][0]+y+mv[j][1])>=(n-1))
                        ansp--;
                }
            }
            int d=5;
            if (x==0 || x==(n-1)) {
                d--;
            }
            if (y==0 || y==(n-1)) {
                d--;
            }
            ansq-=d;
            if ((x+y)>=(n-1))
                ansp-=d;
        }
        int d=gcd(ansp,ansq);
        printf("Case #%d: %d/%d\n",cas,ansp/d,ansq/d);
        
    }
    return 0;
}
