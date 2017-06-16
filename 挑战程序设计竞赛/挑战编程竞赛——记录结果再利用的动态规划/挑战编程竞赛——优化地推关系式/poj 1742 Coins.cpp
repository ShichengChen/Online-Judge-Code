#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXM 100010
#define MAXN 105
bool vis[MAXM];
int dp[MAXM],val[MAXN],num[MAXN];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m),n | m)
    {
        for(int i = 1;i <= n;i++)
            scanf("%d",&val[i]);
        for(int i = 1;i <= n;i++)
            scanf("%d",&num[i]);
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        vis[0] = dp[0] = 1;
        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 0;j <= m;j++)
            {
                if(dp[j] <= 0 && j >= val[i])
                    dp[j] = dp[j - val[i]] - 1;
                else if(dp[j] > 0)
                    dp[j] = num[i] + 1;
                if(dp[j] > 0 && !vis[j])
                    vis[j] = ++ans;
            }
        }
        printf("%d\n",ans);
    }
}
