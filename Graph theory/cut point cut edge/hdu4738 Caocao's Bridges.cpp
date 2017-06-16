#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXL 2100000
#define MAXP 1200
#define INF (1 << 29)
int first[MAXP];
int matrix[MAXP][MAXP];
int dfn[MAXP],depth,low[MAXP],minn;
int begin_number;
struct Edge
{
    int v,next;
    int w;
}edge[MAXL];
void insert(int x,int y,int w)
{
        edge[begin_number].v = y;
        edge[begin_number].next = first[x];
        edge[begin_number].w = w;
        first[x] = begin_number++;
}
void init()
{
    begin_number = 0;
    memset(first,-1,sizeof(first));
    memset(matrix,0,sizeof(matrix));
    memset(dfn,0,sizeof(dfn));
}
void DFS(int u,int fa)
{
    dfn[u] = low[u] = ++depth;
    for(int i = first[u];i != -1;i = edge[i].next){
        if(dfn[edge[i].v] == 0)
        {
            DFS(edge[i].v,u);
            low[u] = min(low[u],low[edge[i].v]);
            if(dfn[u] < low[edge[i].v] && matrix[u][edge[i].v] == 1)
                minn = min(minn,edge[i].w);
        }
        else if(edge[i].v != fa)  low[u] = min(low[u],dfn[edge[i].v]);}
}
int tarjan(int n)
{
    depth = 0;minn = INF;
    DFS(1,0);
    for(int i = 1;i <= n;i++)if(!dfn[i])return 0;
    if(minn == INF)return -1;
    else return max(1,minn);
}
int main()
{
    int N,M;
    while(scanf("%d%d",&N,&M),N,M)
    {
        init();
        for(int i = 0;i < M;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            matrix[u][v]++;  matrix[v][u]++;
            insert(u,v,w);    insert(v,u,w);
        }
        printf("%d\n",tarjan(N));
    }
}
