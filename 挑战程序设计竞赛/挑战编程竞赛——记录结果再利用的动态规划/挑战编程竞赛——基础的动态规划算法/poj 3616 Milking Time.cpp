#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 2000010
#define MAXM 1010
#define lowbit(i) (i & -i)
struct Interval
{
    int l,r,v;
    bool operator < (const Interval & in)const{
        return r < in.r;
    }
}interval[MAXM];
int prefix[MAXN];
int getm(int i)
{
    int ans = 0;
    for(;i;i -= lowbit(i))
        ans = max(ans,prefix[i]);
    return ans;
}
void modify(int i,int r,int val)
{
    for(;i <= r;i += lowbit(i))
        prefix[i] = max(prefix[i],val);
}
int main()
{
    int n,m,r;
    while(scanf("%d%d%d",&n,&m,&r) != EOF)
    {
        memset(prefix,0,sizeof(prefix));
        for(int i = 0;i < m;i++)
            scanf("%d%d%d",&interval[i].l,&interval[i].r,&interval[i].v);
        sort(interval,interval + m);
        for(int i = 0;i < m;i++)
        {
            int maxn = getm(interval[i].l);
            modify(interval[i].r + r,n << 1,maxn + interval[i].v);
        }
        int ans = getm(n << 1);
        printf("%d\n",ans);
    }
}
