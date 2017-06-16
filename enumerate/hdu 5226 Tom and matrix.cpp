#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long LL;
#define MAXN 100005
LL dp[MAXN],ndp[MAXN];
int x1,x2,y2,y1,mod;
LL _pow(LL a,int b)
{
    LL ans = 1,cur = a;
    while(b)
    {
        if(b & 1)ans = (cur * ans) % mod;
        cur = (cur * cur) % mod;
        b >>= 1;
    }
    return ans;
}
void init()
{
    dp[0] = ndp[0] = 1;
    for(int i = 1;i < MAXN;i++)
    {
        dp[i] = dp[i - 1] * i % mod;
        ndp[i] = _pow(dp[i],mod - 2);
    }
}
LL lucas(LL n,LL m)
{
    if (n < m) return 0;
    return dp[n] * ndp[m] % mod * ndp[n - m] % mod;
}
LL c(LL n,LL m)
{
    if (!m) return 1;
    return lucas(n % mod, m % mod) * c(n / mod, m / mod) % mod;
}
LL C(int a,int b)
{
    if(a < b)return 0;
    else if(!b)return 1;
    LL on = dp[a];
    LL below = ndp[b] * ndp[a - b] % mod;
    return on * below % mod;
}
int main()
{
    while(scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&mod) != EOF)
    {
        init();
        LL ans = 0,cur;
        for(int j = y1;j <= y2;j++)
        {
            if(mod < MAXN)cur = ((c(x2 + 1,j + 1) - c(x1,j + 1)) % mod + mod) % mod;
            else cur = ((C(x2 + 1,j + 1) - C(x1,j + 1)) % mod + mod) % mod;
            ans = (ans + cur) % mod;
        }
        printf("%I64d\n",ans);
    }
}
