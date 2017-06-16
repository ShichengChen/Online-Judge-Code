#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define MAXP 10010
#define MAXE 20020
int dfn[MAXP],stack[MAXP],people[MAXP],head[MAXP];
int top,cnt,total,bcc,minn,number;
struct Edge
{
    int v,next;
}edge[MAXE << 1];
void insert(int x,int y)
{
    edge[number].next = head[x];
    edge[number].v = y;
    head[x] = number++;
}
int dfs(int u,int fa)
{
    int lowu = dfn[u] = ++cnt;
    stack[++top] = u;
    for(int i = head[u];i != -1;i = edge[i].next)
    {
        if(i == (fa ^ 1))continue;
        int v = edge[i].v;
        if(!dfn[v])
        {
            int lowv = dfs(v,i);
            lowu = min(lowv,lowu);
            if(dfn[u] < lowv)
            {
                int temp = 0;
                do
                {
                    temp += people[stack[top--]];
                }while(stack[top + 1] != v);
                bcc++;
                people[u] += temp;
                if(abs(total - 2 * temp) < minn)
                    minn = abs(total - 2 * temp);
            }
        }
        else lowu = min(lowu,dfn[v]);
    }
    return lowu;
}
void Tarjan(int n)
{
    memset(dfn,0,sizeof(dfn));
    top = cnt = bcc = 0;
    minn = 0x3f3f3f3f;
    dfs(0,-1);
    if(bcc == 0)puts("impossible") ;
    else printf("%d\n",minn);
}
int main()
{
    int n,m,u,v;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        total = number = 0;
        memset(head,-1,sizeof(head));
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&people[i]);
            total += people[i];
        }
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d",&u,&v);
            insert(u,v) , insert(v,u);
        }
        Tarjan(n);
    }
}
