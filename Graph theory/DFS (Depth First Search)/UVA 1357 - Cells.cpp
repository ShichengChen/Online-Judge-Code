#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef pair<int,int>pii;
#define MAXN 20000005
#define MAXM 1000005
int first[MAXN],next[MAXN],head[MAXN],stack[MAXN],vis[MAXN];
int top,number;
struct Edge
{
    int v,next;
}edge[MAXN];
void insert(int u,int v)
{
    edge[number].next = head[u];
    edge[number].v = v;
    head[u] = number++;
}
pii ans[MAXN];
void init()
{
    memset(head,0,sizeof(head));
    memset(first,0,sizeof(first));
    memset(vis,0,sizeof(vis));
}
int main()
{
    int _,n,m,cur,u,v;
    for(int kcas = scanf("%d",&_);kcas <= _;kcas++)
    {
        printf("Case %d:\n",kcas);
        scanf("%d",&n);
        init();
        int v = 1,u = 0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&cur);
            while(cur--)
            {
                next[v] = first[v];
                first[u] = v;
                v++;
            }
            u++;
        }
        scanf("%d",&m);
        for(int i = 1;i <= m;i++)
            scanf("%d%d",&u,&v);
    }
}
