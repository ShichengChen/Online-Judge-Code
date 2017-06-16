#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define MAXN 100005
#define lson l,mid,cnt << 1
#define rson mid + 1,r,cnt << 1 | 1
vector<int>vec[MAXN];
int in[MAXN],minn[MAXN << 2],n,m,k;
void build(int l,int r,int cnt)
{
    if(l == r)
    {
        minn[cnt] = in[l];
        return;
    }
    int mid = l + r >> 1;
    build(lson) , build(rson);
    minn[cnt] = min(minn[cnt << 1],minn[cnt << 1 | 1]);
}
int query(int l,int r,int cnt)
{
    if(l == r)return l;
    int mid = l + r >> 1;
    if(minn[cnt << 1 | 1] <= k)return query(rson);
    else return query(lson);
}
void modify(int l,int r,int cnt,int ind,int key)
{
    if(l == r && l == ind)
    {
        minn[cnt] += key;
        return;
    }
    int mid = l + r >> 1;
    if(ind <= mid)modify(lson,ind,key);
    else modify(rson,ind,key);
    minn[cnt] = min(minn[cnt << 1],minn[cnt << 1 | 1]);
}
void solve()
{
    build(1,n,1);
    for(int i = 0;i < n;i++)
    {
        int u = query(1,n,1);
        k -= in[u];
        modify(1,n,1,u,MAXN);
        for(int i = 0;i < vec[u].size();i++)
        {
            int v = vec[u][i];
            in[v]--;
            modify(1,n,1,v,-1);
        }
        if(i != n - 1)printf("%d ",u);
        else printf("%d\n",u);
    }
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&k) != EOF)
    {
        memset(in,0,sizeof(in));
        for(int i = 1;i <= n;i++)vec[i].clear();
        for(int i = 0;i < m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            vec[u].push_back(v);
            in[v]++;
        }
        solve();
    }
}
