#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>
using namespace std;
#define MAX 210
#define INF (1 << 29)
#define sss system("pause");
int flow[MAX][MAX],d[MAX],prev[MAX],ans;
queue <int> que;
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
        while(1)
        {
            memset(d,0,sizeof(d));
            while(!que.empty())que.pop();//must remember to clear queue;
            que.push(0);d[0] = INF;
            while(!que.empty())
            {
                int u = que.front(); que.pop();
                if(d[n + 1])break;
                for(int v = 0;v <= n + 1;v++)if(d[v] < min(d[u],flow[u][v]))
                {
                        d[v] = min(d[u],flow[u][v]);
                        prev[v] = u;
                        que.push(v);
                }
            }
            if(!d[n + 1])break;
            ans += d[n + 1];
            for(int v = n + 1,u = prev[v];;v = u,u = prev[v])
            {
                flow[u][v] -= d[n + 1];
                flow[v][u] += d[n + 1];
                if(u == 0)break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
