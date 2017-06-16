#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
#define INF 1e10
LL n,m;
LL f(LL i,LL j)
{
    return i * i + 100000 * i + j * j - 100000 * j + i * j;
}
LL binary_n(LL j,LL val)
{
    LL l = 0,r = n;
    while(l < r)
    {
        LL i = l + r + 1 >> 1;
        if(f((LL)i,(LL)j) > val)r = i - 1;
        else l = i;
    }
    return l;
}
bool isfind(LL mid)
{
    LL cur = 0;
    for(LL j = 1;j <= n;j++)
    {
        cur += binary_n(j,mid);
        if(cur >= m)return true;
    }
    return cur >= m;
}
LL binary()
{
    LL l = -INF,r = INF,mid;
    while(l < r)
    {
        if(l + r > 0)mid = l + r >> 1;
        else mid = (l + r - 1) / 2;
        if(isfind(mid))r = mid;
        else l = mid + 1;
    }
    return l;
}
int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%lld%lld",&n,&m);
        LL ans = binary();
        printf("%lld\n",ans);
    }
}
