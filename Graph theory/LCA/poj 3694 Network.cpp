#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define MAXN 100010
#define MAXM 200020
int dfn[MAXN],fa[MAXN],head[MAXN],n,m,cut,cnt,number;
bool cutl[MAXN];
struct Edge
{
    int v,next;
}edge[MAXM << 1];
void insert(int x,int y)
{
    edge[number].next = head[x];
    edge[number].v = y;
    head[x] = number++;
}
int dfs(int u,int fat)
{
    int lowu = dfn[u] = ++cnt;
    for(int i = head[u];i != -1;i = edge[i].next)
    {
        int v = edge[i].v;
        if((i ^ 1) == fat)continue;
        if(!dfn[v])
        {
            fa[v] = u;
            int lowv = dfs(v,i);
            lowu = min(lowv,lowu);
            if(dfn[u] < lowv)
            {
                cut++;
                cutl[v] = true;
            }
        }
        else lowu = min(lowu,dfn[v]);
    }
    return lowu;
}
void lca(int u,int v)
{
    if(dfn[u] < dfn[v])swap(u,v);
    while(dfn[u] < dfn[v])
    {
        if(cutl[v])
            cutl[v] = false,cut--;
        v = fa[v];
    }
    while(u != v)
    {
        if(cutl[v])
            cutl[v] = false,cut--;
        if(cutl[u])
            cutl[u] = false,cut--;
        v = fa[v],u = fa[u];
    }
}
void tarjan()
{
    memset(dfn,0,sizeof(dfn));
    memset(cutl,0,sizeof(cutl));
    cut = cnt = 0;
    dfs(1,-1);
    int q,u,v;
    scanf("%d",&q);
    for(int i = 0;i < q;i++)
    {
        scanf("%d%d",&u,&v);
        lca(u,v);
        printf("%d\n",cut);
    }
}
int main()
{
    int k = 0;
    while(scanf("%d%d",&n,&m), m | n)
    {
        number = 0;
        memset(head,-1,sizeof(head));
        for(int i = 0;i < m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            insert(u,v),insert(v,u);
        }
        printf("Case %d:\n",++k);
        tarjan();
        puts("");
    }
}
