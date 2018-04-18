/*
 ID: shawn_w1
 PROG: beads
 LANG: C++
 */
#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "algorithm"
using namespace std;
int dp[800][2];

int main(){
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    int N;
    char in[800];
    memset(dp, 0, sizeof(dp));
    scanf("%d",&N);
    scanf("%s",in);
    memcpy(in+strlen(in),in,strlen(in));
    int ans=0;
    for(int i=0;i<2*N;i++){
        if (in[i]=='w') {
            dp[i][0]=dp[i-1][0]+1;
            dp[i][1]=dp[i-1][1]+1;
        }
        else if(in[i]=='r'){
            dp[i][0]=dp[i-1][0]+1;
            dp[i][1]=0;
        }
        else {
            dp[i][0]=0;
            dp[i][1]=dp[i-1][1]+1;
        }
    }
    int d[2]={0};
    for(int i=(2*N-1);i>0;i--){
        if (in[i]=='w') {
            d[0]=d[0]+1;
            d[1]=d[1]+1;
        }
        else if(in[i]=='r'){
            d[0]=d[0]+1;
            d[1]=0;
        }
        else {
            d[0]=0;
            d[1]=d[1]+1;
        }
        ans=max(ans,dp[i-1][1]+d[0]);
        ans=max(ans,dp[i-1][0]+d[1]);
    }
    printf("%d\n",min(ans, N));
    return 0;
}