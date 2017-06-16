#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<map>
#include<iterator>
using namespace std ;
typedef pair<int,int>pii;
#define MAXN 1005
int first[MAXN],d[MAXN],e,n,point,root = 1;
struct Edge
{
    int v,next;
}edge[MAXN << 1];
bool vis[MAXN];
void insert(int u,int v)
{
    edge[e].next = first[u];
    edge[e].v = v;
    first[u] = e++;
}
bool dfs(int u)
{
    point++;
    vis[u] = true;
    int v = -1;
    for(int i = first[u];i != -1;i = edge[i].next)if(!vis[edge[i].v])
        if(v == -1 || d[edge[i].v] < d[v])v = edge[i].v;
    if(v != -1)dfs(v);
    return point == n;
}
bool solve()
{
    memset(vis,0,sizeof(vis));
    point = 0;
    return dfs(root);
}
int main ()
{
    while(scanf("%d",&n) != EOF)
    {
        memset(first,-1,sizeof(first));
        e = 0;
        memset(d,0,sizeof(d));
        for(int i = 0;i < n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            d[u]++,d[v]++;
            insert(u,v);
            insert(v,u);
        }
        root = 1;
        for(int i = 1;i <= n;i++)
            if(d[root] > d[i])root = i;
        if(solve())puts("YES");
        else puts("NO");
    }
}
