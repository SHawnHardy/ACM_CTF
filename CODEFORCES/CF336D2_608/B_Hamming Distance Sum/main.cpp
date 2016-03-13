#include "cstdio"
#include "cstdlib"
#include "cstring"
#define M 200010
#define LL long long int
char a[M];
int T[M];
inline int lowbit(int x){
    return x&(-x);
}

void add(int s){
    int p=s;
    while (p<=M) {
        T[p]++;
        p+=lowbit(p);
    }
    
}

int ask(int s){
    int p=s;
    int re=0;
    while (p) {
        re+=T[p];
        p-=lowbit(p);
    }
    return re;
}


int main(){
    scanf("%s",a+1);
    LL ans=0;
    int la=(int)strlen(a+1);
    char in;
    int p=0;
    while((in=getchar())){
        if (in=='1'||in=='0'){
            p++;
            if (in=='1') {
                add(p);
            }
            break;
        }
    }
    while ((in=getchar())=='1'||in=='0') {
        p++;
        if (in=='1') {
            add(p);
        }
    }
    int lb=p;
    p=0;
    int c=lb-la;
    while ((++p)<=la) {
        int l=p;
        int r=p+c;
        int q=(ask(r)-ask(l-1));
        
        if (a[p]=='0') {
            ans+=q;
        }
        else    ans+=(r-l+1-q);
    }
    printf("%I64d",ans);
    return 0;
    
    
    
}
