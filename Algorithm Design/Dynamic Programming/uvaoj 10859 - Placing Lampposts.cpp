#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define MAXN 1010
#define K 2000
#define INF 0x3f3f3f3f
#define F(i,n) for(int i = 0;i < (n);i++)
int d[MAXN][2],vis[MAXN];
vector<int>vec[MAXN];
int n,_,m,u,v;
void dfs(int u)
{
    vis[u] = 1;
    int ans0 = 0,ans1 = 0,cnt1 = 0;
    F(i,vec[u].size())
    {
        int v = vec[u][i];
        if(vis[v])continue;
        dfs(v);
        ans0 += d[v][1];
        if(d[v][0] > d[v][1])ans1 += d[v][0];
        else
        {
            ans1 += d[v][1];
            cnt1 ++;
        }
    }
    d[u][0] = ans0 + K;
    d[u][1] = ans1 + cnt1;
}
int main()
{
    cin >> _;
    while(_--)
    {
        cin >> n >> m;
        for(int i = 0;i < n;i++)vec[i].clear();
        memset(vis,0,sizeof(vis));
        for(int i = 0;i < m;i++)
        {
            cin >> u >> v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        int ans = 0;
        F(i,n)if(!vis[i])
        {
            dfs(i);
            ans += max(d[i][0],d[i][1]);
        }
        int ans1 = n - ans / K;
        int ans2 = ans % K;
        cout << ans1 << " " << ans2 << " " << m - ans2 << endl;
    }
}
