#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "stack"
#include "queue"
using namespace std;

int n,m;

int G[30][30];
int d[30];

int tG[30][30];
int td[30];


int func(int x,int nn){
    memcpy(tG, G, sizeof(G));
    memcpy(td, d, sizeof(d));
    queue<int>  ans;
    queue<int>  q;
    int ts=1;
    for (int i=0; i<n; i++) {
        if (!td[i]) {
            q.push(i);
            ans.push(i);
        }
    }
    if (q.size()==0) {
        printf("Inconsistency found after %d relations.\n",x);
        return 1;
    }
    if (q.size()>1) {
        ts=0;
    }
    while (!q.empty()) {
        int t=q.front();
        q.pop();
        for (int i=0; i<n; i++) {
            if (tG[t][i]) {
                tG[t][i]=0;
                td[i]--;
                if (td[i]==0) {
                    q.push(i);
                    ans.push(i);
                }
            }
        }
        if (q.size()>1) {
            ts=0;
        }
    }
    if (ans.size()<nn) {
        printf("Inconsistency found after %d relations.\n",x);
        return 1;
    }
    else {
        if (ts&&nn==n) {
            printf("Sorted sequence determined after %d relations: ",x);
            while (!ans.empty()) {
                char to=(char)(ans.front()+'A');
                putchar(to);
                ans.pop();
            }
            putchar('.');
            putchar('\n');
            return 1;
        }
        else
            return 0;
    }

}



int main(){
    while (1) {
        scanf("%d%d",&n,&m);
        if (n+m==0) {
            break;
        }
        memset(G, 0, sizeof(G));
        memset(d, -1, sizeof(d));
        int flag=1;
        int chk=0;
        for (int i=0; i<m; i++) {
            char t,f;
            getchar();
            scanf("%c<%c",&f,&t);
            if (flag==0) {
                continue;
            }
            
            t-='A';
            f-='A';
            if (t==f) {
                printf("Inconsistency found after %d relations.\n",i+1);
                flag=0;
                break;
            }
            if (d[t]==-1) {
                d[t]=1;
                chk++;
            }
            else {
                if (G[f][t]==0) {
                    d[t]++;
                }
            }
            if (d[f]==-1) {
                d[f]=0;
                chk++;
            }
            
            G[f][t]=1;
            
            int tflag=func(i+1,chk);
            if (tflag) {
                flag=0;
                continue;
            }
        }
        if (flag) {
            puts("Sorted sequence cannot be determined.");
        }
    }
}