#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int>pii;
#define INF 0x3f3f3f3f
#define MAXN 1010
vector<pii>vec[MAXN];
int d[MAXN],cnt[MAXN];
bool inque[MAXN];
bool bellman(int n)
{
    memset(d,0x3f,sizeof(d));
    memset(inque,false,sizeof(inque));
    memset(cnt,0,sizeof(cnt));
    queue<int>que;
    d[1] = 0;inque[1] = 1;
    que.push(1);
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
                    if(++cnt[v] > n)return true;
                    que.push(v);
                }
            }
        }
    }
    return false;
}
int main()
{
    int n,m1,m2,u,v,w;
    while(scanf("%d%d%d",&n,&m1,&m2) != EOF)
    {
        for(int i = 1;i <= n;i++)
        {
            vec[i].clear();
            if(i != 1)
                vec[i].push_back(pii(i - 1,0));
        }
        for(int i = 0;i < m1;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            vec[u].push_back(pii(v,w));
        }
        for(int i = 0;i < m2;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            vec[v].push_back(pii(u,-w));
        }
        if(bellman(n)) puts("-1");
        else
        {
            if(d[n] == INF)puts("-2");
            else printf("%d\n",d[n]);
        }
    }
}
