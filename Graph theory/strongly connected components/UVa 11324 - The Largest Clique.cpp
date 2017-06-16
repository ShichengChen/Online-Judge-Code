#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define MAXP 1010
int stack[MAXP],dfn[MAXP],id[MAXP],indu[MAXP],d[MAXP],w[MAXP];
int scc,cnt,top,lowu,ans;
vector<int>vec[MAXP],scc_vec[MAXP];
int dp(int u)
{
    if(scc_vec[u].size() == 0)return d[u] = w[u];
    int ret = 0;
    for(int i = 0;i < scc_vec[u].size();i++)
         ret = max(ret,dp(scc_vec[u][i]));
    return d[u] = ret + w[u];
}
int Tarjan_dfs(int u)
{
    int lowu = dfn[u] = ++cnt;
    stack[++top] = u;
    for(int i = 0;i < vec[u].size();i++)
    {
        int v = vec[u][i];
        if(!dfn[v])
            lowu = min(lowu,Tarjan_dfs(v));
        else if(id[v] == 0)
            lowu = min(lowu,dfn[v]);
    }
    if(lowu == dfn[u])
    {
        scc++;
        int num_of_point_in_scc = 0;
        do
        {
            id[stack[top--]] = scc;
            num_of_point_in_scc++;
        }while(stack[top + 1] != u);
        w[scc] = num_of_point_in_scc;
    }
    return lowu;
}
void solve_Tarjan_dp(int n)
{
    memset(dfn,0,sizeof(dfn));
    memset(id,0,sizeof(id));
    memset(indu,0,sizeof(indu));
    cnt = scc = top = ans = 0;
    for(int i = 1;i <= n;i++)if(!dfn[i])
        Tarjan_dfs(i);
    for(int i = 1;i <= n;i++)
        for(int j = 0;j < vec[i].size();j++)
            if(id[i] != id[vec[i][j]])
            {
                scc_vec[id[i]].push_back(id[vec[i][j]]);
                indu[id[vec[i][j]]]++;
            }
    for(int i = 1;i <= scc;i++)if(!indu[i])
        ans = max(dp(i),ans);
}
int main() {
    int _,n,m,u,v;
    scanf("%d", &_);
    while(_--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
        {
            vec[i].clear();
            scc_vec[i].clear();
        }
        while(m--)
        {
            scanf("%d%d", &u, &v);
            vec[u].push_back(v);
        }
        solve_Tarjan_dp(n);
        printf("%d\n",ans);
    }
}
