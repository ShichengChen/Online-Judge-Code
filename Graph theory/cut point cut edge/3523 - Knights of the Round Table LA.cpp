#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define MAXP 1005
#define MAXE 1000010
bool G[MAXP][MAXP],id[MAXP],odd[MAXP];
int dfn[MAXP],low[MAXP],stack[MAXP],color[MAXP];
int cnt,top,n,m;
bool bipartite(int u)
{
    for(int i = 1;i <= n;i++)if(!G[u][i] && u != i)
    {
        if(id[i] == 0)continue;
        if(color[u] == color[i])return false;
        else if(!color[i])
        {
            color[i] = 3 - color[u];
            if(!bipartite(i))return false;
        }
    }
    return true;
}
int Tarjan(int u,int fa)
{
    dfn[u] = low[u] = ++cnt;
    stack[++top] = u;
    for(int i = 1;i <= n;i++)if(G[u][i] == 0 && u != i && i != fa)
    {
        if(dfn[i] == 0)
        {
            Tarjan(i,u);
            low[u] = min(low[i],low[u]);
            if(dfn[u] <= low[i])
            {
                memset(id,0,sizeof(id));
                int knight = 1;
                id[u] = true;
                do
                {
                    int cur = stack[top--];
                    id[cur] = true;
                    knight++;
                }while(stack[top + 1] != i);
                if(knight >= 3)
                {
                    memset(color,0,sizeof(color));
                    color[u] = 1;
                    if(bipartite(u) == false)
                        for(int i = 1;i <= n;i++)if(id[i])
                            odd[i] = true;
                }
            }
        }
        else low[u] = min(low[u],dfn[i]);
    }
}
int find_bcc_and_odd_circle()
{
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(odd,0,sizeof(odd));
    cnt = top = 0;
    for(int i = 1;i <= n;i++)if(!dfn[i])
        Tarjan(i,-1);
    int ans = n;
    for(int i = 1;i <= n;i++)if(odd[i])ans--;
    return ans;
}
int main()
{
    int u,v;
    while(scanf("%d%d",&n,&m) && (n | m))
    {
        memset(G,0,sizeof(G));
        for(int i = 1;i <= m;i++)
        {
            scanf("%d%d",&u,&v);
            G[u][v] = G[v][u] = 1;
        }
        int ans = find_bcc_and_odd_circle();
        printf("%d\n",ans);
    }
}
