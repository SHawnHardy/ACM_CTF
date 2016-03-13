#include "cstdio"
#include "cstdlib"
#include "cstring"
#define M 110


int c,p;
int in[M];
double dp[2][M*1001];
double sum[2][M*1001];
int ts=0;


int main(){
    scanf("%d%d",&c,&p);
    for (int i=1; i<=c; i++) {
        scanf("%d",in+i);
        ts+=in[i];
    }
    for (int i=1; i<=p; i++) {
        if (i!=in[1]) {
            dp[1][i]=1.0;
        }
        dp[0][i]=0.0;
        sum[1][i]=sum[1][i-1]+dp[1][i];
        sum[0][i]=0.0;
    }
    for (int i=2; i<=c; i++) {
        sum[i&1][i-1]=0.0;
        for (int j=i; j<=p*i; j++) {
            int l=i-1,r=p*(i-1);
            if (l<j-p) {
                l=j-p;
            }
            if (r>j-1) {
                r=j-1;
            }
            if (l>r) {
                dp[i&1][j]=0.0;
            }
            else{
                dp[i&1][j]=sum[(i-1)&1][r]-sum[(i-1)&1][l-1];
                if (j-in[i]>=l&&j-in[i]<=r) {
                    dp[i&1][j]-=dp[(i-1)&1][j-in[i]];
                }
                dp[i&1][j]/=(p-1);
            }
            sum[i&1][j]=sum[i&1][j-1]+dp[i&1][j];
        }
    }
    double ans=0.0;
    for (int i=c; i<ts; i++) {
        ans+=dp[c&1][i];
    }
    printf("%.16lf",ans+1.0);
    
    return 0;
}
