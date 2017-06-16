#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define MAXN 40005
#define MOD 1000000007
typedef long long ll;
ll d[MAXN],nd[MAXN],ans;
int n,_,m,u,v,fa[MAXN],child[MAXN];
vector<int>vec[MAXN];
ll _pow(ll a,int b)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1)ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}
int dfs(int u)
{
    child[u] = 1;
    for(int i = 0;i < vec[u].size();i++)
    {
        int v = vec[u][i];
        int num = dfs(v);
        ans = (ans * nd[num]) % MOD;
        child[u] += num;
    }
    ans = (ans * d[child[u] - 1]) % MOD;
    return child[u];
}
int main()
{
    d[0] = nd[0] = d[1] = nd[1] = 1;
    for(int i = 2;i < MAXN;i++)
    {
        d[i] = (i * d[i - 1]) % MOD;
        nd[i] = _pow(d[i],MOD - 2);
    }
    cin >> _;
    while(_--)
    {
        cin >> n >> m;
        memset(fa,-1,sizeof(fa));
        for(int i = 1;i <= n;i++)vec[i].clear();
        for(int i = 0;i < m;i++)
        {
            cin >> u >> v;
            vec[v].push_back(u);
            fa[u] = v;
        }
        ans = d[n];
        for(int i = 1;i <= n;i++)if(fa[i] == -1)
            ans = (ans * nd[dfs(i)]) % MOD;
        cout << ans << endl;
    }
}
