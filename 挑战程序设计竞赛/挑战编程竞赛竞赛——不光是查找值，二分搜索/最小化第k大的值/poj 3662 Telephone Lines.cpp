#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int>pii;
#define MAXN 1005
#define INF 0x3f3f3f3f
int d[MAXN],n,k,m;
bool vis[MAXN];
vector<pii>vec[MAXN];
bool Dijkstra(int val)
{
    priority_queue<pii,vector<pii>,greater<pii> >que;
    memset(d,0x3f,sizeof(d));
    memset(vis,0,sizeof(vis));
    d[1] = 0;vis[1] = 0;
    que.push(pii(-1,1));
    while(!que.empty())
    {
        int u = que.top().second;que.pop();
        if(vis[u])continue;
        vis[u] = true;
        for(int i = 0;i < vec[u].size();i++)
        {
            int v = vec[u][i].first,w = vec[u][i].second;
            d[v] = min(d[v],d[u] + (w > val));
            if(d[v] > k)continue;
            else que.push(pii(d[v],v));
        }
    }
    return d[n] > k;
}
int binary()
{
    int l = 0,r = 1e6 + 1;
    if(Dijkstra(r))return -1;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(Dijkstra(mid))l = mid + 1;
        else r = mid;
    }
    return l;
}
int main()
{
    int u,v,w;
    while(scanf("%d%d%d",&n,&m,&k) != EOF)
    {
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            vec[u].push_back(pii(v,w));
            vec[v].push_back(pii(u,w));
        }
        int ans = binary();
        printf("%d\n",ans);
    }
}
