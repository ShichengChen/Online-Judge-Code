#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>
using namespace std;
#define MAX 210
#define INF (1 << 29)
int flow[MAX][MAX],d[MAX],maxflow,ans;
queue <int> que;
bool bfs(int n)
{
    memset(d,0,sizeof(d));
    d[0] = 1;que.push(0);
    while(!que.empty())
    {
        int u = que.front();que.pop();
        for(int v = 0;v <= n + 1;v++)if(flow[u][v] && !d[v])
        {
                d[v] = d[u] + 1;
                que.push(v);
        }
    }
    if(d[n + 1])return true;
    else return false;
}
int dinic(int u,int n,int maxflow)
{
    if(u == n + 1)
        return maxflow;
    int curmax = 0;
    for(int v = 0;v <= n + 1;v++)if(d[v] == d[u] + 1 && flow[u][v])
    {
        int temp = maxflow;
        maxflow = min(maxflow,flow[u][v]);
        //if some small thing was left over,you must remember it;
        maxflow = min(dinic(v,n,maxflow),maxflow);
        temp -= maxflow;
        curmax += maxflow;
        flow[u][v] -= maxflow;
        flow[v][u] += maxflow;
        maxflow = temp;
        if(!maxflow)return curmax;
    }
    return curmax;
}
int main()
{
    int n,np,nc,m;
    while(scanf("%d%d%d%d",&n,&np,&nc,&m) != EOF)
    {
        memset(flow,0,sizeof(flow));
        ans = 0;
        int u,v,w;char ss[30];
        for(int i = 0;i < m;i++)
        {
            scanf("%s",ss);
            sscanf(ss,"(%d,%d)%d",&u,&v,&w);
            flow[u + 1][v + 1] = w;
        }
        for(int i = 0;i < np;i++)
        {
            scanf("%s",ss);
            sscanf(ss,"(%d)%d",&v,&w);
            flow[0][v + 1] = w;
        }
        for(int i = 0;i < nc;i++)
        {
            scanf("%s",ss);
            sscanf(ss,"(%d)%d",&u,&w);
            flow[u + 1][n + 1] = w;
        }
        while(bfs(n))
            ans += dinic(0,n,INF);
        printf("%d\n",ans);
    }
    return 0;
}
