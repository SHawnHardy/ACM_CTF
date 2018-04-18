/*
 ID: shawn_w1
 PROG: crypt1
 LANG: C++
 */
#include "cstdio"
#include "cstdlib"
#include "cstring"
int num[20];
int cn[10]={0};

bool chk1(int x){
    if (!x) {
        return true;
    }
    while (x) {
        if (!cn[x%10]) {
            return true;
        }
        x/=10;
    }
    return false;
}

bool chk2(int x,int a){
    if (chk1(x)) {
        return true;
    }
    int aa=0;
    while (x) {
        x/=10;
        aa++;
    }
    return aa!=a;
}



int main(){
    FILE *in,*out;
    in=fopen("crypt1.in", "r");
    out=fopen("crypt1.out", "w");
    int n;
    fscanf(in,"%d",&n);
    for (int i=0; i<n; i++) {
        fscanf(in,"%d",num+i);
        cn[num[i]]=1;
    }
    int ans=0;
    for (int a=0; a<n; a++) {
        for (int b=0; b<n; b++) {
            for (int c=0; c<n; c++) {
                for (int d=0; d<n; d++) {
                    for (int e=0; e<n; e++) {
                        int x1=num[a]*100+num[b]*10+num[c],x2=num[d]*10+num[e];
                        if (chk2(x1, 3)||chk2(x2, 2)) {
                            continue;
                        }
                        int c1=(x2%10)*x1,c2=(x2/10)*x1;
                        if (chk2(c1, 3)||chk2(c2, 3)) {
                            continue;
                        }
                        int fa=x1*x2;
                        if (chk2(fa, 4)) {
                            continue;
                        }
                        ans++;
                    }
                }
            }
        }
    }
    fprintf(out,"%d\n",ans);
    

    fclose(in);
    fclose(out);
    return 0;
}