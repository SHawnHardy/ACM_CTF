//
//  main.cpp
//  HDOJ1010
//
//  Created by 尚恒宇 on 16/1/6.
//  Copyright © 2016年 尚恒宇. All rights reserved.
//

#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "stack"
using namespace std;
stack<pair<int, int>> s;
const int INF=1e9;
int G[10][10];


int N,M,T;

int main(){
    while (scanf("%d%d%d",&N,&M,&T)) {
        if (!N&&!M&&!T) {
            break;
        }
        else{
            int Dx=0,Dy=0;
            int Sx=0,Sy=0;
            for (int i=1; i<=N; i++) {
                char in[10];
                scanf("%s",in);
                for (int j=0; j<M; j++) {
                    if (in[j]=='S') {
                        G[i][j]=0;
                        Sx=i;
                        Sy=j;
                    }
                    else if (in[j]=='D'){
                        G[i][j]=INF;
                        Dx=i;
                        Dy=j;
                    }
                    else if (in[j]=='X'){
                        G[i][j]=-1;
                    }
                    else {
                        G[i][j]=INF;
                    }
                }
                
            }
            s.push(pair<int, int>{Sx,Sy});
            while (!s.empty()) {
                int ox=s.top().first;
                int oy=s.top().second;
                s.pop();
                
            }
            
            
            
            
            
        }
    }
    return 0;
}
