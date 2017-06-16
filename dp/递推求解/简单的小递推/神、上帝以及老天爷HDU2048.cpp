#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define N 23
double dp[N][N];
double dfs(int n,int m)
{
    if(m == 0)return dp[n][m] = 1;
    if(n == 1 && m == 1)return dp[n][m] = 0;
    if(dp[n][m] != 0)return dp[n][m];
    double ans = 0;
    if(m >= 2)
        ans += dfs(n - 1,m - 2) * m * (m - 1);
    if(n > m)
        ans += dfs(n - 1,m - 1) * m * (n - m) * 2;
    if(n > m)
        ans += dfs(n - 1,m) * (n - m) * (n - m);
    return dp[n][m] = ans / (n * n);
}
int main()
{
    int _,n;
    memset(dp,0,sizeof(dp));
    dfs(22,22);
    ///if call dfs(20,20)  dp[19][19] is 0
    ///why
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        printf("%.2f%%\n",dp[n][n] * 100);
    }
}
