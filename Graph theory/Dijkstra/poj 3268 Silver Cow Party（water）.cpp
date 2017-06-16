#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int>pii;
#define MAXN 1010
void Dijkstra(int x,int * d,vector<pii> * vec)
{
    priority_queue<pii,vector<pii>,greater<pii> >que;
    que.push(pii(0,x));
    d[x] = 0;
    while(!que.empty())
    {
        pii cur = que.top(); que.pop();
        int u = cur.second;
        if(d[u] < cur.first)continue;
        for(int i = 0;i < vec[u].size();i++)
        {
            int v = vec[u][i].first , w = vec[u][i].second;
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                que.push(pii(d[v],v));
            }
        }
    }
}
vector<pii>vec[MAXN],rvec[MAXN];
int d1[MAXN],d2[MAXN];
int main()
{
    int n,m,x,u,v,w;
    while(scanf("%d%d%d",&n,&m,&x) != EOF)
    {
        for(int i = 1;i <= n;i++)
            vec[i].clear(),rvec[i].clear();
        for(int i = 1;i <= m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            vec[u].push_back(pii(v,w));
            rvec[v].push_back(pii(u,w));
        }
        memset(d1,0x3f,sizeof(d1));
        Dijkstra(x,d1,vec);
        memset(d2,0x3f,sizeof(d2));
        Dijkstra(x,d2,rvec);
        int ans = 0;
        for(int i = 1;i <= n;i++)
            ans = max(ans,d1[i] + d2[i]);
        printf("%d\n",ans);
    }
}
