#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXP 110
int cost[MAXP][MAXP],mincost[MAXP];
bool used[MAXP];
void init()
{
    memset(cost,0x3f,sizeof(cost));
    memset(mincost,0x3f,sizeof(mincost));
    memset(used,0,sizeof(used));
}
int prim(int n)
{
    int ans = 0;
    mincost[1] = 0;
    while(1)
    {
        int v = -1;
        for(int u = 1;u <= n;u++)if(!used[u] && (v == -1 || mincost[u] < mincost[v]))v = u;
        if(v == -1)break;
        ans += mincost[v];
        used[v] = 1;
        for(int u = 1;u <= n;u++)mincost[u] = min(mincost[u],cost[u][v]);
    }
    return ans;
}
int main()
{
    int n,num,u,v,w;
    while(scanf("%d",&n),n)
    {
        init();
        for(int i = 1;i <= n * (n - 1) / 2;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            cost[u][v] = cost[v][u] = w;
        }
        int ans = prim(n);
        printf("%d\n",ans);
    }
}
