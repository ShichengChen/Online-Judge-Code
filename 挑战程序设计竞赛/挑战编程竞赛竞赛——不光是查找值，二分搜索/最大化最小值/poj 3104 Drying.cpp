#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
#define MAXN 100005
#define INF 1e15
int num[MAXN],n,m,maxn;
bool isfind(LL mid)
{
    LL tem = 0;
    for(int i = 0;i < n;i++)
    {
        if(num[i] <= mid)continue;
        tem += (num[i] - mid + m - 2) / (m - 1);
    }
    return tem <= mid;
}
LL binary()
{
    LL l = 1,r = INF;
    if(m == 1)return maxn;
    while(l < r)
    {
        LL mid = l + r >> 1;
        if(isfind(mid))r = mid;
        else l = mid + 1;
    }
    return l;
}
int main()
{
    while(scanf("%d",&n) != EOF)
    {
        maxn = 0;
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&num[i]);
            maxn = max(maxn,num[i]);
        }
        scanf("%d",&m);
        LL ans = binary();
        printf("%lld\n",ans);
    }
}
