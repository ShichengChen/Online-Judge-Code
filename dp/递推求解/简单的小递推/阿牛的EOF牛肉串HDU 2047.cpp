#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define N 42
long long dp[N][2];
long long dfs(int n,int o)
{
    if(n == 1) return dp[n][o];
    else if(dp[n][o] != -1)return dp[n][o];
    if(o == 0)return dp[n][o] = dfs(n - 1,1);
    return dp[n][o] = (dfs(n - 1,0) + dfs(n - 1,1)) * 2;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    dp[1][0] = 1 , dp[1][1] = 2;
    dfs(41,0);
    int n;
    while(scanf("%d",&n) != EOF)
        printf("%I64d\n",dp[n][0] + dp[n][1]);
}
