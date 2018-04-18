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

const int MAXN=20+10;
const double eps=1e-6;

int sgn(double x) {
    return fabs(x)<eps?0:(x<0.0?-1:1);
}

struct pt {
    double x,y;
    pt() {}
    pt(double xx,double yy): x(xx),y(yy) {}
    void input() {
        scanf("%lf%lf",&x,&y);
    }
    pt operator + (const pt &a) {
        return pt(x+a.x,y+a.y);
    }
    pt operator - (const pt &a) {
        return pt(x-a.x,y-a.y);
    }
    bool operator == (const pt &a) {
        return sgn(x-a.x)==0 && sgn(y-a.y)==0;
    }
    pt operator * (const double &c) {
        return pt(x*c,y*c);
    }
    friend pt operator * (const double &c,const pt &p) {
        return pt(p.x*c,p.y*c);
    }
    pt operator / (const double &c) {
        return pt(x/c,y/c);
    }
    
    double dist() {
        return sqrt(x*x+y*y);
    }
    pt unit() {
        return *this/(this->dist());
    }
};
double dot(pt a,pt b) {
    return a.x*b.x+a.y*b.y;
}
double det(pt a,pt b) {
    return a.x*b.y-a.y*b.x;
}

bool parallel(pt aa,pt ab,pt ba,pt bb) {
    return !sgn(det(aa-ab,ba-bb));
}
bool collineation(pt aa,pt ab,pt ba,pt bb) {
    return parallel(aa, ab, ba, bb) && parallel(aa, ab, ba, ab);
}

int n;
char in[MAXN][MAXN];

pt Tri[3];

int mv[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

bool chk(int x,int y) {
    return x>=0 && x<n && y>=0 && y<n && (in[n-1-y][x]!='#');
}

bool ptOn (pt p,pt s,pt t) {
    return (sgn(det(p-s,t-s))==0) && (sgn(dot(p-s,p-t))<=0);
}

bool scs(pt aa,pt ab,pt ba,pt bb) {
    return
    sgn(det(ba-aa,ab-aa))*sgn(det(bb-aa,ab-aa)) <= 0 &&
    sgn(det(aa-ba,bb-ba))*sgn(det(ab-ba,bb-ba)) <= 0;
}
bool scsS(pt aa,pt ab,pt ba,pt bb) {
    return
    sgn(det(ba-aa,ab-aa))*sgn(det(bb-aa,ab-aa)) < 0 &&
    sgn(det(aa-ba,bb-ba))*sgn(det(ab-ba,bb-ba)) < 0;
}
int ptInPlg (pt t) {
    int num=0;
    for (int i=0; i<3; i++) {
        if (ptOn(t, Tri[i], Tri[(i+1)%3]))
            return 2;
        int k=sgn(det(Tri[(i+1)%3]-Tri[i],t-Tri[i]));
        int d1=sgn(Tri[i].y-t.y);
        int d2=sgn(Tri[(i+1)%3].y-t.y);
        if (k>0 && d1<=0 && d2>0)
            num++;
        if (k<0 && d2<=0 && d1>0)
            num--;
    }
    return num!=0;
}
pt lnMakePt(pt aa,pt ab,pt ba, pt bb) {
    double s1=det(aa-ba,bb-ba);
    double s2=det(ab-ba,bb-ba);
    return (s1*ab-s2*aa)/(s1-s2);
}

bool chk2(int ax,int ay,int bx,int by) {
    pt pa=pt((double)ax,(double)ay);
    pt pb=pt((double)bx,(double)by);
    int cpa=ptInPlg(pa);
    int cpb=ptInPlg(pb);
    
    if (cpa==1||cpb==1)
        return false;
        
    for (int i=0; i<3; i++) {
        if (collineation(pa, pb, Tri[i], Tri[(i+1)%3]))
            return true;
    }
    
    int cnt=0;
    pt p;
    for (int i=0; i<3; i++) {
        if (scs(pa,pb,Tri[i],Tri[(i+1)%3])) {
            pt tmp=lnMakePt(pa, pb, Tri[i], Tri[(i+1)%3]);
            if (cnt==0) {
                p=tmp;
                cnt++;
                continue;
            }
            if (cnt && !(tmp==p))
                return false;
            
        }
    }
    
    return true;
}




vector<int> G[MAXN*MAXN];
int z2n(int x,int y) {
    return x+n*y;
}
bool vis[MAXN*MAXN];
int sol() {
    memset(vis,0,sizeof(vis));
    
    queue<pii> q;
    q.push(mp(0,0));
    vis[n*n-n]=true;
    while (!q.empty()) {
        pii t=q.front();
        q.pop();
        for (int i=0; i<G[t.fi].size(); i++) {
            if (vis[G[t.fi][i]])
                continue;
            if (G[t.fi][i]==(n*n-1))
                return t.se+1;
            q.push(mp(G[t.fi][i],t.se+1));
            vis[G[t.fi][i]]=true;
        }
    }
    return -1;
}


int main() {
    while (~scanf("%d",&n)) {
        for (int i=0; i<(n*n); i++)
            G[i].clear();
        
        for (int i=0; i<3; i++) {
            Tri[i].input();
        }
        for (int i=0; i<n; i++) {
            scanf("%s",in[i]);
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (!chk(i,j))
                    continue;
                
                for (int k=0; k<8; k++) {
                    if (chk(i+mv[k][0],j+mv[k][1])) {
                        if (chk2(i,j,i+mv[k][0],j+mv[k][1])) {
                            G[z2n(i,j)].push_back(z2n(i+mv[k][0],j+mv[k][1]));
                        }
                    }
                }
            }
        }
        
        printf("%d\n",sol());
    }
    return 0;
}
