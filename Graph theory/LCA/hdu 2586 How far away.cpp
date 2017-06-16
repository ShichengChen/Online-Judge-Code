#pragma comment(linker, "/STACK:102400000")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
typedef pair<int,int>pii;
#define MAXN 40005
#define MAXM 205
int fa[MAXN],dis[MAXN],ans[MAXM],m,n,quer[MAXN][2];
bool vis[MAXN];
vector<pii>vec[MAXN];
int findfa(int i)
{
    return fa[i] = fa[i] == i ? i : findfa(fa[i]);
}
void tarjan(int u,int fat)
{
    fa[u] = u;
    for(int i = 0;i < vec[u].size();i++)
    {
        int v = vec[u][i].first;
        if(fat == v)continue;
        dis[v] = dis[u] + vec[u][i].second;
        tarjan(v,u);
        fa[v] = u;
    }
    vis[u] = true;
    for(int i = 0;i < m;i++)
    {
        if(quer[i][0] == u || quer[i][1] == u)
        {
            int v = quer[i][1] ^ quer[i][0] ^ u;
            if(vis[v] && vis[u])
                ans[i] = dis[v] + dis[u] - 2 * dis[findfa(v)];
        }
    }
}
int main()
{
    int _,u,v,w;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++)
            vec[i].clear();
        memset(vis,0,sizeof(vis));
        for(int i = 1;i < n;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            vec[u].push_back(pii(v,w));
            vec[v].push_back(pii(u,w));
        }
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d",&u,&v);
            quer[i][0] = u,quer[i][1] = v;
        }
        tarjan(1,-1);
        for(int i = 0;i < m;i++)
            printf("%d\n",ans[i]);
    }
}
