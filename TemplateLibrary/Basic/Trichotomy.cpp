#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "cmath"
#include "ctime"
#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "queue"
#include "stack"
#include "set"
#include "map"

using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<int,string> pis;

const int maxn=10010;
const double eps=1e-8;
const double gd=(sqrt(5.0)-1.0)/2.0;

double func(double x) {
    return x;
}


int main() {
    double l=0,r=maxn;
    double ml=l*gd+r*(1-gd);
    double mr=l*(1-gd)+r*gd;
    double fml=func(ml);
    double fmr=func(mr);
    double ans=max(fml,fmr);
    while((r-l)>eps) {
        if ((fml-fmr)<0) {
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
    ans=max(ans,func(ml));
    ans=max(ans,func(mr));
    printf("%f\n",ans);
    return 0;
}
