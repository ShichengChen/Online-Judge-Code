#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int>pii;
#define INF 0x3f3f3f3f
#define MAXN 50010
vector<pii>vec[MAXN];
int d[MAXN],cnt[MAXN];
bool inque[MAXN];
bool bellman(int i)
{
    memset(d,0x3f,sizeof(d));
    memset(inque,false,sizeof(inque));
    queue<int>que;
    d[i] = 0;inque[i] = 1;
    que.push(i);
    while(!que.empty())
    {
        int u = que.front();que.pop();
        inque[u] = 0;
        for(int i = 0;i < vec[u].size();i++)
        {
            int v = vec[u][i].first,w = vec[u][i].second;
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                if(!inque[v])
                {
                    inque[v] = 1;
                    que.push(v);
                }
            }
        }
    }
}
int main()
{
    int m,u,v,w;
    while(scanf("%d",&m) != EOF)
    {
        int n = 0;
        for(int i = 0;i < MAXN;i++)vec[i].clear();
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            n = max(n,v);
            vec[v].push_back(pii(u - 1,-w));
        }
        for(int i = 0;i <= n;i++)
        {
            vec[i + 1].push_back(pii(i,0));
            vec[i].push_back(pii(i + 1,1));
        }
        bellman(n);
        printf("%d\n",-d[0]);
    }
}
