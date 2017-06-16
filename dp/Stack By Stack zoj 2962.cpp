/*
every stack's status is determined;
so dp[i] have some relationship with dp[i - 1];
they have some same status;
*/
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
#define N 1010
int vol[N];
LL sum[N];
LL dp(int n,int ind)
{
    if(ind == 0)return 0;
    if(n == 1)return (LL)(1 + ind) * ind / 2;
    if(ind % vol[n - 1] == 0)return (LL)sum[n - 1] * (ind / vol[n - 1]);
    return (ind / vol[n - 1] + 1) * sum[n - 1] - dp(n - 1,vol[n - 1] - (ind % vol[n - 1]));
}
int main()
{
    int n,lb,ub;
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&vol[i]);
            sum[i] = dp(i,vol[i]);
        }
        scanf("%d%d",&lb,&ub);
        printf("%lld\n",dp(n,ub) - dp(n,lb - 1));
    }
}
