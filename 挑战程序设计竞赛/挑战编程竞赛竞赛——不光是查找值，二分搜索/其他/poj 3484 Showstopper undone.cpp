#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long LL;
#define MAXN 1000000
#define INF 1e10
int n;
LL x[MAXN], y[MAXN], z[MAXN];
LL isfind(LL mid)
{
    LL l = 0;
    for(int i = 0;i < n;i++)
        l += max((min(mid,y[i]) - x[i]) / z[i] + 1, (LL)0);
    return l;
}
LL binary()
{
    LL l = 0,r = INF;
    while(l < r)
    {
        LL mid = l + r >> 1;
        if(isfind(mid) & 1)r = mid;
        else l = mid + 1;
    }
    return l;
}
void solve()
{
    LL ans = binary();
    if(ans >= INF)
        puts("no corruption");
    else
        printf("%lld %lld\n",ans,isfind(ans) - isfind(ans - 1));
}
int main()
{
    n = 0;
    char s[111];
    while (gets(s))
    {
        if (strlen(s))
        {
            sscanf(s,"%lld%lld%lld", &x[n], &y[n], &z[n]);
            ++n;
        }
        else if (n)
        {
            solve();
            n = 0;
        }
    }
    if (n)
        solve();
}
