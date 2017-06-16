#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
#define MAXN 1005
vector<int>vec[MAXN],deep[MAXN];
int _,n,k,s,ans,father[MAXN];
bool covered[MAXN];
void dfs(int u,int fa,int d)
{
    if(vec[u].size() == 1)
    {
        covered[u] = true;
        return;
    }
    if(d == 0)return;
    for(int i = 0;i < vec[u].size();i++)if(vec[u][i] != fa)
        dfs(vec[u][i],u,d - 1);
}
void pre_dfs(int u,int fa,int d)
{
    if(vec[u].size() == 1 && u != s)
    {
        deep[d].push_back(u);
        //cout << d << " deep u " << u << endl;
        return;
    }
    for(int i = 0;i < vec[u].size();i++)
    {
        int v = vec[u][i];
        if(v == fa)continue;
        father[v] = u;
        pre_dfs(v,u,d + 1);
    }
}
void solve()
{
    pre_dfs(s,-1,1);
    dfs(s,-1,k);
    for(int d = n;d >= 1;d--)
        for(int i = 0;i < deep[d].size();i++)
        {
            int u = deep[d][i];
            if(covered[u])continue;
            int fa = u;
            for(int i = 0;i < k;i++)
                fa = father[fa];
            dfs(fa,-1,k);
            ans++;
        }
}
int main()
{
    cin >> _;
    while(_--)
    {
        cin >> n >> s >> k;
        for(int i = 1;i <= n;i++)
            vec[i].clear(),deep[i].clear();
        memset(covered,0,sizeof(covered));
        ans = 0;
        for(int i = 1;i < n;i++)
        {
            int u,v;
            cin >> u >> v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        solve();
        cout << ans << endl;
    }
}
