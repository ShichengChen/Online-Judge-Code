#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
#define MAXN 305
vector<int>vec[MAXN];
int color[MAXN];
bool bipartite(int u)
{
    for(int i = 0;i < vec[u].size();i++)
    {
        int v = vec[u][i];
        if(color[v] == -1)
        {
            color[v] = (!color[u]);
            bipartite(v);
        }
        if(color[v] == color[u])return false;
    }
    return true;
}
int main()
{
    int n,u,v;
    while(scanf("%d",&n),n)
    {
        for(int i = 1;i <= n;i++)vec[i].clear();
        while(scanf("%d%d",&u,&v),u,v)
            vec[u].push_back(v) , vec[v].push_back(u);
        memset(color,-1,sizeof(color));
        color[1] = 1;
        if(bipartite(1))puts("YES");
        else puts("NO");
    }
}
