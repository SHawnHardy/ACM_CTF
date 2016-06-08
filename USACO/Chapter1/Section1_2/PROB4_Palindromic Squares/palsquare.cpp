/*
 ID: shawn_w1
 PROG: palsquare
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
    in=fopen("palsquare.in", "r");
    out=fopen("palsquare.out", "w");
    int n;
    fscanf(in, "%d",&n);
    for (int i=1; i<=300; i++) {
        char x[30],x2[30];
        trans(i*i, n, x2);
        if (chk(x2)) {
            trans(i, n, x);
            fprintf(out,"%s %s\n",x,x2);
        }
    }
    fclose(in);
    fclose(out);
    return 0;
}