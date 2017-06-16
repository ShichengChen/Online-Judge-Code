#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
#define MAXN 5050
int d1[MAXN],d2[MAXN];
vector<pii>vec[MAXN];
void Dijkstra()
{
    priority_queue<pii,vector<pii>,greater<pii> >que;
    memset(d1,0x3f,sizeof(d1));
    memset(d2,0x3f,sizeof(d2));
    d1[1] = 0;
    que.push(pii(0,1));
    while(!que.empty())
    {
        pii cur = que.top(); que.pop();
        int u = cur.second;
        if(d2[u] < cur.first)continue;
        for(int i = 0;i < vec[u].size();i++)
        {
            pii tem = vec[u][i];
            int d = cur.first + tem.second;
            int v = tem.first;
            if(d1[v] > d)
            {
                swap(d1[v],d);
                que.push(pii(d1[v],v));
            }
            if(d2[v] > d && d > d1[v])
            {
                d2[v] = d;
                que.push(pii(d2[v],v));
            }
        }
    }
}
int main()
{
    int n,m,w,u,v;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        for(int i = 1;i <= n;i++)vec[i].clear();
        for(int i = 1;i <= m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            vec[u].push_back(pii(v,w));
            vec[v].push_back(pii(u,w));
        }
        Dijkstra();
        printf("%d\n",d2[n]);
    }
}
