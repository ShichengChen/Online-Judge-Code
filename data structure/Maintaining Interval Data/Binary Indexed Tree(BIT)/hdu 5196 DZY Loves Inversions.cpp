#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
#define MAXN 100005
#define lowbit(i) (i & -i)
int num[MAXN],bit[MAXN],n,q;
LL fk1[MAXN],fk2[MAXN],s1[MAXN],s2[MAXN],k;
struct Node
{
    int v,id;
    bool operator < (const Node & c)const{
        return v < c.v;
    }
}node[MAXN];
int sum(int i)
{
    int total = 0;
    for(;i;i -= lowbit(i))
        total += bit[i];
    return total;
}
void modify(int i,int key)
{
    for(;i <= n;i += lowbit(i))
        bit[i] += key;
}
void findf(LL k,LL * s,LL * ss)
{
    LL cur = 0;
    memset(bit,0,sizeof(bit));
    for(int i = 1,j = 0;i <= n;i++)
    {
        while(j <= n && cur <= k)
        {
            if(++j > n)break;
            cur += (j - i) - sum(num[j]);
            modify(num[j],1);
        }
        cur -= sum(num[i] - 1);
        modify(num[i],-1);
        s[i] = j - 1;
        ss[i] = ss[i - 1] + j - i;
    }
}
LL query(int l,int r)
{
    int ind = upper_bound(fk1 + l,fk1 + r + 1,r) - fk1 - 1;
    LL cur = r - ind;
    LL ans1 = (cur + 1) * cur / 2 + s1[ind] - s1[l - 1];
    if(!k)return ans1;
    ind = upper_bound(fk2 + l,fk2 + r + 1,r) - fk2 - 1;
    cur = r - ind;
    LL ans2 = (cur + 1) * cur / 2 + s2[ind] - s2[l - 1];
    return ans1 - ans2;
}
void solve()
{
    findf(k,fk1,s1);
    if(k)findf(k - 1,fk2,s2);
    int l,r;
    for(int i = 0;i < q;i++)
    {
        scanf("%d%d",&l,&r);
        LL ans = query(l,r);
        printf("%I64d\n",ans);
    }
}
int main()
{
    while(~scanf("%d%d%I64d",&n,&q,&k))
    {
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&num[i]);
            node[i].v = num[i];
            node[i].id = i;
        }
        sort(node + 1,node + n + 1);
        num[node[1].id] = 1;
        for(int i = 2;i <= n;i++)
            if(node[i].v == node[i - 1].v)
                num[node[i].id] = num[node[i - 1].id];
            else
                num[node[i].id] = num[node[i - 1].id] + 1;
        solve();
    }
}
