#pragma comment(linker, "/STACK:102400000,102400000")
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100005
#define MAXM 300005
int n,m,_,e,top,cnt,bcc,odd,even,ans1,ans2;
int first[MAXN],dfn[MAXN],stack[MAXN];
int id[MAXN],color[MAXN],vis[MAXN];
struct Edge
{
    int next,v;
}edge[MAXM << 1];
void insert(int u,int v)
{
    edge[e].v = v;
    edge[e].next = first[u];
    first[u] = e++;
}
void bipartite(int u,int bcc)
{
    for(int i = first[u];i != -1;i = edge[i].next)if(!vis[i] && !vis[i ^ 1])
    {
        int v = edge[i].v;
        if(id[v] != bcc)continue;
        vis[i] = vis[i ^ 1] = true;
        if(color[v] && color[u] != color[v])even++;
        if(color[u] == color[v])odd++;
        else if(!color[v])
        {
            color[v] = 3 - color[u];
            bipartite(v,bcc);
        }
    }
}
void search(int bcc,int u)
{
    even = odd = 0;
    color[u] = 1;
    bipartite(u,bcc);
    if(odd > 1)even = true;
    ans1 = max(odd,ans1);
    ans2 = max(ans2,even);
}
int dfs(int u,int fa)
{
    int lowu = dfn[u] = ++cnt;
    stack[++top] = u;
    for(int i = first[u];i != -1;i = edge[i].next)if((i ^ 1) != fa)
    {
        int v = edge[i].v;
        if(!dfn[v])
        {
            int lowv = dfs(v,i);
            lowu = min(lowu,lowv);
            if(dfn[u] < lowv)
            {
                bcc++;
                do
                {
                    id[stack[top--]] = bcc;
                }while(stack[top + 1] != v);
            }
        }
        else lowu = min(lowu,dfn[v]);
    }
    return lowu;
}
void solve()
{
    ans1 = ans2 = 0;
    memset(dfn,0,sizeof(dfn));
    memset(color,0,sizeof(color));
    memset(id,0,sizeof(id));
    memset(vis,0,sizeof(vis));
    bcc = cnt = top = 0;
    for(int i = 1;i <= n;i++)if(!dfn[i])dfs(1,-1);
    for(int u = 1;u <= n;u++)
        if(!color[u])
        {
            search(id[u],u);
            if(ans1 && ans2)return;
        }
}
int main()
{
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        memset(first,-1,sizeof(first));
        e = 0;
        for(int i = 0;i < m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            insert(u,v),insert(v,u);
        }
        solve();
        if(ans1)puts("YES");
        else puts("NO");
        if(ans2)puts("YES");
        else puts("NO");
    }
}
