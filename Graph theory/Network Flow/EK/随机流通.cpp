#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;
#define MAX 210
#define INF (1 << 29)
#define sss system("pause");
int flow[MAX][MAX],prev[MAX],ans;
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
            memset(prev,-1,sizeof(prev));
            bool success = 0;
            while(!que.empty())que.pop();//must remember to clear queue;
            que.push(0);
            while(!que.empty())
            {
                int u = que.front(); que.pop();
                for(int v = 0;v <= n + 1;v++)if(flow[u][v] > 0 && prev[v] == -1)
                {
                        prev[v] = u;
                        if(v == n + 1)
                        {
                            success = 1;
                            break;
                        }
                        que.push(v);
                }
                if(success)break;
            }
            if(prev[n + 1] == -1)break;
            int minflow = INT_MAX;
            for(int v = n + 1;v != 0;v = prev[v])
                minflow = min(minflow,flow[prev[v]][v]);
            for(int v = n + 1;v != 0;v = prev[v])
            {
                flow[prev[v]][v] -= minflow;
                flow[v][prev[v]] += minflow;
            }
            ans += minflow;
        }
        printf("%d\n",ans);
    }
    return 0;
}
