#include <stdio.h>
#include <stdlib.h>//

int in[100100][2]={0};
int chk(int l,int a,int b,int no,int ts,int ta){//1 3 2 1 2
    if (l==-1) {
        if (a<b) {
            return no+ts;
        }
        else{
            return ts+ta;
        }
    }
    else{
        if (a>b) {
            return no+ts;
        }
        else{
            return ts+ta;
        }
    }
    
}

int main(){
    int n=0;
    int ans=-1;
    int now=-1;
    int l=0;
    
    scanf("%d",&n);
    if (n==1) {
        printf("1");
        return 0;
    }
    int p=0;
    scanf("%d",&in[0][0]);
    in[0][1]++;
    n--;
    int t=0;
    while (n--) {
        scanf("%d",&t);
        if (!n) {
            if (in[p][0]==t){
                in[p][1]++;
                if (p==0) {
                    ans=in[p][1];
                }
                else if(p==1){
                    ans=in[p][1]+in[p-1][1];
                }
                else{
                    now=chk(l, in[p-1][0],in[p][0], now, in[p][1], in[p-1][1]);
                    if (now>ans) ans=now;
                }
            }
            else{
                if (p==0) {
                    ans=in[p][1]+1;
                }
                else if(p==1){
                    now=in[p][1]+in[p-1][1];
                    if (in[p][0]>in[p-1][0])    l=1;
                    else                        l=-1;
                    if (now>ans) ans=now;
                    now=chk(l, in[p][0],t, now, 1, in[p][1]);
                    if (now>ans) ans=now;
                    
                    
                }
                else{
                    now=chk(l, in[p-1][0], in[p][0], now, in[p][1], in[p-1][1]);
                    if (in[p][0]>in[p-1][0])    l=1;
                    else                        l=-1;
                    if (now>ans) ans=now;
                    now=chk(l, in[p][0],t, now, 1, in[p][1]);
                    if (now>ans) ans=now;
                }
                
            }
            break;
        }
        
        if (in[p][0]==t) in[p][1]++;
        else{
            if (p==0) {
                now=in[p][1];
                if (now>ans) ans=now;
            }
            else if (p==1) {
                now=in[p][1]+in[p-1][1];
                if (in[p][0]>in[p-1][0])    l=1;
                else                        l=-1;
                if (now>ans) ans=now;
                
            }
            else{
                now=chk(l, in[p-1][0],in[p][0], now, in[p][1], in[p-1][1]);
                if (in[p][0]>in[p-1][0])    l=1;
                else                        l=-1;
                if (now>ans) ans=now;
            }
            in[++p][0]=t;
            in[p][1]++;
            
        }
    }
    printf("%d",ans);
    return 0;
}
