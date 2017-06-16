#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define MAXP 20010
#define MAXE 50010
vector<int>vec[MAXP];
int indu[MAXP],outdu[MAXP],dfn[MAXP],stack[MAXE],id[MAXP];
int cnt,scc,top;
int Tarjan_dfs(int u)
{
    int lowu = dfn[u] = ++cnt;
    stack[++top] = u;
    for(int i = 0;i < vec[u].size();i++)
    {
        int v = vec[u][i];
        if(!dfn[v])
        {
            int lowv = Tarjan_dfs(v);
            lowu = min(lowu,lowv);
        }
        else if(id[v] == 0)
            lowu = min(dfn[v],lowu);
    }
    if(dfn[u] == lowu)
    {
        scc++;
        do
        {
            id[stack[top--]] = scc;
        }while(stack[top + 1] != u);
    }
    return lowu;
}
int solve_Tarjan(int n)
{
    memset(indu,0,sizeof(indu));
    memset(outdu,0,sizeof(outdu));
    memset(dfn,0,sizeof(dfn));
    memset(id,0,sizeof(id));
    cnt = top = scc = 0;
    for(int i = 1;i <= n;i++)if(!dfn[i])
        Tarjan_dfs(i);
    if(scc == 1)return 0;
    for(int i = 1;i <= n;i++)
        for(int j = 0;j < vec[i].size();j++)
        if(id[i] != id[vec[i][j]])
        {
            outdu[id[i]]++;
            indu[id[vec[i][j]]]++;
        }
    int in0 = 0,out0 = 0;
    for(int i = 1;i <= scc;i++)
    {
        if(indu[i] == 0)in0++;
        if(outdu[i] == 0)out0++;
    }
    return max(in0,out0);
}
int main()
{
    int _,u,v,n,m;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++)vec[i].clear();
        while(m--)
        {
            scanf("%d%d",&u,&v);
            vec[u].push_back(v);
        }
        int ans = solve_Tarjan(n);
        printf("%d\n",ans);
    }
}
