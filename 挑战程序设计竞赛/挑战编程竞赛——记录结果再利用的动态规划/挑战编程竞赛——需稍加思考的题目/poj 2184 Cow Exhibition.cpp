#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 200005
#define MID 100000
#define MAXM 105
int dp[2][MAXN],w[MAXM],c[MAXM];
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 0;i < n;i++)
            scanf("%d%d",&c[i],&w[i]);
        memset(dp,-0x3f,sizeof(dp));
        dp[0][MID] = 0;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < MAXN;j++)
            {
                dp[(i + 1) & 1][j] = dp[i & 1][j];
                if(0 <= j - c[i] && j - c[i] < MAXN)
                    dp[(i + 1) & 1][j] = max(dp[i & 1][j],dp[i & 1][j - c[i]] + w[i]);
            }
        int ans = 0;
        for(int j = MID;j < MAXN;j++)
            if(dp[n & 1][j] >= 0 && j >= MID)
                ans = max(ans,j - MID + dp[n & 1][j]);
        printf("%d\n",ans);
    }
}
