#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 1000010
#define MOD 1000000000
int dp[MAXN];
int main()
{
    dp[1] = 1;
    for(int i = 2;i < MAXN;i++)
    {
        if(i & 1)dp[i] = dp[i - 1];
        else dp[i] = (dp[i - 1] + dp[i >> 1]) % MOD;
    }
    int n;
    while(scanf("%d",&n) != EOF)
        printf("%d\n",dp[n]);
}
