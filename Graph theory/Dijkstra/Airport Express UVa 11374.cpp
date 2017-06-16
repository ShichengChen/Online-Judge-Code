#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int>pii;
#define MAXP 505
#define MAXE 2005
int next[MAXP],prev[MAXP],dbegin[MAXP],dend[MAXP],w[MAXP][MAXP];
bool vis[MAXP];
vector<int>vec[MAXP];
void Dijkstra(int first,int * d,int * pre)
{
        memset(vis,0,sizeof(vis));
        priority_queue<pii,vector<pii>,greater<pii> >que;
        que.push(pii(0,first));
        d[first] = 0;
        while(!que.empty())
        {
            pii node = que.top() ; que.pop();
            int u = node.second;
            if(vis[u])continue;
            vis[u] = 1;
            for(int i = 0;i < vec[u].size();i++)
            {
                int v = vec[u][i];
                if(d[v] > d[u] + w[u][v])
                {
                    d[v] = d[u] + w[u][v];
                    pre[v] = u;
                    que.push(pii(d[v],v));
                }
            }
        }
}
void print(int v)
{
    int u = prev[v];
    if(u == -1)return;
    print(u);
    printf(" %d",v);
}
void solve(int first,int last)
{
    int k,u,v,minute;
    scanf("%d",&k);
    int minn = dbegin[last],stop = last,next_stop;
    for(int i = 1;i <= k;i++)
    {
        scanf("%d%d%d",&u,&v,&minute);
        if(dbegin[u] + minute + dend[v] < minn)
        {
            minn = dbegin[u] + minute + dend[v];
            stop = u;
            next_stop  = v;
        }
        if(dbegin[v] + minute + dend[u] < minn)
        {
            minn = dbegin[v] + minute + dend[u];
            stop = v;
            next_stop  = u;
        }
    }
    if(stop == last)
    {
        printf("%d",first);
        print(last);
        puts("");
        puts("Ticket Not Used");
    }
    else
    {
        printf("%d",first);
        print(stop);
        int u = next_stop;
        while(1)
        {
            printf(" %d",u);
            u = next[u];
            if(u == -1)break;
        }
        printf("\n%d\n",stop);
    }
    printf("%d\n",minn);
}
int main()
{
    int n,first,last,u,v,m,minute,cas = 0;
    while(scanf("%d%d%d",&n,&first,&last) != EOF)
    {
        if(cas != 0)   printf("\n");
        cas++;
        for(int i = 1;i <= MAXP;i++)vec[i].clear();
        scanf("%d",&m);
        for(int i = 1;i <= m;i++)
        {
            scanf("%d%d%d",&u,&v,&minute);
            vec[u].push_back(v);
            vec[v].push_back(u);
            w[u][v] = w[v][u] = minute;
        }
        memset(dbegin,0x3f,sizeof(dbegin));
        prev[first] = -1 , next[last] = -1;
        Dijkstra(first,dbegin,prev);
        memset(dend,0x3f,sizeof(dend));
        Dijkstra(last,dend,next);
        solve(first,last);
    }
}
