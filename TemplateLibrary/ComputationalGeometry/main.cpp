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

const double eps=1e-8;
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
    bool operator == (const pt &b) {
        return (sgn(x-b.x)==0) && (sgn(y-b.y)==0);
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
    pt a,b;
    int c;                  //0:直线 1:a->b 2:a<-b 3:线段
    ln() {}
    ln(pt aa,pt bb,int cc) :a(aa),b(bb),c(cc){}
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
};

int main() {
    vector<int> vt;
    vt.push_back(0);
    vt.push_back(1);
    vt.push_back(2);
    vt.push_back(3);
    cout<<vt.size();
    cout<<vt[0]<<vt[1]<<vt[2]<<vt[3];
    vt.erase(vt.begin()+1);
    
    cout<<vt.size();
    cout<<vt[0]<<vt[1]<<vt[2]<<vt[3];
}
