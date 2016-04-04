#include "cstdio"
#include "cstdlib"
double p[100010];

int main()
{
    int  n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int t=(r/m-l/m);
        if(l%m==0)  t++;
        p[i]=1.0-(double)t/(r-l+1);
    }
    double ans=0;
    for(int i=0;i<(n-1);i++)
    {
        ans+=(1-p[i]*p[i+1])*2000;
    }
    ans+=(1-p[n-1]*p[0])*2000;
    printf("%lf\n",ans);
    return 0;
}
