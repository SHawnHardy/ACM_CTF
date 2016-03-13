//
//  main.cpp
//  HDOJ1002
//
//  Created by 尚恒宇 on 15/10/13.
//  Copyright © 2015年 尚恒宇. All rights reserved.
//

#include "cstdio"
#include "cstring"

int T=0;
char a[1010]={0};
char b[1010]={0};
char ans[1010]={0};

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(ans, 0, sizeof(ans));
        
        scanf("%s%s",a,b);
        int i=0;
        while(a[i]!='\0')
        {
            a[i]-=48;
            i++;
        }
        i--;
        
        int j=0;
        while(b[j]!='\0')
            j++;
        j--;
        
        int p=1005;
        ans[p+1]='\0';
        
        while ((i+1)||(j+1))
        {
            if((i+1)&&(j+1))
            {
                ans[p]=a[i]+b[j];
                i--;
                j--;
                p--;
                continue;
            }
            else if(i<0)
            {
                while(j+1)
                {
                    ans[p]=b[j];
                    j--;
                    p--;
                }
            }
            else if(j<0)
            {
                while(i+1)
                {
                    ans[p]=a[i];
                    i--;
                    p--;
                }
            }
        }
        int h=p;
        p=1005;
        while(p>h)
        {
            if((int)ans[p]>57)
            {
                ans[p]-=10;
                ans[p-1]++;
            }
            p--;
        }
        if((int)ans[p]>57)
        {
            ans[p]-=10;
            ans[p-1]+=49;
            p--;
        }
        printf("%s",&ans[p]);
    
    }
    return 0;
}
