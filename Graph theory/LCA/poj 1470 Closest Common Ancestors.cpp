#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define MAXN 905
using namespace std;
vector<int>vec[MAXN],quer[MAXN];
int ans[MAXN],fa[MAXN],vis[MAXN];
int findfa(int i)
{
    return fa[i] = fa[i] == i ? i : findfa(fa[i]);
}
void tarjan(int u)
{
    fa[u] = u;
    for(int i = 0;i < vec[u].size();i++)
    {
        int v = vec[u][i];
        tarjan(v);
        fa[v] = u;
    }
    vis[u] = true;
    for(int i = 0;i < quer[u].size();i++)
    {
        int v = quer[u][i];
        if(vis[v] || u == v)ans[findfa(v)]++;
    }

}
int main()
{
    int n,u,v,num,m;
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 1;i <= n;i++)vec[i].clear(),quer[i].clear();
        memset(ans,0,sizeof(ans));
        memset(vis,0,sizeof(vis));
        for(int i = 1;i <= n;i++)
        {
            scanf("%d:(%d)",&u,&num);
            while(num--)
            {
                scanf("%d",&v);
                vec[u].push_back(v);
                ans[v]++;
            }
        }
        scanf("%d",&m);
        for(int i = 1;i <= m;i++)
        {
            scanf("%(%d %d%)",&u,&v);
            quer[u].push_back(v),quer[v].push_back(u);
        }
        int root = 0;
        while(ans[++root]);
        memset(ans,0,sizeof(ans));
        tarjan(root);
        for(int i = 1;i <= n;i++)
            if(ans[i]) printf("%d:%d\n",i,ans[i]);
    }
}
