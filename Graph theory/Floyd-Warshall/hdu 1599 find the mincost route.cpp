#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 105
#define INF 0x1f1f1f1f
int dp[MAXN][MAXN],w[MAXN][MAXN],n,m;
int floyd()
{
    int ans = INF;
    for(int k = 1;k <= n;k++)
    {
        for(int i = 1;i < k;i++)
            for(int j = 1 + i;j < k;j++)
                ans = min(ans,dp[i][j] + w[i][k] + w[k][j]);
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                dp[i][j] = min(dp[i][k] + dp[k][j],dp[i][j]);
    }
    return ans;
}
int main()
{
    int u,v,val;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        memset(dp,0x1f,sizeof(dp));
        memset(w,0x1f,sizeof(w));
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&val);
            dp[u][u] = dp[v][v] = w[u][u] = w[v][v] = 0;
            w[v][u] = w[u][v] = dp[u][v] = dp[v][u] = min(val,dp[u][v]);
        }
        int ans = floyd();
        if(ans == INF)puts("It's impossible.");
        else printf("%d\n",ans);
    }
}
