#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
typedef pair<int,int>pii;
#define MAXN 50005
#define LOG 15
#define lowbit(i) (i & -i)
vector<pii>vec[MAXN];
int fa[MAXN][LOG],ind[MAXN << 1],cnt,deep[MAXN];
int prefix[MAXN << 1];
int sum(int i)
{
    int ans = 0;
    for(;i;i -= lowbit(i))ans += prefix[i];
    return ans;
}
void modify(int i,int maxn,int key)
{
    for(;i < maxn;i += lowbit(i))
        prefix[i] += key;
}
void dfs(int u,int fat,int d)
{
    fa[u][0] = fat;
    deep[u] = d;
    ind[u] = cnt;
    for(int i = 1;i < LOG;i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for(int i = 0;i < vec[u].size();i++)
    {
        int v = vec[u][i].first,val = vec[u][i].second;
        if(v == fat)continue;;
        modify(++cnt,MAXN << 1,val);
        dfs(v,u,d + 1);
        modify(++cnt,MAXN << 1,-val);
    }
}
int LCA(int u,int v)
{
    if(deep[u] < deep[v])swap(u,v);
    for(int i = LOG - 1;i >= 0;i--)
        if(deep[u] - deep[v] >> i & 1)
        u = fa[u][i];
    if(u == v)return u;
    for(int i = LOG - 1;i >= 0;i--)
        if(fa[u][i] != fa[v][i])
            u = fa[u][i],v = fa[v][i];
    return fa[u][0];
}
int main()
{
    int n,m,u,v,val,q;
    char c[2];
    while(scanf("%d%d",&n,&m) != EOF)
    {
        memset(prefix,0,sizeof(prefix));
        memset(fa,-1,sizeof(fa));
        while(m--)
        {
            scanf("%d%d%d%s",&u,&v,&val,c);
            vec[u].push_back(pii(v,val));
            vec[v].push_back(pii(u,val));
        }
        cnt = 1;
        dfs(1,0,0);
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d",&u,&v);
            int fat = LCA(u,v);
            int ans = sum(ind[u]) + sum(ind[v]) - 2 * sum(ind[fat]);
            printf("%d\n",ans);
        }
    }
}
