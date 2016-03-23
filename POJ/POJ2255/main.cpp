#include "cstdio"
#include "cstdlib"
#include "cstring"

struct node{
    char d;
    node* lc;
    node* rc;
};
node *rt;
char x[30];
char z[30];
int s[30][2];
int p=0;
void MT(char rtc,int l,int r,node *fa){
    int zs=s[rtc-'A'][1];
    if (zs>l) {
        fa->lc=(node *)malloc(sizeof(node));
        fa->lc->d=x[++p];
        MT(fa->lc->d, l, zs-1, fa->lc);
    }
    else fa->lc=NULL;
    if (zs<r) {
        fa->rc=(node *)malloc(sizeof(node));
        fa->rc->d=x[++p];
        MT(fa->rc->d, zs+1, r, fa->rc);
    }
    else fa->rc=NULL;
}

void PT(node *t){
    if (t->lc==NULL&&t->rc==NULL) {
        putchar(t->d);
        return ;
    }
    if (t->lc!=NULL) {
        PT(t->lc);
    }
    if (t->rc!=NULL) {
        PT(t->rc);
    }
    putchar(t->d);
    return;
}

void FT(node *t){
    if (t->lc!=NULL) {
        FT(t->lc);
    }
    if (t->rc!=NULL) {
        FT(t->rc);
    }
    free(t);
}


int main(){
    while (scanf("%s%s",x,z)==2) {
        memset(s, 0, sizeof(s));
        int len=(int)strlen(x);
        for (int i=0; i<len; i++) {
            s[x[i]-'A'][0]=i;
            s[z[i]-'A'][1]=i;
        }
        rt=(node *)malloc(sizeof(node));
        rt->d=x[0];
        p=0;
        MT(rt->d, 0, len-1, rt);
        PT(rt);
        putchar('\n');
        FT(rt);
    }
    return 0;
}