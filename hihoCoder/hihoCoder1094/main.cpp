#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "cmath"
#include "ctime"
#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "queue"
#include "stack"
#include "set"
#include "map"

using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<int,string> pis;

const int maxn=210;

char mp[maxn][maxn];
char hi[4][4];
char sur[10];

bool chk(int x,int y) {
    if (mp[x][y]!=hi[1][1])
        return false;
    int sx=x-1,sy=y-1;
    int dx=0,dy=1;
    int flag=1;
    for (int i=0; i<8; i++) {
        if (sur[i]!=mp[sx][sy]) {
            flag=0;
            break;
        }
        if (i==2)
            dx=1,dy=0;
        else if (i==4)
            dx=0,dy=-1;
        else if (i==6)
            dx=-1,dy=0;
            
        sx+=dx;
        sy+=dy;
    }
    if (flag)
        return true;
        
    sx=x-1,sy=y+1;
    dx=1,dy=0;
    flag=1;
    for (int i=0; i<8; i++) {
        if (sur[i]!=mp[sx][sy]) {
            flag=0;
            break;
        }
        if (i==2)
            dx=0,dy=-1;
        else if (i==4)
            dx=-1,dy=0;
        else if (i==6)
            dx=0,dy=1;
            
        sx+=dx;
        sy+=dy;
    }
    if (flag)
        return true;
    
    sx=x+1,sy=y+1;
    dx=0,dy=-1;
    flag=1;
    for (int i=0; i<8; i++) {
        if (sur[i]!=mp[sx][sy]) {
            flag=0;
            break;
        }
        if (i==2)
            dx=-1,dy=0;
        else if (i==4)
            dx=0,dy=1;
        else if (i==6)
            dx=1,dy=0;
            
        sx+=dx;
        sy+=dy;
    }
    if (flag)
        return true;
        
    sx=x+1,sy=y-1;
    dx=-1,dy=0;
    flag=1;
    for (int i=0; i<8; i++) {
        if (sur[i]!=mp[sx][sy]) {
            flag=0;
            break;
        }
        if (i==2)
            dx=0,dy=1;
        else if (i==4)
            dx=1,dy=0;
        else if (i==6)
            dx=0,dy=-1;
            
        sx+=dx;
        sy+=dy;
    }
    if (flag)
        return true;
    return false;
}


int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0; i<n; i++) {
        scanf("%s",mp[i]);
    }
    for (int i=0; i<3; i++) {
        scanf("%s",hi[i]);
    }
    sur[0]=hi[0][0];
    sur[1]=hi[0][1];
    sur[2]=hi[0][2];    
    sur[3]=hi[1][2];
    sur[4]=hi[2][2];
    sur[5]=hi[2][1];
    sur[6]=hi[2][0];
    sur[7]=hi[1][0];
    
    for (int i=1; i<(n-1); i++) {
        for (int j=1; j<(m-1); j++) {
            if (chk(i,j))
                printf("%d %d\n",i+1,j+1);
        }
    }
    
    return 0;
}
