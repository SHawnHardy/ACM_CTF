//
//  main.cpp
//  HDOJ1001
//
//  Created by 尚恒宇 on 15/10/12.
//  Copyright © 2015年 尚恒宇. All rights reserved.
//

#include <cstdio>

int main()
{
    long long int n=0;
    long long int ans=0;
    while (scanf("%lld",&n)!=EOF)
    {
        ans=(1+n)*n/2;
        printf("%lld\n\n",ans);
    }
    return 0;
}