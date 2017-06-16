#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 52
long long dp[N][3];
long long dfs(int n,int color)
{
    if(n == 1)return (color != 0);
    else if(dp[n][color] != -1)return dp[n][color];
    return dp[n][color] = dfs(n - 1,(color + 1) % 3) + dfs(n - 1,(color + 2) % 3);
}
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        memset(dp,-1,sizeof(dp));
        long long ans = max(dfs(n,0) * 3 , (long long)3);
        printf("%I64d\n",ans);
    }
}
