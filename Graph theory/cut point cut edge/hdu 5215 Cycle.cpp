#pragma comment(linker, "/STACK:102400000,102400000")
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100005
#define MAXM 300005
int n,m,_,e,top,cnt,bcc,odd,even,point;
int first[MAXN],dfn[MAXN],stack[MAXN],color[MAXN];
bool vis[MAXM << 1];
struct Edge
{
    int next,v;
}edge[MAXM << 1];
void insert(int u,int v)
{
    edge[e].v = v;
    edge[e].next = first[u];
    first[u] = e++;
}
int dfs(int u)
{
    int lowu = dfn[u] = ++cnt;
    stack[++top] = u;
    for(int i = first[u];i != -1;i = edge[i].next)if(!vis[i] && !vis[i ^ 1])
    {
        int v = edge[i].v;
        vis[i] = vis[i ^ 1] = true;
        if(color[v] + color[u] == 3)even++;
        if(color[u] == color[v])odd++;
        if(!dfn[v])
        {
            color[v] = 3 - color[u];
            int lowv = dfs(v);
            lowu = min(lowu,lowv);
            if(dfn[u] < lowv)
            {
                bcc++;
                int num = 0;
                do
                {
                    num++;
                }while(stack[top--] != v);
                if(num == 1)point++;
            }
        }
        else lowu = min(lowu,dfn[v]);
    }
    return lowu;
}
void solve()
{
    even = odd = point = 0;
    memset(dfn,0,sizeof(dfn));
    memset(color,0,sizeof(color));
    memset(vis,false,sizeof(vis));
    bcc = 0;
    cnt = top = 0;
    for(int i = 1;i <= n;i++)if(!dfn[i])
    {
        bcc++;
        color[i] = 1;
        dfs(i);
    }
    if(top == 1)point++;
    if(point + odd > bcc)even++;
}
int main()
{
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        memset(first,-1,sizeof(first));
        e = 0;
        for(int i = 0;i < m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            insert(u,v),insert(v,u);
        }
        solve();
        if(odd)puts("YES");
        else puts("NO");
        if(even)puts("YES");
        else puts("NO");
    }
}
