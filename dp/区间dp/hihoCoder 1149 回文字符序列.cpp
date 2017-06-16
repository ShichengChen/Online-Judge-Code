#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 1005
#define MOD 100007
int dp[MAXN][MAXN];
char s[MAXN];
int main()
{
    int _;
    for(int kcas = scanf("%d",&_);kcas <= _;kcas++)
    {
        memset(dp,0,sizeof(dp));
        scanf("%s",s + 1);
        int n = strlen(s + 1);
        for(int k = 0;k <= n;k++)
        {
            for(int i = 1;i + k <= n;i++)
            {
                int j = i + k;
                if(s[i] == s[j])dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] + 1) % MOD;
                else dp[i][j] = ((dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1]) % MOD + MOD) % MOD;
            }
        }
        printf("Case #%d: %d\n",kcas,dp[1][n]);
    }
}
