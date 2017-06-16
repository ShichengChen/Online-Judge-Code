#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
#define MAXN 510
int dfn[MAXN],cnt,n,m,cut;
vector<int>vec[MAXN];
int tarjan(int u,int fa,int node)
{
    int lowu = dfn[u] = ++cnt;
    int child = 0;
    for(int i = 0;i < vec[u].size();i++)
    {
        int v = vec[u][i];
        if(v == fa || v == node)continue;
        if(!dfn[v])
        {
            child++;
            int lowv = tarjan(v,u,node);
            lowu = min(lowu,lowv);
            if(dfn[u] <= lowv)
                cut++;
        }
        else lowu = min(dfn[v],lowu);
    }
    if(child == 1 && fa == -1)cut--;
    return lowu;
}
bool run()
{
    for(int i = 0;i < n;i++)
    {
        cut = cnt = 0;
        memset(dfn,0,sizeof(dfn));
        tarjan((i + 1) % n,-1,i);
        if(cnt != n - 1 || cut)return false;
    }
    return true;
}
int main()
{
    int u,v;
    while(scanf("%d%d",&n,&m),n | m)
    {
        for(int i = 0;i < n;i++)vec[i].clear();
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d",&u,&v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        puts(run() ? "YES" : "NO");
    }
}
