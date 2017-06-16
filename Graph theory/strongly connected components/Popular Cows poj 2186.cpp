#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
using namespace std;
#define MAXP 11000
#define MAXL 55000
int begin_number,first[MAXP],uu[MAXL],vv[MAXL];
int dfn[MAXP],low[MAXP],vis[MAXP],id[MAXP];
int out[MAXP];
int scc,ind;
stack<int>st;
struct Edge
{
    int v,next;
}edge[MAXL];
void insert(int x,int y)
{
        edge[begin_number].v = y;
        edge[begin_number].next = first[x];
        first[x] = begin_number++;
}
void init()
{
    begin_number = 0;
    memset(first,-1,sizeof(first));
    memset(dfn,0,sizeof(dfn));
    memset(vis,0,sizeof(vis));
    memset(out,0,sizeof(out));
}
void DFS(int n)
{
    dfn[n] = low[n] = ind++;
    st.push(n);vis[n] = 1;
    for(int i = first[n];i != -1;i = edge[i].next)
        if(!dfn[edge[i].v])
        {
            DFS(edge[i].v);
            low[n] = min(low[n],low[edge[i].v]);
        }
        else if(vis[edge[i].v])
            low[n] = min(low[n],dfn[edge[i].v]);
    if(dfn[n] == low[n])
    {
        while(1)
        {
            int u = st.top(); st.pop();
            id[u] = scc;
            vis[u] = 0;
            if(n == u)break;
        }
        scc++;
    }
}
int tarjan(int n,int m)
{
    scc = 1;ind = 1;
    for(int i = 1;i <= n;i++)if(dfn[i] == 0)
        DFS(i);
    for(int i = 1;i <= m;i++)if(id[uu[i]] != id[vv[i]])
        out[id[uu[i]]]++;
    int num_out = 0,num = 0;
    for(int i = 1;i <= n;i++)if(!out[id[i]])
    {
        if(num_out && num_out != id[i])return 0;
        num_out = id[i];
        num++;
    }
    return num;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        init();
        for(int i = 1;i <= m;i++)
        {
            scanf("%d%d",&uu[i],&vv[i]);
            insert(uu[i],vv[i]);
        }
        printf("%d\n",tarjan(n,m));
    }
}
