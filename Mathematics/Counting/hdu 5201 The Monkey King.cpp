#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long LL;
#define MOD 1000000007
#define MAXN 200005
LL d[MAXN],nd[MAXN];
int n,m;
LL _pow(LL a,int b)
{
    LL ans = 1;
    while(b)
    {
        if(b & 1)ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}
LL C(int a,int b)
{
    return d[a] * nd[b] % MOD * nd[a - b] % MOD;
}
LL f(int a,int b)
{
    return C(a + b - 1,b - 1);
}
LL cal(int u)
{
    LL ans = 0;
    for(int i = 1;(i + 1) * u <= n && i <= m - 1;i++)
    {
        LL cur = C(m - 1,i) * f(n - (i + 1) * u,m - 1);
        if(i & 1)ans = ((ans - cur) % MOD + MOD) % MOD;
        else ans = (ans + cur) % MOD;
    }
    return ans;
}
void init()
{
    d[0] = d[1] = nd[0] = nd[1] = 1;
    for(int i = 2;i < MAXN;i++)
    {
        d[i] = d[i - 1] * i % MOD;
        nd[i] = _pow(d[i],MOD - 2);
    }
}
int main()
{
    int _;
    scanf("%d",&_);
    init();
    while(_--)
    {
        scanf("%d%d",&n,&m);
        LL ans = f(n,m);
        for(int u = 0;u <= n;u++)
            ans = (ans + cal(u)) % MOD;
        printf("%I64d\n",ans);
    }
}
