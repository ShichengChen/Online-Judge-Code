#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
#define MAXN 90000
#define MAXM 10005
#define INF 0x3f3f3f3f3f3f3f3f
struct Node
{
    int l,r,w;
    bool operator < (const Node & n)const{
        return l < n.l;
    }
}node[MAXM];
LL minn[MAXN << 2];
int ql,qr;
void updata(int l,int r,int cnt,LL val)
{
    if(qr <= l && r <= qr)
    {
        minn[cnt] = min(val,minn[cnt]);
        return;
    }
    int mid = l + r >> 1;
    if(qr <= mid)
        updata(l,mid,cnt << 1,val);
    if(qr > mid)
        updata(mid + 1,r,cnt << 1 | 1,val);
    minn[cnt] = min(minn[cnt << 1],minn[cnt << 1 | 1]);
}
LL query(int l,int r,int cnt)
{
    if(ql <= l && r <= qr)
        return minn[cnt];
    int mid = l + r >> 1;
    LL ans = INF;
    if(ql <= mid)
        ans = min(ans,query(l,mid,cnt << 1));
    if(mid < qr)
        ans = min(ans,query(mid + 1,r,cnt << 1 | 1));
    return ans;
}
int main()
{
    int n,u,v;
    while(scanf("%d%d%d",&n,&u,&v) != EOF)
    {
        v += 2;
        memset(minn,0x3f,sizeof(minn));
        ql = qr = ++u;
        updata(1,v,1,0);
        for(int i = 0;i < n;i++)
            scanf("%d%d%d",&node[i].l,&node[i].r,&node[i].w);
        sort(node,node + n);
        for(int i = 0;i < n;i++)
        {
            ql = node[i].l + 1;
            qr = node[i].r + 2;
            LL val = query(1,v,1);
            updata(1,v,1,val + node[i].w);
        }
        ql = qr = v;
        LL ans = query(1,v,1);
        if(ans >= INF)puts("-1");
        else printf("%lld\n",ans);
    }
}
