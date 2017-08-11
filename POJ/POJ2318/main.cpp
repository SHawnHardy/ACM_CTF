#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "cmath"
#include "algorithm"
#include "vector"
#include "queue"
#include "stack"
#include "set"
#include "map"
#include "iostream"
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;

const int maxn=5000+10;

const double eps=1e-7;
const double pi=acos(-1.0);

int sgn(double x) {
    if (fabs(x)<eps)    return 0;
    else                return x<0.0?-1:1;
}

inline double sqr(double x) {
    return x*x;
}
double a2r(double x) {
    return x/180*pi;
}
double r2a(double x) {
    return x/pi*180;
}

struct pt {
    double x,y;
    pt(){}
    pt(double xx,double yy) : x(xx),y(yy){}
    pt operator - () {
        return pt(0.0-x,0.0-y);
    }
    pt operator + (const pt &b) {
        return pt(x+b.x,y+b.y);
    }
    pt operator - (const pt &b) {
        return pt(x-b.x,y-b.y);
    }
    friend bool operator == (const pt &a,const pt &b) {
        return (sgn(a.x-b.x)==0) && (sgn(a.y-b.y)==0);
    }
    pt operator * (const double &c) {
        return pt(x*c,y*c);
    }
    friend pt operator * (const double &c, pt &a) {
        return pt(a.x*c,a.y*c);
    }
    pt operator / (const double &c) {
        return pt(x/c,y/c);
    }
    double dist() {
        return sqrt(sqr(x)+sqr(y));
    }
    void input() {
        scanf("%lf%lf",&x,&y);
    }
    void output() {
        printf("%f %f",x,y);
    }
    void debug() {
        printf("Debug: x:%f\ty:%f\n",x,y);
    }
};


double dot(pt a, pt b) {
    return a.x*b.x+a.y*b.y;
}
double det(pt a, pt b) {
    return a.x*b.y-a.y*b.x;
}
double dist(pt a, pt b) {
    return (a-b).dist();
}
pt rotpt(pt a, pt b, double theta) {
    return pt((a.x-b.x)*cos(theta)-(a.y-b.y)*sin(theta)+b.x,(a.x-b.x)*sin(theta)+(a.y-b.y)*cos(theta)+b.y);
}
pt rotpt(pt a, double theta) {
    return rotpt(a, pt(0.0, 0.0), theta);
}

struct ln {
    pt a,b;                //0:直线 1:a->b 2:a<-b 3:线段
    ln() {}
    ln(pt aa,pt bb) :a(aa),b(bb){}
};

bool ptOnSeg(pt p,pt s,pt t) {
    return sgn(det(p-s,t-s))==0 && sgn(dot(p-s,p-t))<=0;
}
bool ptOnSeg(pt p,ln a) {
    return ptOnSeg(p, a.a, a.b);
}
bool parallel(ln a,ln b) {
    return !sgn(det(a.a-a.b,b.a-b.b));
}
int lnMakePt(ln a,ln b,pt &rst) {
    if (parallel(a, b))
        return -1;
    double s1=det(a.a-b.a,b.b-b.a);
    double s2=det(a.b-b.a,b.b-b.a);
    rst=(s1*a.b-s2*a.a)/(s1-s2);
    int re=0;
    if (ptOnSeg(rst, a))
        re+=1;
    if (ptOnSeg(rst, b))
        re+=2;
    return re;
}

struct plg {
    vector<pt> p;
    plg(int sz=0) {
        p.resize(sz);
    }
    void debug() {
        puts("DEBUG");
        for (int i=0; i<p.size(); i++) {
            p[i].debug();
        }
    }
    double comC() {
        double re=0;
        for (int i=0; i<(p.size()-1); i++) {
            re+=dist(p[i+1],p[i]);
        }
        return re;
    }
    double comS() {
        double re=0;
        for (int i=0; i<(p.size()-1); i++) {
            re+=det(p[i+1],p[i]);
        }
        return re/2.0;
    }
};

int ptInPlg(pt pt,plg p) {
    int num=0;
    for (int i=0; i<(p.p.size()-1); i++) {
        if (ptOnSeg(pt, p.p[i], p.p[i+1]))
            return 2;
        int k=sgn(det(p.p[i+1]-p.p[i],pt-p.p[i]));
        int d1=sgn(p.p[i].y-pt.y);
        int d2=sgn(p.p[i+1].y-pt.y);
        if (k>0 && d1<=0 && d2>0)
            num++;
        if (k<0 && d2<=0 && d1>0)
            num--;
    }
    return num!=0;
}

bool makePlgcCmp(pt a,pt b) {
    return sgn(a.x-b.x)==0?(sgn(a.y-b.y)<0):(sgn(a.x-b.x)<0);
}

plg makePlgc(vector<pt> a) {
    plg re(2*(int)a.size()+5);
    sort(a.begin(), a.end(), makePlgcCmp);
    a.erase(unique(a.begin(),a.end()),a.end());
    int m=0;
    for (int i=0; i<a.size(); i++) {
        while (m>1 && sgn(det(re.p[m-1]-re.p[m-2],a[i]-re.p[m-2]))<=0) {
            m--;
        }
        re.p[m++]=a[i];
    }
    int k=m;
    for (int i=((int)a.size()-2); i>=0; i--) {
        while (m>k && sgn(det(re.p[m-1]-re.p[m-2],a[i]-re.p[m-2]))<=0) {
            m--;
        }
        re.p[m++]=a[i];
    }
    re.p.resize(m);
    return re;
}

ln L[maxn];
int ans[maxn];

int main() {
    int n,m,x1,y1,x2,y2;
    while (scanf("%d",&n),n) {
        memset(ans, 0, sizeof(ans));
        scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
        L[0].a=pt((double)x1,(double)y2);
        L[0].b=pt((double)x1,(double)y1);
        for (int i=1; i<=n; i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            L[i].a=pt((double)b,(double)y2);
            L[i].b=pt((double)a,(double)y1);
        }
        L[n+1].a=pt((double)x2,(double)y2);
        L[n+1].b=pt((double)x2,(double)y1);
        while (m--) {
            int l=0,r=(n+1);
            pt t;
            t.input();
            while ((r-l)>1) {
                int mid=(l+r)>>1;
                if (sgn(det(L[mid].b-L[mid].a,t-L[mid].a))<0)
                    l=mid;
                else
                    r=mid;
            }
            ans[l]++;
        }
        for (int i=0; i<=n; i++) {
            printf("%d: %d\n",i,ans[i]);
        }
        putchar('\n');

    }
    return 0;
}

