#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int m[6]={0};
int w[6]={0};
int s=0,u=0;
int ans=0;
int main(){
    //input
    for (int i=1; i<=5; i++)    scanf("%d",m+i);
    for (int i=1;i<=5;i++)      scanf("%d",w+i);
    scanf("%d%d",&s,&u);
    for(int i=1;i<=5;i++){
        int min=m[i];
        int wr=w[i];
        m[i]=(500-2*min)*i-50*wr;
        w[i]=(150*i);
    }
    ans+=(100*s);
    ans-=(50*u);
    for(int i=1;i<=5;i++){
        if(m[i]>w[i])   ans+=m[i];
        else    ans+=w[i];
    }
    printf("%d",ans);
    return 0;
    
    
}
