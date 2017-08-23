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
#include "complex"
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;

const int maxn=100+10;

const double eps=1e-7;
const double pi=acos(-1.0);

int sgn(double x) {
    if (fabs(x)<eps)    return 0;
    else                return x<0.0?-1:1;
}

inline double sqr(double x) {
    return x*x;
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
    double arg() {
        return atan2(y,x);
    }
    void input() {
        scanf("%lf%lf",&x,&y);
    }
    void output() {
        debug();
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

pt rotPt(pt a, pt b, double theta) {
    return pt((a.x-b.x)*cos(theta)-(a.y-b.y)*sin(theta)+b.x,(a.x-b.x)*sin(theta)+(a.y-b.y)*cos(theta)+b.y);
}
pt rotPt(pt a, double theta) {
    return rotPt(a, pt(0.0,0.0), theta);
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
    void rot(pt o,double theta) {
        a=rotPt(a,o,theta);
        b=rotPt(b,o,theta);
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

pt lnMakePt(ln a,ln b) {
    double s1=det(a.a-b.a,b.b-b.a);
    double s2=det(a.b-b.a,b.b-b.a);
    return (s1*a.b-s2*a.a)/(s1-s2);
}

double includedAngle(ln a, ln b) {
    double re=normRad(dot(a.b-a.a,b.b-b.a)/dist(a.a,a.b)/dist(b.a,b.b));
    if (sgn(re-pi)>0)
        re-=pi;
    return re;
}
double includedAngle(pt a, pt o, pt b) {
    double re=radSub((a-o).arg(), (b-o).arg());
    if (sgn(re-pi)>0)
        re=2*pi-re;
    return re;
}

double detAngel(pt o, pt s, pt t) {
    double re=includedAngle(s, o, t);
    if (sgn(normRad((t-o).arg())-normRad((s-o).arg()))<0)
        return -re;
    else
        return re;
}

struct cc {
    pt o;
    double r;
    cc() {}
    cc(pt oo, double rr): o(oo),r(rr){}
};

pair<pt,pt> ccCrossCc(cc a, cc b) {
    double dis=dist(a.o, b.o);
    double cost=(sqr(a.r)+sqr(dis)-sqr(b.r))/(2.0*a.r*dis);
    pair<pt, pt> re;
    re.first=rotPt(b.o-a.o, acos(cost))/((b.o-a.o).dist())*a.r+a.o;
    re.second=rotPt(b.o-a.o, -acos(cost))/((b.o-a.o).dist())*a.r+a.o;
    return re;
}

int ptInCc (pt p, cc c) {
    int rst=sgn(c.r-dist(p,c.o));
    return rst==0?1:(rst==1?2:0);
}

pt P[maxn];
pt D[maxn];
int V[maxn];
int n,m;

bool chk(double t) {
    for (int i=0; i<n; i++) {
        for (int j=(i+1); j<n; j++) {
            if (sgn(dist(P[i]+(t*(double)V[i])*D[i],P[j]+(t*(double)V[j])*D[j])-t*(double)m*2.0)>0)
                continue;
            pair<pt, pt> jd=ccCrossCc(cc(P[i]+(t*(double)V[i])*D[i],t*(double)m), cc(P[j]+(t*(double)V[j])*D[j],t*(double)m));
            bool f1=false;
            bool f2=false;
            for (int k=0; k<n; k++) {
                if (k==i||k==j)
                    continue;
                if (ptInCc(jd.first, cc(P[k]+(t*(double)V[k])*D[k], t*(double)m))==0)
                    f1=true;
                if (ptInCc(jd.second, cc(P[k]+(t*(double)V[k])*D[k], t*(double)m))==0)
                    f2=true;
                if (f1&&f2)
                    break;
            }
            if (!(f1&&f2))
                return true;
        }
    }
    return false;
}


int main() {
//    pair<pt,pt> tst=ccCrossCc(cc(pt(-1,0),1), cc(pt(1,0),1));
//    tst.first.debug();
//    tst.second.debug();
    while (scanf("%d%d",&n,&m)!=EOF) {
        for (int i=0; i<n; i++) {
            P[i].input();
            D[i].input();
            D[i]=(D[i]/(D[i].dist()));
            scanf("%d",&V[i]);
        }
        double l=0.0;
        double r=200.0;
        while(sgn(r-l-1e-6)==1) {
            double mid=(l+r)/2.0;
            if (chk(mid)) {
                r=mid;
            }
            else {
                l=mid;
            }
        }
        printf("%.4f\n",r);
    }
    return 0;
}
