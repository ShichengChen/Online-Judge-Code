#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long LL;
#define MAXN 1000005
#define MOD 1000000007
LL dp[MAXN];
char s[MAXN];
int n;
LL extgcd(LL a,LL b,LL & x,LL & y)
{
    LL d = a;
    if(b)
    {
        d = extgcd(b,a % b,y,x);
        y -= (a / b) * x;
    }
    else
    {
        x = 1;
        y = 0;
    }
    return d;
}
LL mod_inverse(LL a,LL m)
{
    LL x,y;
    extgcd(a,m,x,y);
    return (m + x % m) % m;
}
LL C(int a,int b)
{
    if(b < 0)return 0;
    LL inverse = (mod_inverse(dp[b],MOD) * mod_inverse(dp[a - b],MOD)) % MOD;
    return (dp[a] * inverse) % MOD;
}
LL solve()
{
    int len = strlen(s),p = 0,q = 0;
    if(n & 1)return 0;
    for(int i = 0;i < len;i++)
    {
        if(s[i] == '(')p++;
        else q++;
        if(p < q)return 0;
    }
    return (C(n - p - q,n / 2 - p) - C(n - p - q,n / 2 - p - 1) + MOD) % MOD;
}
int main()
{
    dp[0] = 1;
    for(int i = 1;i < MAXN;i++)
        dp[i] = (dp[i - 1] * i) % MOD;
    while(scanf("%d",&n) != EOF)
    {
        scanf("%s",s);
        LL ans = solve();
        printf("%I64d\n",ans);
    }
}
