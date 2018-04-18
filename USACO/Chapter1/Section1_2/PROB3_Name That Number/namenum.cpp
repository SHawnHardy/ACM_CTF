/*
 ID: shawn_w1
 PROG: namenum
 LANG: C++
 */
#include "cstdio"
#include "cstdlib"
#include "cstring"
typedef long long int LL;
int main(){
    char trans[]="22233344455566677778889999";
    
    
    FILE *dic,*in,*out;
    dic=fopen("dict.txt", "r");
    in=fopen("namenum.in", "r");
    out=fopen("namenum.out", "w");
    LL n;
    fscanf(in, "%lld",&n);
    char t[30];
    int flag=1;
    while (~fscanf(dic, "%s",t)) {
        LL tn=0;
        for (int i=0; i<strlen(t); i++) {
            tn*=10;
            tn+=(trans[t[i]-'A']-'0');
        }
        if (tn==n) {
            fprintf(out,"%s\n",t);
            flag=0;
        }
    }
    if (flag) {
        fprintf(out, "NONE\n");
    }
    fclose(dic);
    fclose(in);
    fclose(out);
    return 0;
}