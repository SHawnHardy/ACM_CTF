#include "cstdio"
#include "cstring"

char a[1010]={0};
char b[1010]={0};
char ans[1010]={0};

int main()
{
    int T=0;
    scanf("%d",&T);
    for (int c=1; c<=T; c++) {
        memset(a, 0, sizeof(a));
        memset(b,0,sizeof(b));
        memset(ans, 0, sizeof(ans));
        scanf(" %s %s",a,b);
        for (int l=0,r=(int)strlen(a)-1; l<r; l++,r--) {
            char t=a[l];
            a[l]=a[r];
            a[r]=t;
        }
        for (int l=0,r=(int)strlen(b)-1; l<r; l++,r--) {
            char t=b[l];
            b[l]=b[r];
            b[r]=t;
        }
        int flag=0;
        int p=0,la=(int)strlen(a),lb=(int)strlen(b);
        while (1) {
            int t=0;
            if (p<la) 
                t+=a[p]-'0';
            if (p<lb)
                t+=b[p]-'0';
            t+=flag;
            if (t>9) {
                t-=10;
                flag=1;
            }
            else
                flag=0;
            ans[p]=t+'0';
            if (p>=la&&p>=lb&&(!flag))
                break;
            p++;
        }
        while (ans[p]=='0'&&p>=0)
            p--;
        if (p<0) {
            ans[0]='0';
            ans[1]='\0';
        }
        else
            ans[p+1]='\0';
        for (int l=0,r=(int)strlen(a)-1; l<r; l++,r--) {
            char t=a[l];
            a[l]=a[r];
            a[r]=t;
        }
        for (int l=0,r=(int)strlen(b)-1; l<r; l++,r--) {
            char t=b[l];
            b[l]=b[r];
            b[r]=t;
        }
        for (int l=0,r=(int)strlen(ans)-1; l<r; l++,r--) {
            char t=ans[l];
            ans[l]=ans[r];
            ans[r]=t;
        }
        printf("Case %d:\n",c);
        printf("%s + %s = %s\n",a,b,ans);
        if (c<T)
            putchar('\n');
    }
        return 0;
}