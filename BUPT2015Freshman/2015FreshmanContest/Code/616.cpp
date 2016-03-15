#include "cstdio"
#include "cstdlib"
#include "cmath"
#define PI 3.1415926
using namespace std;
typedef long long int LL;
int main(){
    double r,R;
    while (scanf("%lf%lf",&r,&R)==2) {
        double t=asin(R/(R+r));
        double tans=PI/t;
        LL ans=(int)tans;
        //R/sin(p/n)>=r+R
        while (R<=(r+R)*sin((double)(PI/ans))) {
            ans++;
        }
        while (R>=(r+R)*sin((double)(PI/ans))) {
            ans--;
        }
        printf("%lld\n",ans+1);
    }
    return 0;
}