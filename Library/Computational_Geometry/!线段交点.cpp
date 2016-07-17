#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "cmath"

const double eps=1e-8;
int cmp(double x){
    if (fabs(x)<eps)
        return 0;
    if (x>0)
        return 1;
    return -1;
}

inline double sqr(double x){
    return x*x;
}

struct point {
    double x,y;
    point() {}
    void input(){
        scanf("%lf %lf",&x,&y);
    }
    point(double a,double b):x(a),y(b){}
    friend point operator + (const point &a,const point &b){
        return point(a.x+b.x,a.y+b.y);
    }
    friend point operator - (const point &a,const point &b){
        return point(a.x-b.x,a.y-b.y);
    }
    friend point operator / (const point &a,const double &b){
        return point(a.x/b,a.y/b);
    }
    friend point operator * (const point &a,const double &b){
        return point(a.x*b,a.y*b);
    }
    friend point operator * (const double &a,const point &b){
        return point(b.x*a,b.y*a);
    }
};

double det(const point &a,const point &b) {
    return a.x*b.y-a.y*b.x;
}
double dot(const point &a,const point &b) {
    return a.x*b.x+a.y*b.y;
}


struct line {
    point a,b;
    line(){}
    line(point x,point y):a(x),b(y){}
};
bool parallel(line a,line b){
    return !cmp(det(a.a-a.b, b.a-b.b));
}

bool PointOnSegment(point p,point s,point t){
    return cmp(det(p-s,t-s))==0&&cmp(dot(p-s, p-t))<=0;
}

int line_make_point(line a,line b,point &res){
    if (parallel(a, b))
        return 1;
    double s1=det(a.a-b.a, b.b-b.a);
    double s2=det(a.b-b.a, b.b-b.a);
    res=(s1*a.b-s2*a.a)/(s1-s2);
    if (PointOnSegment(res, a.a, a.b))
        return 0;
    else
        return -1;
}





int main(){
    int n;
    scanf("%d",&n);
    puts("INTERSECTING LINES OUTPUT");
    while(n--){
        point a1,a2,b1,b2;
        a1.input();
        a2.input();
        b1.input();
        b2.input();
        line a(a1,a2);
        line b(b1,b2);
        point r;
        int rt=line_make_point(a, b, r);
        if (!rt) {
            printf("POINT %.2f %.2f\n",r.x,r.y);
        }
        else if(rt==-1){
            puts("NONE");
        }
        else {
            point p[4];
            int t=0;
            if(PointOnSegment(a1, b1, b2))
                p[t++]=a1;
            if(PointOnSegment(a2, b1, b2))
                p[t++]=a2;
            if(PointOnSegment(b1, a1, a2))
                p[t++]=a1;
            if(PointOnSegment(b2, a1, a2))
                p[t++]=a2;
            if (t==0) {
                if (parallel(line(a1,b1), line(a1,b2))) {
                    puts("LINE");
                }
                else
                    puts("NONE");
            }
            else {
                if (t==2&&p[0].x==p[1].x&&p[0].y==p[1].y)
                    printf("POINT %.2f %.2f\n",p[0].x,p[0].y);
                else {
                    puts("LINE");
                }
            }
        }
    }
    puts("END OF OUTPUT");
    
    return 0;
}




