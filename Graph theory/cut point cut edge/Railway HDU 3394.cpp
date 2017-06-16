/*
using v as factor to decide when to stop stack.pop;
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define MAXP 11000
#define MAXE 110000
vector<int>vec[MAXP];
int clash_num,no_need,cnt,top;
int dfn[MAXP],low[MAXP],vis[MAXP];
int stack[MAXE],block[MAXE];
void check(int u,int v)
{
    block[0] = 0;
    memset(vis,0,sizeof(vis));
    do
    {
        vis[stack[top]] = 1;
        block[++block[0]] = stack[top--];
    }while(stack[top + 1] != v);
    block[++block[0]] = u;
    vis[u] = 1;
    int edge = 0 ;
    for(int i = 1;i <= block[0];i++)
        for(unsigned j = 0;j < vec[block[i]].size();j++)
            if(vis[vec[block[i]][j]])
                edge++;
    edge /= 2;
    if(edge < block[0])no_need++;
    else if(edge > block[0])clash_num += edge;
}
void Tarjan(int u,int fa)
{
    dfn[u] = low[u] = ++cnt;
    stack[++top] = u;
    for(unsigned i = 0;i < vec[u].size();i++)if(vec[u][i] != fa)
    {
        int v = vec[u][i];
        if(!dfn[v])
        {
            Tarjan(v,u);
            low[u] = min(low[u],low[v]);
            if(dfn[u] <= low[v])
                check(u,v);
        }
        else low[u] = min(dfn[v],low[u]);
    }
}
void init(int n)
{
    clash_num = no_need = cnt = 0;
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    for(int i = 0;i < n;i++)vec[i].clear();
}
int main()
{
    int n,m,u,v;
    while(scanf("%d%d",&n,&m) ,n | m)
    {
        init(n);
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d",&u,&v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        for(int u = 0;u < n;u++)if(!dfn[u])
            Tarjan(u,-1);
        printf("%d %d\n",no_need,clash_num);
    }
}
