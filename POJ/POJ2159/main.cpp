#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "algorithm"
using namespace std;
int main(){
    
    char s1[110];
    char s2[110];
    scanf("%s",s1);
    getchar();
    scanf("%s",s2);
    if (strlen(s1)!=strlen(s2)) {
        printf("NO\n");
        return 0;
    }
    int n1[30]={0};
    int n2[30]={0};
    for (int i=0; i<strlen(s1); i++) {
        n1[(int)(s1[i]-'A')]++;
        n2[(int)(s2[i]-'A')]++;
    }
    sort(n1,n1+26);
    sort(n2,n2+26);
    for (int i=0; i<26; i++) {
        if (n1[i]!=n2[i]) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}