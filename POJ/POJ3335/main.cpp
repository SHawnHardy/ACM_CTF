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
    double arg() {
        return atan2(y,x);
    }
    void input() {
        scanf("%lf%lf",&x,&y);
    }
    void output() {
        printf("%f %f\n",x,y);
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
    return rotPt(a, pt(0.0, 0.0), theta);
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
double dist(pt a, ln l) {
    return fabs(det(l.a-a,l.b-a)/dist(l.a,l.b));
}
double ptSegDist(pt p, ln l) {
    if (sgn(dot(p-l.a,l.b-l.a))<=0)
        return dist(p,l.a);
    else if (sgn(dot(p-l.a,l.b-l.a)-sqr(dist(l.a,l.b)))>=0)
        return dist(p,l.b);
    else {
        return dist(p,l);
    }
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

struct plg {
    vector<pt> p;
    plg(int sz=0) {
        p.resize(sz);
    }
    plg(vector<pt> pp) {
        p=pp;
        p.erase(unique(p.begin(),p.end()),p.end());
        p.push_back(p[0]);
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
            re+=det(p[i],p[i+1]);
        }
        return re/2.0;
    }
    //TODO
    double comD(pt &fst,pt &scd) {
        return 0.0;
    }
    //TODO
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

struct hp {
    pt s,t;
    hp(){};
    hp(pt ss, pt tt): s(ss),t(tt){}
    void input() {
        s.input();
        t.input();
    }
};


bool ptInHp(pt p, hp h) {
    return sgn(det(h.t-h.s,p-h.s))>=0;
}

bool hpInterCmp(hp a,hp b) {
    int rst=sgn((a.t-a.s).arg()-(b.t-b.s).arg());
    return rst==0?ptInHp(a.s, b):rst<0;
}
bool hpUniqueCmp(hp a,hp b) {
    return sgn((a.t-a.s).arg()-(b.t-b.s).arg())==0;
}

vector<pt> hpInter(vector<hp> v) {
    sort(v.begin(),v.end(),hpInterCmp);
    v.erase(unique(v.begin(),v.end(),hpUniqueCmp),v.end());
    deque<hp> q;
    deque<pt> re;
    q.push_back(v[0]);
    for (int i=1; i<(int)v.size(); i++) {
        if (sgn((v[i].t-v[i].s).arg()-(v[i-1].t-v[i-1].s).arg())==0)
            continue;
        while (re.size()>0 && !(ptInHp(re.back(), v[i]))) {
            re.pop_back();
            q.pop_back();
        }
        while (re.size()>0 && !(ptInHp(re.front(), v[i]))) {
            re.pop_front();
            q.pop_front();
        }
        re.push_back(lnMakePt(ln(q.back().s,q.back().t), ln(v[i].s,v[i].t)));
        q.push_back(v[i]);
    }
    while (re.size()>0 && !(ptInHp(re.back(), q.front()))) {
        re.pop_back();
        q.pop_back();
    }
    while (re.size()>0 && !(ptInHp(re.front(), q.back()))) {
        re.pop_front();
        q.pop_front();
    }
    if (q.size()<=2)
        re.resize(0);
    else
        re.push_back(lnMakePt(ln(q.back().s,q.back().t),ln(q.front().s,q.front().t)));
    return vector<pt>(re.begin(),re.end());
}

vector<hp> H;
vector<pt> P;

int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        P.resize(n);
        H.resize(n);
        for (int i=0; i<n; i++)
            P[i].input();
        for (int i=0; i<n; i++) {
            H[i].s=P[i];
            H[i].t=P[(i-1+n)%n];
        }
        vector<pt> rst=hpInter(H);
        if (rst.empty())
            puts("NO");
        else
            puts("YES");
    }
    return 0;
}
