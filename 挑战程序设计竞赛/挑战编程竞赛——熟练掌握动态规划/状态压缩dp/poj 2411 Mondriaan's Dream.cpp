#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 14
long long dp[2][1 << MAXN];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m),m | n)
    {
        long long * cur = dp[0], * next = dp[1];
        memset(dp,0,sizeof(dp));
        cur[0] = 1;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                for(int k = 0;k < 1 << m;k++)
                {
                    if(k >> j & 1)
                        next[k & ~(1 << j)] += cur[k];
                    else
                    {
                        if(j + 1 < m && !(k >> (j + 1) & 1))
                            next[k | 1 << (j + 1)] += cur[k];
                        if(i + 1 < n)
                            next[k | 1 << j] += cur[k];
                    }
                }
                swap(cur,next);
                memset(next,0,1 << m + 3);
            }
        }
        printf("%lld\n",cur[0]);
    }
}
