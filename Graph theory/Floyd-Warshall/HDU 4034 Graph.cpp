#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 105
int dp[MAXN][MAXN];
int solve(int n)
{
    int ans = n * (n - 1);
    for(int j = 1;j <= n;j++)
        for(int i = 1;i <= n;i++)
            for(int k = 1;k <= n;k++)
            {
                if(i == k || j == k || i == j)continue;
                if(dp[i][k] + dp[k][j] < dp[i][j])return -1;
                else if(dp[i][k] + dp[k][j] == dp[i][j])
                {
                    ans--;
                    break;
                }
            }
    return ans;
}
int main()
{
    int _,n,w;
    for(int kcas = scanf("%d",&_);kcas <= _;kcas++)
    {
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
            {
                scanf("%d",&w);
                dp[i][j] = w;
            }
        int ans = solve(n);
        if(ans == -1)printf("Case %d: impossible\n",kcas);
        else printf("Case %d: %d\n",kcas,ans);
    }
}
