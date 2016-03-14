#include "cstdio"
#include "cstdlib"
#include "cstring"
struct nd{
    char l[15];
    char r[15];
    char s[15];
};


int main(){
    int n;
    scanf("%d",&n);
    while (n--) {
        nd in[3];
        for (int i=0; i<3; i++) {
            getchar();
            scanf("%s",in[i].l);
            getchar();
            scanf("%s",in[i].r);
            getchar();
            scanf("%s",in[i].s);
        }
        int flag=0;
        int ans=-1;
        for (int i=0; i<24; i++) {
            int w=i%2;
            int t=i/2;
            int chkf=0;
            for (int j=0; j<3; j++) {
                int lw=(int)strlen(in[j].l);
                for (int k=0; k<lw; k++) {
                    if (in[j].l[k]-'A'==t) {
                        if (w) {
                            lw++;
                            break;
                        }
                        else {
                            lw--;
                            break;
                        }
                    }
                }
                int rw=(int)strlen(in[j].r);
                for (int k=0; k<rw; k++) {
                    if (in[j].r[k]-'A'==t) {
                        if (w) {
                            rw++;
                            break;
                        }
                        else {
                            rw--;
                            break;
                        }
                    }
                }
                if (in[j].s[0]=='e') {
                    if(rw!=lw){
                        chkf=1;
                    }
                }
                else if(in[j].s[0]=='u'){
                    if(rw>=lw){
                        chkf=1;
                    }
                }
                else {
                    if(rw<=lw){
                        chkf=1;
                    }
                }
                if (chkf){
                    break;
                }
            }
            if(chkf)    continue;
            else {
                if(flag){
                    flag++;
                    puts("cannot judge.");
                    break;
                }
                else {
                    flag++;
                    ans=i;
                }
            }
        }
        
        if (ans==-1) {
            puts("cannot judge.");
        }
        
        else if(flag==1){
            char A=(char)('A'+(ans/2));
            printf("%c is ",A);;
            if (ans%2) {
                printf("heavy.\n");
            }
            else {
                printf("light.\n");
            }
        }
    }
    return 0;
}