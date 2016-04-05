#include <stdio.h>
int main(){
    int a=0;
    int c[3]={0};
    int m[3]={0};
    for (int i=0; i<3; i++) scanf("%d",c+i);
    for (int i=0; i<3; i++) scanf("%d",m+i);
    for (int i=0; i<3; i++) *(c+i)-=*(m+i);
    for (int i=0; i<3; i++){
        if (*(c+i)>0)   a+=(*(c+i)/2);
        else            a+=(*(c+i));
    }
    if (a>=0)   printf("YES");
    else        printf("NO");
    return 0;
}

