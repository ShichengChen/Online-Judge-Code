#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;
typedef pair<int,int>pii;
typedef long long LL;
#define MAXN 100
LL d[MAXN];
bool vis[MAXN];
vector<int>vec[MAXN];
int check_add(int v)
{
    if(v <= 26)return 1;
    v = (v / 20 + (bool)(v % 20));
    v///
}
LL Dijkstra(int end,int aim)
{
    priority_queue<pii,vector<pii> greater<pii> >que;
    memset(d,-1,sizeof(d));
    memset(vis,0,sizeof(vis));
    que.push(pii(aim,end));
    while(!que.empty())
    {
        int u = que.top().second ; que.pop();
        if(vis[u])continue;
        vis[u] = true;
        for(int i = 0;i < vec[u].size();i++)
        {
            int v = vec[u][i];
            int add = check_add(v);
            if(d[v] == -1 || d[v] > d[u] + add)
            {
                d[v] = d[u] + add;
                que.push(pii(d[v],v));
            }
        }
    }
    return d[begin];
}
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {

    }
    LL ans = Dijkstra(end,aim);
    printf("%lld\n",ans);
}
