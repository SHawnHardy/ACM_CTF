#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "cmath"
#include "algorithm"

using namespace std;

char fj[20]="fjxmlhx";
char ma[20]="marshtomp";

char tl(char c) {
    return c>='A'&&c<='Z'?c-'A'+'a':c;
}
int main() {
    char str[210];
    while (fgets(str,100,stdin)!=NULL) {
        for (int i=0; i<strlen(str); i++) {
            if (tl(str[i]) == 'm') {
                int flag = 1;
                if (i + strlen(ma) - 1 < strlen(str)) {
                    for (int j = 1; j < strlen(ma) && i + j < strlen(str); j++) {
                        if (tl(str[i + j]) != ma[j]) {
                            flag = 0;
                            break;
                        }
                    }
                }
                else {
                    flag = 0;
                }
                if (flag) {
                    printf("%s", fj);
                    i += (strlen(ma) - 1);
                }
                else {
                    putchar(str[i]);
                }
            }
            else {
                putchar(str[i]);
            }
        }
    }
    return 0;
}


