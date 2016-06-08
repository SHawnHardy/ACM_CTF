/*
 ID: shawn_w1
 PROG: transform
 LANG: C++
 */
#include "cstdio"
#include "cstdlib"
#include "cstring"


char str[20][20];
char tar[20][20];
int n;

bool chk(char a[][20]){
    for (int i=0; i<n; i++) {
        if (strcmp(a[i], tar[i])) {
            return false;
        }
    }
    return true;
}

void tran(char s[20][20],char t[20][20]){
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int ti=j;
            int tj=(n-1)-i;
            t[ti][tj]=s[i][j];
        }
        t[i][n]='\0';
    }
}



int main(){
    FILE *in,*out;
    in=fopen("transform.in", "r");
    out=fopen("transform.out", "w");
    fscanf(in,"%d",&n);
    
    for (int i=0; i<n; i++) {
        fscanf(in, "%s",str[i]);
    }
    for (int i=0; i<n; i++) {
        fscanf(in, "%s",tar[i]);
    }
    bool flag=chk(str);
    char t1[20][20];
    char t2[20][20];
    char t3[20][20];
    tran(str, t1);
    if(chk(t1)){
        fprintf(out, "1\n");
        fclose(in);
        fclose(out);
        return 0;
    }
    tran(t1, t2);
    if (chk(t2)) {
        fprintf(out, "2\n");
        fclose(in);
        fclose(out);
        return 0;
    }
    tran(t2, t3);
    if (chk(t3)) {
        fprintf(out, "3\n");
        fclose(in);
        fclose(out);
        return 0;
    }
    
    for (int i=0; i<n; i++) {
        int l=0,r=(n-1);
        while (l<r) {
            char t=str[i][l];
            str[i][l]=str[i][r];
            str[i][r]=t;
            l++;
            r--;
        }
    }
    if (chk(str)) {
        fprintf(out, "4\n");
        fclose(in);
        fclose(out);
        return 0;
    }
    tran(str, t1);
    if(chk(t1)){
        fprintf(out, "5\n");
        fclose(in);
        fclose(out);
        return 0;
    }
    tran(t1, t2);
    if (chk(t2)) {
        fprintf(out, "5\n");
        fclose(in);
        fclose(out);
        return 0;
    }
    tran(t2, t3);
    if (chk(t3)) {
        fprintf(out, "5\n");
        fclose(in);
        fclose(out);
        return 0;
    }
    
    if (flag) {
        fprintf(out, "6\n");
        fclose(in);
        fclose(out);
        return 0;
    }
    else {
        fprintf(out, "7\n");
        fclose(in);
        fclose(out);
        return 0;

    }
    
    return 0;
}