#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 105
#define INF 0x1f1f1f1f
int dp[MAXN][MAXN],w[MAXN][MAXN],pre[MAXN][MAXN],arr[MAXN];
int n,m,len;
void dfs(int i,int j)
{
    int k = pre[i][j];
    if(k == -1)
    {
        arr[len++] = i;
        return;
    }
    dfs(i,k),dfs(k,j);
}
void floyd()
{
    int ans = INF;
    len = 0;
    for(int k = 1;k <= n;k++)
    {
        for(int i = 1;i < k;i++)
            for(int j = 1 + i;j < k;j++)
            {
                int cur = dp[i][j] + w[i][k] + w[k][j];
                if(cur < ans)
                {
                    ans = cur;
                    len = 0;
                    arr[len++] = k;
                    dfs(i,j);
                    arr[len++] = j;
                }
            }
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
            {
                if(dp[i][j] > dp[i][k] + dp[k][j])
                {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    pre[i][j] = k;
                }
            }
    }
}
int main()
{
    int u,v,val;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        memset(dp,0x1f,sizeof(dp));
        memset(w,0x1f,sizeof(w));
        memset(pre,-1,sizeof(pre));
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&val);
            dp[u][u] = dp[v][v] = w[u][u] = w[v][v] = 0;
            w[v][u] = w[u][v] = dp[u][v] = dp[v][u] = min(val,dp[u][v]);
        }
        floyd();
        if(len < 2)puts("No solution.");
        else
            for(int i = 0;i < len;i++)
                if(i != len - 1)printf("%d ",arr[i]);
                else printf("%d\n",arr[i]);
    }
}
