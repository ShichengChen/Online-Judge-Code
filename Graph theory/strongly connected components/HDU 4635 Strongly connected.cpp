#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
#define MAXN 100010
vector<int>vec[MAXN];
int dfn[MAXN],id[MAXN],stack[MAXN],num[MAXN];
bool in[MAXN],out[MAXN];
int scc,cnt,top;
int tarjan(int u)
{
    int lowu = dfn[u] = ++cnt;
    stack[++top] = u;
    for(int i = 0;i < vec[u].size();i++)
    {
        int v = vec[u][i];
        if(!dfn[v])
        {
            int lowv = tarjan(v);
            lowu = min(lowu,lowv);
        }
        else if(!id[v])
            lowu = min(lowu,dfn[v]);
    }
    if(lowu == dfn[u])
    {
        scc++;
        num[scc] = 0;
        do
        {
            id[stack[top--]] = scc;
            num[scc]++;
        }while(stack[top + 1] != u);
    }
    return lowu;
}
long long solve(int n,int m)
{
    memset(dfn,0,sizeof(dfn));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    memset(id,0,sizeof(id));
    scc = top = cnt = 0;
    for(int i = 1;i <= n;i++)
        if(!dfn[i])tarjan(i);
    if(scc == 1)return -1;
    for(int u = 1;u <= n;u++)
        for(int i = 0;i < vec[u].size();i++)
            if(id[u] != id[vec[u][i]])
                in[id[vec[u][i]]] = out[id[u]] = true;
    long long minn = n;
    for(int i = 1;i <= scc;i++)
        if(!out[i] || !in[i])minn = min(minn,(long long)num[i]);
    return (long long)n * (n - 1) - m - minn * (n - minn);
}
int main()
{
    int _,n,m,u,v;
    scanf("%d",&_);
    for(int kcas = 1;kcas <= _;kcas++)
    {
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++)vec[i].clear();
        for(int i = 1;i <= m;i++)
        {
            scanf("%d%d",&u,&v);
            vec[u].push_back(v);
        }
        long long ans = solve(n,m);
        if(ans == -1)
            printf("Case %d: -1\n",kcas);
        else
            printf("Case %d: %I64d\n",kcas,ans);
    }
}
