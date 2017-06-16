#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
#define MAXN 50005
int num[MAXN],bound[MAXN];
ll gcd(ll a,ll b)
{
    if(b)return gcd(b,a % b);
    return a;
}
ll C(ll a)
{
    return a * (a - 1) * (a - 2) / 2 / 3;
}
int main()
{
    int _,n,m;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++)
            scanf("%d",&num[i]);
        memset(bound,0,sizeof(bound));
        for(int i = 0;i < m;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            bound[l]++,bound[r + 1]--;
        }
        int cnt = 0;
        ll ans1 = 0;
        for(int i = 1;i <= n;i++)
        {
            cnt += bound[i];
            if(cnt >= 3)
            {
                ans1 += num[i] * C(cnt);
            }
        }
        ll ans2 = C(m);
        ll cur = gcd(ans1,ans2);
        if(cur)
        {
            ans1 /= cur,ans2 /= cur;
            if(ans2 == 1)printf("%I64d\n",ans1);
            else printf("%I64d/%I64d\n",ans1,ans2);
        }
        else puts("0");
    }
}
