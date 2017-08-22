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

pt rotpt(pt a, pt b, double theta) {
    return pt((a.x-b.x)*cos(theta)-(a.y-b.y)*sin(theta)+b.x,(a.x-b.x)*sin(theta)+(a.y-b.y)*cos(theta)+b.y);
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
        a=rotpt(a,o,theta);
        b=rotpt(b,o,theta);
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
};

pt P[maxn];
double k[maxn];

int main() {
    int n;
    while(scanf("%d",&n)!=EOF) {
        for (int i=0; i<n; i++) {
            P[i].input();
            scanf("%lf",&k[i]);
        }
        P[n]=P[0];
        
        ln ls(pt(0,0),pt(0,0));
        ls.b.input();
        double pwr=10000;
        int ans=0;
        int lm=-1;
        while(sgn(pwr-1.0)>=0) {
            ans++;
            for (int i=0; i<n; i++) {
                if (lnCrossSeg(ls,ln(P[i],P[i+1]))) {
                    if (lm==-1) {
                        pt rst=lnMakePt(ls, ln(P[i],P[i+1]));
                        if (rst==ls.b)
                            ls.b=(ls.a+ls.b)/2.0;
                        if (sgn(dot(rst-ls.a,ls.b-ls.a)<0)) {
                            lm=i;
                            continue;
                        }
                    }
                    else if (i==lm)
                        continue;
                
                    lm=i;
                    pt rst;
                    pt lna=P[i];
                    pt lnb=P[i+1];
                    if (sgn(radSub(lnb.arg(),lna.arg())-pi)>0) {
                        swap(lna,lnb);
                    }
                
                    lnMakePt(ls,ln(P[i],P[i+1]),rst);
                
                
                    if (rst==P[i]||rst==P[i+1]) {
                        pwr=0.0;
                    }
                    else {
                        pwr*=k[i];
                        double an=includedAngle(ls, ln(lna,lnb));
                        double da=includedAngle(rst, lna, ls.a);
                        if (sgn(da-an)==0) {
                            ls.rot(rst,-(pi-2*an));
                        }
                        else {
                            ls.rot(rst,pi-2*an);
                        }
                        ls.b=ls.b+rst-ls.a;
                        ls.a=rst;
                    } 
                    break;
                }
            }
        }
    printf("%d\n",ans);
    }
    return 0;
}
