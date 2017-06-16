///only is thinking
/*
using low[u] renew low[v] is wrong
because in the same edge-bcc maybe have different low;
*/
///need testing
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define N 5005
vector<int>vec[N];
int dfn[N],low[N],id[N],stack[N],du[N];
bool G[N][N];
int cnt,top,bcc;
void dfs(int u,int fa)
{
    dfn[u] = low[u] = ++cnt;
    stack[++top] = u;
    for(int i = 0;i < vec[u].size();i++)if(vec[u][i] != fa)
    {
            int v = vec[u][i];
            if(!dfn[v])
            {
                    dfs(v,u);
                    low[u] = min(low[u],low[v]);
                    if(dfn[u] < low[v])
                    {
                            bcc++;
                            while(1)
                            {
                                id[stack[top--]] = bcc;
                                if(stack[top + 1] == v)break;
                            }
                    }
            }
            else low[u] = min(low[u],dfn[v]);
    }
}
inline int tarjan(int n)
{
    dfs(1,-1);
    for(int i = 1;i <= n;i++)
        for(int j = 0;j < vec[i].size();j++)
            if(id[i] - id[vec[i][j]])
                du[id[vec[i][j]]]++;
    int ans = 0;
    for(int i = 0;i <= bcc;i++)if(du[i] == 1)ans++;
    return (ans + 1) / 2;
}
inline void init(int n)
{
    bcc = cnt = top = 0;
    memset(dfn,0,sizeof(dfn));
    memset(du,0,sizeof(du));
    memset(id,0,sizeof(id));
    memset(G,0,sizeof(G));
    for(int i = 1;i <= n;i++)vec[i].clear();
}
int main()
{
    int n,m,x,y;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        init(n);
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d",&x,&y);
            if(G[x][y] || G[y][x])continue;
            vec[x].push_back(y);
            vec[y].push_back(x);
            G[x][y] = G[y][x] = 1;
        }
        printf("%d\n",tarjan(n));
    }
    return 0;
}
