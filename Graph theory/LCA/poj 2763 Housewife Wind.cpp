#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 100005
#define LOG 18
#define lowbit(i) (i & -i)
int prefix[MAXN << 1],in[MAXN],out[MAXN],fa[LOG][MAXN],deep[MAXN];
int cnt,ind[MAXN],number,first[MAXN],val[MAXN];
struct Edge
{
    int v,next,id;
}edge[MAXN << 1];
void modify(int i,int r,int key)
{
    for(;i < r;i += lowbit(i))
        prefix[i] += key;
}
int sum(int i)
{
    int total = 0;
    for(;i;i -= lowbit(i))
        total += prefix[i];
    return total;
}
void insert(int x,int y,int i)
{
    edge[number].next = first[x];
    edge[number].v = y;
    edge[number].id = i;
    first[x] = number++;
}
void dfs(int u,int father,int d)
{
    fa[0][u] = father;
    deep[u] = d;
    for(int i = 1;i < LOG;i++)
        fa[i][u] = fa[i - 1][fa[i - 1][u]];
    for(int i = first[u];i != -1;i = edge[i].next)
    {
        int v = edge[i].v;
        if(v == father)continue;
        ind[v] = in[edge[i].id] = ++cnt;
        modify(cnt,MAXN << 1,val[edge[i].id]);
        dfs(v,u,d + 1);
        out[edge[i].id] = ++cnt;
        modify(cnt,MAXN << 1,-val[edge[i].id]);
    }
}
int LCA(int u,int v)
{
    if(deep[u] < deep[v])swap(u,v);
    for(int i = LOG - 1;i >= 0;i--)
        if(deep[u] - deep[v] & (1 << i))
            u = fa[i][u];
    if(u == v)return u;
    for(int i = LOG - 1;i >= 0;i--)
        if(fa[i][u] != fa[i][v])
        u = fa[i][u],v = fa[i][v];
    return fa[0][u];
}
int main()
{
    int n,m,s,type,u,v,w,x;
    while(scanf("%d%d%d",&n,&m,&s) != EOF)
    {
        memset(prefix,0,sizeof(prefix));
        memset(first,-1,sizeof(first));
        number = 0;
        for(int i = 1;i < n;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            insert(u,v,i);insert(v,u,i);
            val[i] = w;
        }
        cnt = 1;
        dfs(1,0,0);
        u = s;
        while(m--)
        {
            scanf("%d",&type);
            if(type)
            {
                scanf("%d%d",&x,&w);
                int key = w - val[x];
                modify(in[x],MAXN << 1,key);
                modify(out[x],MAXN << 1,-key);
                val[x] = w;
            }
            else
            {
                scanf("%d",&v);
                int father = LCA(u,v);
                printf("%d\n",sum(ind[u]) + sum(ind[v]) - 2 * sum(ind[father]));
                u = v;
            }
        }
    }
}
