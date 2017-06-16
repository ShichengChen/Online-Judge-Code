#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
#define MAXP 1005
typedef pair<int,int> pii ;
bool vis[MAXP];
int d[MAXP],dp[MAXP],w[MAXP][MAXP];
vector<int>vec[MAXP];
void Dijkstra()
{
    priority_queue<pii,vector<pii>,greater<pii> >que;
    memset(vis,0,sizeof(vis));
    memset(d,-1,sizeof(d));
    que.push(pii(0,2));
    d[2] =0;
    while(!que.empty())
    {
        int u = que.top().second ; que.pop();
        if(vis[u])continue;
        vis[u] = true;
        for(int i = 0;i < vec[u].size();i++)
        {
            int v = vec[u][i];
            if(d[v] == -1 || d[v] > d[u] + w[u][v])
            {
                d[v] = d[u] + w[u][v];
                que.push(pii(d[v],v));
            }
        }
    }
}
int DFS(int u)
{
    if(dp[u])return dp[u];
    int ans = 0;
    for(int i = 0;i < vec[u].size();i++)
        if(d[u] > d[vec[u][i]])
            ans += DFS(vec[u][i]);
    return dp[u] = ans;
}
int main()
{
    int n,m,u,v,minute;
    while(scanf("%d",&n) && n)
    {
        scanf("%d",&m);
        for(int i = 1;i <= n;i++) vec[i].clear();
        for(int i = 1;i <= m;i++)
        {
            scanf("%d%d%d",&u,&v,&minute);
            vec[u].push_back(v);
            vec[v].push_back(u);
            w[u][v] = w[v][u] = minute;
        }
        Dijkstra();
        memset(dp,0,sizeof(dp));
        dp[2] = 1;
        DFS(1);
        printf("%d\n",dp[1]);
    }
}
