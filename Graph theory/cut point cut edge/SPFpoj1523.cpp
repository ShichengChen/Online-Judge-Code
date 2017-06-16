#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAX 1200
struct EGDE
{
    int v,next;
}edge[MAX];
int first[MAX],dfn[MAX],low[MAX],cut[MAX];
int number,cnt;
void insert(int x,int y)
{
    edge[number].next = first[x];
    edge[number].v = y;
    first[x] = number++;
    edge[number].next = first[y];
    edge[number].v = x;
    first[y] = number++;
}
void init()
{
    number = 0;cnt = 0;
    memset(first,-1,sizeof(first));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(cut,0,sizeof(cut));
}
void Tarjan(int u,int fa)
{
    dfn[u] = low[u] = ++cnt;
    int child = 0;
    for(int i = first[u];i != -1;i = edge[i].next)
    {
        if(!dfn[edge[i].v])
        {
            child++;
            Tarjan(edge[i].v,u);
            low[u] = min(low[u],low[edge[i].v]);
            if(dfn[u] <= low[edge[i].v])
                cut[u]++;
        }
        else if(edge[i].v != fa)
            low[u] = min(low[u],dfn[edge[i].v]);
    }
    if(child == 1 && fa == -1)cut[u] = 0;
}
int main()
{
    int x,y,n,_ = 1;
    while(scanf("%d",&x),x)
    {
        init();
        scanf("%d",&y);
        insert(x,y);
        n = 1;
        while(scanf("%d",&x),x)
        {
            scanf("%d",&y);
            insert(x,y);
            n++;
        }
        Tarjan(y,-1);
        printf("Network #%d\n",_++);
        bool success = 1;
        for(int i = 1;i <= n;i++)if(cut[i])
        {
            if(y != i)cut[i]++;
            printf("  SPF node %d leaves %d subnets\n",i,cut[i]);
            success = 0;
        }
        if(success)puts("  No SPF nodes");
        printf("\n");
    }
    return 0;
}
