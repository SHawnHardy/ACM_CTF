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

const int maxn=100000+10;

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
double normRad(double x) {
    if (sgn(x)<0) {
        double tx=fabs(x);
        ll fix=ceil(tx/pi/2.0);
        x+=(fix)*(pi*2.0);
    }
    else {
        ll fix=floor(x/pi/2.0);
        x-=(fix)*(pi*2.0);
    }
    if (sgn(pi*2.0-x)==0)
        x=0.0;
    return x;
}
double radSub(double a,double b) {
    a=normRad(a);
    b=normRad(b);
    if (sgn(a-b)>=0)
        return a-b;
    else {
        return 2.0*pi-b+a;
    }
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
        printf("(%.0f,%.0f)\n",x,y);
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
    void input() {
        a.input();
        b.input();
    }
    void output() {
        a.output();
        b.output();
        putchar('\n');
    }
};

bool ptOnSeg(pt p,pt s,pt t) {
    return (sgn(det(p-s,t-s))==0) && (sgn(dot(p-s,p-t))<=0);
}
bool ptOnSeg(pt p,ln a) {
    return ptOnSeg(p, a.a, a.b);
}
bool parallel(ln a,ln b) {
    return !sgn(det(a.a-a.b,b.a-b.b));
}
bool collineation(ln a,ln b) {
    return (parallel(a, b)&&parallel(a,ln(b.a,a.b)));
}
bool lnCrossSeg(ln l,ln s) {
    return sgn(det(l.b-l.a,s.a-l.a)*det(l.b-l.a,s.b-l.a))<=0;
}
bool segCrossSeg(ln a,ln b) {
    return 
        max(a.a.x,a.b.x) >= min(b.a.x,b.b.x) &&
        max(b.a.x,b.b.x) >= min(a.a.x,a.b.x) &&
        max(a.a.y,a.b.y) >= min(b.a.y,b.b.y) &&
        max(b.a.y,b.b.y) >= min(a.a.y,a.b.y) &&
        sgn(det((b.a-a.a),(a.b-a.a)))*sgn(det((b.b-a.a),(a.b-a.a))) <= 0 &&
        sgn(det((a.a-b.a),(b.b-b.a)))*sgn(det((a.b-b.a),(b.b-b.a))) <= 0;
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
bool cmp(pt a,pt b) {
    return normRad(atan2(a.y,a.x))<normRad(atan2(b.y,b.x));
}

vector<pt> P;

void sol() {
    sort(P.begin(),P.end(),cmp);
    for (int i=0; i<P.size(); i++) {
        pt ds=P[i],nx=P[(i+1)%P.size()];
        if (radSub(atan2(nx.y,nx.x),atan2(ds.y,ds.x))>=pi) {
            pt(0,0).output();
            int f=(i+1)%P.size();
            for (int j=0; j<P.size(); j++) {
                P[f].output();
                f=(f+1)%P.size();
            }
            return ;
        }
    }
}

int main() {
    double tx,ty;
    scanf("%lf %lf",&tx,&ty);
    while (~scanf("%lf %lf",&tx,&ty)) {
        P.push_back(pt(tx,ty));
    }
    sol();
    return 0;
}
