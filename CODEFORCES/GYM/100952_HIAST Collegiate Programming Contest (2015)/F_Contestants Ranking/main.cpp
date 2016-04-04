#include "iostream"
#include "cstring"
#include "cstdlib"
#include "string"
#include "map"
#include "set"
#include "queue"
#include "algorithm"
using namespace std;
struct Na{
    char name[25];
    int rk;
};

int Dic(char a[25],char b[25]){
    int re=(int)strlen(a)-(int)strlen(b);
    for (int i=0; i<(int)strlen(a)&&i<(int)strlen(b); i++) {
        if (a[i]==b[i]) 
            continue;
        else 
            return (int)(a[i]-b[i]);
    }
    return re;
}

short G[400][400]={0};

int cmp(const void *a,const void *b){
    Na *aa=(Na*)a;
    Na *bb=(Na*)b;
    char sa[25];
    strcpy(sa, aa->name);
    char sb[25];
    strcpy(sb, bb->name);
    if((aa->rk)==(bb->rk))
        return Dic(sa, sb);
    else 
        return (aa->rk)-(bb->rk);
}
map<string,int> D;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int p=0;
        D.clear();
        Na DD[400];
        memset(G,0,sizeof(G));
        for(int i=0;i<n;i++){
            char in[3][25];
            int num[3]={0};
            scanf("%s %s %s",in[0],in[1],in[2]);
            for(int j=0;j<3;j++){
                if(D.find(in[j])!=D.end())
                    num[j]=D[in[j]];
                else {
                    num[j]=p++;
                    D[in[j]]=num[j];
                    strcpy(DD[num[j]].name,in[j]);
                }
            }
            for(int j=0;j<3;j++){
                for(int k=j+1;k<3;k++){
                    G[num[j]][num[k]]=1;
                    G[num[k]][num[j]]=1;
                }
            }
        }
        int rt=D["Ahmad"];
        int rank[400]={0};
        memset(rank,0,sizeof(rank));
        rank[rt]=1;
        queue<int> q;
        q.push(rt);
        while(!q.empty()){
            int op=q.front();
            q.pop();
            for(int i=0;i<p;i++){
                if(rank[i])
                    continue;
                if(G[op][i]){
                    rank[i]=rank[op]+1;
                    q.push(i);
                }
            }
        }
        for(int i=0;i<p;i++){
            DD[i].rk=rank[i];
            if(!rank[i])
                DD[i].rk=5000;
        }
        qsort(DD,p,sizeof(Na),cmp);
        cout<<p<<endl;
        for(int i=0;i<p;i++){
            if(DD[i].rk==5000){
                cout<<DD[i].name<<' '<<"undefined"<<endl;
                continue;
            }
            cout<<DD[i].name<<' '<<(DD[i].rk-1)<<endl;
        }
    }
    return 0;
}