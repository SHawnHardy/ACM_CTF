/*
 ID: shawn_w1
 PROG: dualpal
 LANG: C++
 */
#include "cstdio"
#include "cstdlib"
#include "cstring"
bool chk(char a[]){
    int len=(int)strlen(a);
    int flag=1;
    int l=0,r=len-1;
    while (l<r) {
        if (a[l]!=a[r]) {
            flag=0;
            break;
        }
        else {
            l++;
            r--;
        }
    }
    return flag;
}

void trans(int x,int b,char s[30]){
    int p=0;
    while (x) {
        char t=(char)(x%b);
        if (t>9)
            t+=('A'-10);
        else
            t+='0';
        s[p++]=t;
        x/=b;
    }
    s[p]='\0';
    int l=0,r=(int)strlen(s)-1;
    while (l<r) {
        char t=s[l];
        s[l]=s[r];
        s[r]=t;
        l++;
        r--;
    }
}


int main(){
    FILE *in,*out;
    in=fopen("dualpal.in", "r");
    out=fopen("dualpal.out", "w");
    int n,s;
    fscanf(in, "%d%d",&n,&s);
    int tn=0,t=s+1;
    while (tn<n) {
        int pn=0;
        for (int i=2; i<=10; i++) {
            char ts[30];
            trans(t, i, ts);
            if (chk(ts))
                pn++;
            if (pn>1)
                break;
        }
        if (pn>1) {
            tn++;
            fprintf(out,"%d\n",t);
        }
        t++;
    }
    
    
    
    fclose(in);
    fclose(out);
    return 0;
}