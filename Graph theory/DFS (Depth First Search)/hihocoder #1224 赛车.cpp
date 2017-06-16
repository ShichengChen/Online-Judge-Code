#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
#define MAXN 100005
#define pb push_back
vector<int>vec[MAXN];
int ans,maxn;
int dfs(int u,int d)
{
    ans = max(d + maxn,ans);
    int deep = d;
    for(int i = 0;i < vec[u].size();i++)
    {
        int v = vec[u][i];
        deep = max(dfs(v,d + 1),deep);
        maxn = max(deep - d,maxn);
    }
    return deep;
}
int main()
{
    int n,u,v;
    while(cin >> n)
    {
        for(int i = 0;i <= n;i++)vec[i].clear();
        for(int i = 0;i < n - 1;i++)
        {
            scanf("%d%d",&u,&v);
            vec[u].pb(v);
        }
        maxn = ans = 0;
        dfs(1,0);
        cout << ans << endl;
    }
}
