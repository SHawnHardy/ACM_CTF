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

const int maxn=20000+10;

const double eps=1e-10;
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
double dist(pt a, ln l) {
    return fabs(det(l.a-a,l.b-a)/dist(l.a,l.b));
}
double ptSegDist(pt a, ln l) {
    pt mid=(l.a+l.b)/2.0;
    if (sgn(det(mid-a,l.a-a)*det(mid-a,l.b-a))<=0)
        return dist(a,l);
    else {
        double re1=dist(a,l.a);
        double re2=dist(a,l.b);
        return sgn(re1-re2)<0?re1:re2;
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

pt en[maxn];
ln w[maxn];
ln seg[maxn];
pt Q;

struct nd {
    double arg;
    int type;
    int num;
    friend bool operator < (const nd &a,const nd &b) {
        return sgn(a.arg-b.arg)==0?a.type>b.type:sgn(a.arg-b.arg)<0;
    }
};

nd c[maxn*3];
int top=0;



double targ;
struct cmp{
    bool operator()(ln a, ln b) {
        ln ls(pt(0,0),pt(cos(targ),sin(targ)));
        if (sgn(lnMakePt(ls, a).dist()-lnMakePt(ls, b).dist())<0)
            return true;
        else
            return false;
    }
};
//bool cmp(const ln a,const ln b) {
//    ln ls(pt(0,0),pt(cos(targ),sin(targ)));
//    if (sgn(lnMakePt(ls, a).dist()-lnMakePt(ls, b).dist())<0)
//        return true;
//    else
//        return false;
//}

set<ln,cmp> st;


int main() {
//        freopen("1003.in", "r", stdin);
    int n,m,q;
    int cas=0;
    while (scanf("%d%d%d",&n,&m,&q)!=EOF) {
        cas++;
        for (int i=0; i<n; i++)
            en[i].input();
        for (int i=0; i<m; i++) {
            w[i].a.input();
            w[i].b.input();
        }
        printf("Case #%d:\n",cas);
        while(q--) {
            Q.input();
            top=0;
            for (int i=0; i<n; i++) {
                c[top].arg=(en[i]-Q).arg();
                c[top].type=0;
                c[top++].num=i;
            }
            int mm=m;
            for (int i=0; i<m; i++) {
                seg[i]=ln(w[i].a-Q,w[i].b-Q);
                
                if (sgn(seg[i].a.arg()-seg[i].b.arg())>0)
                    swap(seg[i].a,seg[i].b);
                if (sgn(seg[i].b.arg()-seg[i].a.arg()-pi)>0) {
                    c[top].arg=seg[i].b.arg();
                    c[top].type=1;
                    c[top++].num=i;
                    c[top].arg=pi;
                    c[top].type=-1;
                    c[top++].num=i;
                    c[top].arg=-pi;
                    c[top].type=1;
                    c[top++].num=i;
                    c[top].arg=seg[i].a.arg();
                    c[top].type=-1;
                    c[top++].num=i;
                }
                else {
                    c[top].arg=seg[i].b.arg();
                    c[top].type=-1;
                    c[top++].num=i;
                    c[top].arg=seg[i].a.arg();
                    c[top].type=1;
                    c[top++].num=i;
                }
            }
            sort(c,c+top);
//            for (int i=0; i<top; i++) {
//                printf("%f %d %d\n",c[i].arg,c[i].type,c[i].num);
//            }
            int ans=0;
            st.clear();
            for (int i=0; i<top; i++) {
                targ=c[i].arg;
                if (c[i].type!=0) {
                    if (c[i].type>0)
                        st.insert(seg[c[i].num]);
                    else {
                        st.erase(seg[c[i].num]);
                    }
                }
                else {
                    ln ls(pt(0,0),en[c[i].num]-Q);
                    if (st.empty()||(!segCrossSeg(ls, *st.begin())))
                        ans++;
                }
            }
            printf("%d\n",ans);
        }
        
    }
    return 0;
}
