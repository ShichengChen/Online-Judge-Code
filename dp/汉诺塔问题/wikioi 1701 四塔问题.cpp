#include<iostream>
#include<cstdio>
using namespace std;
#define MAXN 50050
#define MOD 10000
int dp[MAXN],r[MAXN];
int pow(int b)
{
    int ans = 1;
    for(int i = 1;i <= b;i++)
        ans = ans * 2 % MOD;
    return ans - 1;
}
int main()
{
    int cnt = 1;
    for(int i = 1;cnt < MAXN;i++)
        for(int j = 0;j <= i && cnt < MAXN;j++)
            r[cnt++] = i;
    dp[1] = 1,dp[2] = 3,dp[3] = 5;
    for(int i = 4;i < MAXN;i++)
        dp[i] = (2 * dp[i - r[i]] + pow(r[i])) % MOD;
    int n;
    while(scanf("%d",&n) != EOF)
        printf("%d\n",dp[n]);
}
