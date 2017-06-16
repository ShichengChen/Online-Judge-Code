#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
#define MAXL 6600
#define MAXP 1201
int first[MAXP],tail[MAXP],order[MAXP],vis[MAXP],id[MAXP],head[MAXP],in[MAXP];
int vv[MAXL],uu[MAXL];
queue<int>que;
int begin_number,topo_num,scc,num;
struct Edge
{
    int v,next;
}edge[MAXL],redge[MAXL],topo[MAXL];
void insert(int x,int y)
{
        edge[begin_number].v = y;
        edge[begin_number].next = first[x];
        first[x] = begin_number;
        redge[begin_number].v = x;
        redge[begin_number].next = tail[y];
        tail[y] = begin_number++;
}
void inserter(int x,int y)
{
        topo[topo_num].v = y;
        topo[topo_num].next = head[x];
        head[x] = topo_num++;
}
void init()
{
    begin_number = 0;topo_num = 0;
    memset(first,-1,sizeof(first));
    memset(tail,-1,sizeof(tail));
    memset(head,-1,sizeof(head));
    memset(in,0,sizeof(in));
    while(!que.empty())que.pop();
}
void DFS(int u)
{
    if(vis[u])return;       // if this point is visited we need to avoid affect order
    vis[u] = 1;
    for(int i = first[u];i != -1;i = edge[i].next)
        DFS(edge[i].v);
    order[++num] = u;
}
void T_DFS(int v)
{
    if(vis[v])return;
    id[v] = scc;  vis[v] = 1;
    for(int i = tail[v];i != -1;i = redge[i].next)if(!vis[redge[i].v])
        T_DFS(redge[i].v);
}
void kosaraju(int n)
{
    memset(vis,0,sizeof(vis));   num = 0;
    for(int i = 1;i <= n;i++)
        if(!vis[i])DFS(i);
    memset(vis,0,sizeof(vis));   scc = 0;
    for(int i = num;i >= 1;i--)if(!vis[order[i]])
    {
        scc++;
        T_DFS(order[i]);
    }
}
bool topol(int n,int m)
{
    kosaraju(n);
    for(int i = 1;i <= m;i++)if(id[uu[i]] - id[vv[i]])
    //contract point automatic delete repeat point(these points belong to one scc)
    {
        inserter(id[uu[i]],id[vv[i]]);
        in[id[vv[i]]] ++;
    }
    int begin = 0;
    for(int i = 1;i <= n;i++)if(!in[id[i]])
    {
        if(begin && begin != id[i])return false;
        begin = id[i];
    }// 1-2 2-3 3-1     4-5 5-6 6-4    1-4 2-5 3-6 three identical edge
    que.push(begin);
    while(!que.empty())
    {
        int num_in = 0;
        int u = que.back();   que.pop();
        for(int i = head[u];i != -1;i = topo[i].next)
        {
            in[topo[i].v]--;
            if(in[topo[i].v] == 0)
            {
                num_in ++;
                if(num_in == 2)return false;
                que.push(topo[i].v);
            }
        }
    }
    return true;
}
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        int n,m;scanf("%d%d",&n,&m);
        init();
        for(int i = 1;i <= m;i++){
                scanf("%d%d",&uu[i],&vv[i]);
                insert(uu[i],vv[i]);
        }
        if(topol(n,m))puts("Yes");
        else puts("No");
    }
}
