#pragma comment(linker, "/STACK:102400000,102400000")
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 1000005
int first[MAXN],e,_,n,m1,m2;
struct Edge
{
    int v,next;
}edge[MAXN * 3];
bool vis[MAXN * 3],stack[MAXN];
void insert(int u,int v)
{
    edge[e].next = first[u];
    edge[e].v = v;
    first[u] = e++;
}
bool dfs(int u)
{
    stack[u] = true;
    for(int i = first[u];i != -1;i = edge[i].next)if(!vis[i])
    {
        int v = edge[i].v;
        vis[i] = true;
        if(stack[v] && (i >= 2 * m1 || ((i < 2 * m1) && vis[i ^ 1] == 0)))return true;
        if(dfs(v))return true;
    }
    stack[u] = false;
    return false;
}
bool solve()
{
    memset(stack,0,sizeof(stack));
    memset(vis,0,sizeof(vis));
    for(int u = 1;u <= n;u++)
        if(dfs(u))return true;
    return false;
}
int main()
{
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d%d",&n,&m1,&m2);
        int u,v;
        memset(first,-1,sizeof(first));
        e = 0;
        for(int i = 0;i < m1 + m2;i++)
        {
            scanf("%d%d",&u,&v);
            insert(u,v);
            if(i < m1)insert(v,u);
        }
        if(solve())puts("YES");
        else puts("NO");
    }
}
