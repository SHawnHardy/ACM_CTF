#include "cstdio"
#define M 1000
int fa[M];
int find(int x){
    return x==fa[x]?x:fa[x]=bc(fa[x]);
}