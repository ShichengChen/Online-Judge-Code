#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long LL;
#define MAXN 100005
LL whole[MAXN << 2],part[MAXN << 2];
int ql,qr;
void add(int l,int r,int cnt,int v)
{
    if(ql <= l && r <= qr)
        whole[cnt] += v;
    else if(ql <= r && qr >= l)
    {
        part[cnt] += (min(qr,r) - max(ql,l) + 1) * (LL)v;
        int mid = l + r >> 1;
        add(l,mid,cnt << 1,v);
        add(mid + 1,r,cnt << 1 | 1,v);
    }
}
LL sum(int l,int r,int cnt)
{
    if(qr < l || ql > r)
        return 0;
    else if(ql <= l && r <= qr)
        return (r - l + 1) * whole[cnt] + part[cnt];
    else
    {
        LL ans = whole[cnt] * (min(qr,r) - max(ql,l) + 1);
        int mid = l + r >> 1;
        ans += sum(l,mid,cnt << 1);
        ans += sum(mid + 1,r,cnt << 1 | 1);
        return ans;
    }
}
int main()
{
    int n,m,val;
    char q[2];
    while(scanf("%d%d",&n,&m) != EOF)
    {
        memset(part,0,sizeof(part));
        memset(whole,0,sizeof(whole));
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&val);
            ql = qr = i;
            add(1,n,1,val);
        }
        while(m--)
        {
            scanf("%s",q);
            if(q[0] == 'Q')
            {
                scanf("%d%d",&ql,&qr);
                LL ans = sum(1,n,1);
                printf("%lld\n",ans);
            }
            else
            {
                scanf("%d%d%d",&ql,&qr,&val);
                add(1,n,1,val);
            }
        }
    }
}
