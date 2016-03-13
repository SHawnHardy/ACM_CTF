#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "stack"
#define FL(h) for(int j=0;j<h;j++)
#define MA(a,b) a > b ?(a):(b)
#define LL long long int
#define M 100010
using namespace std;

int in[M];
int n,q;
LL s[M];
int s1[M];

int mns(int a,int b){
    if (a>b)    return (a-b);
    else        return (b-a);
}

int main(){
    scanf("%d%d",&n,&q);
    FL(n){
        scanf("%d",in+j+1);
    }
    FL(q){
        int l,r;
        LL ans=0;
        scanf("%d%d",&l,&r);
        memset(s, 0, sizeof(s));
        memset(s1, 0, sizeof(s1));
        int top=0;
        ans=mns(in[l], in[l+1]);
        s[top]=ans;
        s1[top++]=1;
        LL last=ans;
        for (int i=l+1; i<r; i++) {
            LL t=(LL)mns(in[i], in[i+1]);
            int tn=1;
            while (t>=s[top-1]&&top) {
                int tmp=s1[--top];
                last-=s1[top]*s[top];
                tn+=tmp;
            }
            s[top]=t;
            s1[top++]=tn;
            last+=t*tn;
            ans+=last;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
