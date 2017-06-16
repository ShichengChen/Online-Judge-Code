#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXM 33
int dp[MAXM];
int main()
{
    int n,w,cur,odd;
    while(scanf("%d%d",&n,&w) != EOF)
    {
        memset(dp,0,sizeof(dp));
        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&cur);
            dp[0] += 2 - cur;
            for(int j = 1;j <= w;j++)
            {
                dp[j] = max(dp[j - 1],dp[j]) + (j + cur) % 2;
                ans = max(ans,dp[j]);
            }
        }
        printf("%d\n",ans);
    }
}
