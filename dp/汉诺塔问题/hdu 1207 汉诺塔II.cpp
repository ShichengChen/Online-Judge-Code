#include<iostream>
#include<cstdio>
using namespace std;
#define MAXN 66
int dp[MAXN];
int main()
{
    dp[1] = 1,dp[2] = 3,dp[3] = 5;
    for(int i = 4;i < MAXN;i++)
    {
        dp[i] = 2 * dp[i - 1] + 1;
        for(int j = 2;j < i && j < 31;j++)
            dp[i] = min(dp[i - j] * 2 + (1 << j) - 1,dp[i]);
    }
    int n;
    while(scanf("%d",&n) != EOF)
        printf("%d\n",dp[n]);
}
