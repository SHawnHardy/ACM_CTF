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

const double gd=(sqrt(5)-1)/2;

const int maxn=200+10;

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
        printf("%.4f %.4f",x,y);
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

ln mvLn(ln l, double len) {
    pt p=l.b-l.a;
    p=p/p.dist();
    p=rotPt(p,pi/2.0);
    return ln(l.a+p*len,l.b+p*len);
}

bool ptOnSeg(pt p,pt s,pt t) {
    return (sgn(det(p-s,t-s))==0) && (sgn(dot(p-s,p-t))<=0);
}
bool ptOnSeg(pt p,ln a) {
    return ptOnSeg(p, a.a, a.b);
}
double ptLnDist(pt a, ln l) {
    return fabs(det(l.a-a,l.b-a)/dist(l.a,l.b));
}
double ptSegDist(pt p, ln l) {
    if (sgn(dot(p-l.a,l.b-l.a))<=0)
        return dist(p,l.a);
    else if (sgn(dot(p-l.a,l.b-l.a)-sqr(dist(l.a,l.b)))>=0)
        return dist(p,l.b);
    else {
        return ptLnDist(p,l);
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
    void input() {
        o.input();
        scanf("%lf",&r);
    }
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
    double comD(int &fst,int &scd) {
        double re=0.0;
        int n=(int)p.size()-1;
        if (p.size()==2) {
            fst=0,scd=1;
            return re;
        }
        
        for (int i=0,j=1; i<n; i++) {
            while (sgn(det(p[(i+1)%n]-p[i],p[j]-p[i])-det(p[(i+1)%n]-p[i],p[(j+1)%n]-p[i]))<0)
                j=(j+1)%n;
            double d=dist(p[i],p[j]);
            if (d>re) {
                re=d;
                fst=i;
                scd=j;
            }
            d=dist(p[(i+1)%n],p[(j+1)%n]);
            if (d>re) {
                re=d;
                fst=i;
                scd=j;
            }
        }
        return re;
    }
};

int ptInPlg(pt t,plg p) {
    int num=0;
    for (int i=0; i<(p.p.size()-1); i++) {
        if (ptOnSeg(t, p.p[i], p.p[i+1]))
            return 2;
        int k=sgn(det(p.p[i+1]-p.p[i],t-p.p[i]));
        int d1=sgn(p.p[i].y-t.y);
        int d2=sgn(p.p[i+1].y-t.y);
        if (k>0 && d1<=0 && d2>0)
            num++;
        if (k<0 && d2<=0 && d1>0)
            num--;
    }
    return num!=0;
}
int ptInPlgc(pt t,plg p) {
    //todo
    return 0;
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
    hp(ln l): s(l.a),t(l.b){}
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
        if (parallel(ln(q.back().s,q.back().t), ln(v[i].s,v[i].t))) {
            re.resize(0);
            return vector<pt>(re.begin(),re.end());
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
    else {
        if (parallel(ln(q.back().s,q.back().t),ln(q.front().s,q.front().t))) {
            re.resize(0);
            return vector<pt>(re.begin(),re.end());
        }
        re.push_back(lnMakePt(ln(q.back().s,q.back().t),ln(q.front().s,q.front().t)));
    }
    return vector<pt>(re.begin(),re.end());
}

pt triMassCenter(pt a,pt b,pt c) {
    return (a+b+c)/3;
}
pt triCircumCenter(pt a,pt b,pt c) {
    pt re;
    double a1=b.x-a.x,b1=b.y-a.y,c1=(sqr(a1)+sqr(b1))/2;
    double a2=c.x-a.x,b2=c.y-a.y,c2=(sqr(a2)+sqr(b2))/2;
    double d=a1*b2-a2*b1;
    re.x=a.x+(c1*b2-c2*b1)/d;
    re.y=a.y+(a1*c2-a2*c1)/d;
    return re;
}
pt triOrthoCenter(pt a,pt b,pt c) {
    return triMassCenter(a, b, c)*3.0-triCircumCenter(a,b,c)*2.0;
}
pt triInnerCenter(pt a,pt b,pt c) {
    pt re;
    double la,lb,lc;
    la=(b-c).dist();
    lb=(c-a).dist();
    lc=(a-b).dist();
    re.x=(la*a.x+lb*b.x+lc*c.x)/(la+lb+lc);
    re.y=(la*a.y+lb*b.y+lc*c.y)/(la+lb+lc);
    return re;
}

 
int n;
vector<cc> C;
double theta[maxn*3];
int top=0;

double cal(cc c,double theta) {
    pt t=pt(cos(theta),sin(theta));
    t=rotPt(t,-c.o.arg());
    theta=t.arg();
    c.o=rotPt(c.o,-normRad(c.o.arg()));
    double d=c.o.dist();
    if (fabs(theta)>asin(c.r/d))
        return 0.0;
    else {
        return 2*(sqrt(sqr(c.r)-sqr(d*sin(theta))));
    }
}
double func(double theta) {
//    printf("%f\n",theta);
    double re=0;
    for (int i=0; i<n; i++) {
        re+=cal(C[i],theta);
//        printf("\t%f\n",re);
    }
    return re;
}


void sol() {
    top=0;
    for (int i=0; i<n; i++) {
        theta[top++]=C[i].o.arg();
        double alpha=asin(C[i].r/C[i].o.dist());
        double beta=C[i].o.arg();
        if (sgn(beta+alpha-pi)>0) {
            theta[top++]=beta+alpha-2*pi;
        }
        else {
            theta[top++]=beta+alpha;
        }
        
        if (sgn(beta-alpha+pi)<0) {
            theta[top++]=beta-alpha+2*pi;
        }
        else {
            theta[top++]=beta-alpha;
        }
    }
    theta[top++]=pi;
    theta[top++]=-pi;    
    sort(theta,theta+top);

    double ans=0;
    for (int i=0; i<top; i++) {
        double l=theta[i];
        double r=theta[(i+1)%top];
        if (sgn(l-r)>0)
            swap(l,r);
        double ml=l*gd+r*(1-gd);
        double mr=l*(1-gd)+r*gd;
        double fml=func(ml);
        double fmr=func(mr);
        ans=max(ans,func(l));
        ans=max(ans,func(r));
//        printf("%f %f\n",l,r);
        while(sgn(r-l)){
            if (sgn(fml-fmr)<0) {
                l=ml;
                ml=mr;
                fml=fmr;
                mr=l*(1-gd)+r*gd;
                fmr=func(mr);
            }
            else {
                r=mr;
                mr=ml;
                fmr=fml;
                ml=l*gd+r*(1-gd);
                fml=func(ml);
            }
        }
//        printf("\t%f %f\n",ml,fml);
        ans=max(ans,fml);
        ans=max(ans,fmr);
    }
    printf("%.10f\n",ans);
}



int main() {
    while(scanf("%d",&n)!=EOF) {
        C.resize(n);
        for (int i=0; i<n; i++) {
            C[i].o.input();
            scanf("%lf",&C[i].r);
        }
//        printf("%f\n",cal(cc(pt(50,0),10),0));
        sol();
    }
    return 0;
}
