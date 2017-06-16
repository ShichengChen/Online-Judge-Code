#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 1005
#define MAXM 105
long long const MOD = 1e17;
long long dp1[MAXN],dp2[MAXN];
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k) != EOF)
    {
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        dp1[0] = 1;
        for(int i = 1;i <= k;i++)
            for(int j = i;j <= n;j++)
            {
                dp2[j] = (dp2[j] + dp2[j - i]) + (dp1[j] + dp1[j - i]) / MOD;
                dp1[j] = (dp1[j] + dp1[j - i]) % MOD;
            }
        if(dp2[n])printf("%lld%012lld\n",dp2[n],dp1[n]);
        else printf("%lld\n",dp1[n]);
    }
}
