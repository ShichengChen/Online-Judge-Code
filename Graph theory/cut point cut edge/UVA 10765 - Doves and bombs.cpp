#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int>pii;
#define MAXN 10005
vector<int>vec[MAXN];
int dfn[MAXN],cut[MAXN],cnt;
int dfs(int u,int fa)
{
    int lowu = dfn[u] = ++cnt;
    int child = 0;
    for(int i = 0;i < vec[u].size();i++)
    {
        int v = vec[u][i];
        if(!dfn[v])
        {
            child++;
            int lowv = dfs(v,u);
            lowu = min(lowv,lowu);
            if(dfn[u] <= lowv)
                cut[u]++;
        }
        else if(v != fa)
            lowu = min(lowu,dfn[v]);
    }
    if(u || child != 1)cut[u]++;
    return lowu;
}
void Tarjan(int n,int m)
{
    memset(dfn,0,sizeof(dfn));
    memset(cut,0,sizeof(cut));
    cnt = 0;
    dfs(0,-1);
    priority_queue<pii>que;
    for(int i = 0;i < n;i++)
        que.push(pii(cut[i],-i));
    for(int i = 1;i <= m;i++)
    {
        pii u = que.top();que.pop();
        printf("%d %d\n",-u.second,u.first);
    }
    puts("");
}
int main()
{
    int n,m,u,v;
    while(scanf("%d%d",&n,&m), n | m)
    {
        for(int i = 0;i < n;i++)vec[i].clear();
        while(scanf("%d%d",&u,&v), u + 1 , v + 1)
            vec[u].push_back(v),vec[v].push_back(u);
        Tarjan(n,m);
    }
}
