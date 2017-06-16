#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#define MAXN 30010
vector<int>vec[MAXN];
int in[MAXN],ans[MAXN];
void topol(int n)
{
    priority_queue<int>que;
    for(int i = 1;i <= n;i++)
        if(!in[i])que.push(i);
    while(!que.empty())
    {
        int u = que.top();
        que.pop();
        for(int i = 0;i < vec[u].size();i++)
        {
            int v = vec[u][i];
            in[v]--;
            if(!in[v])que.push(v);
        }
        ans[n--] = u;
    }
}
int main()
{
    int _,n,m,u,v;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++)vec[i].clear();
        memset(in,0,sizeof(in));
        for(int i = 1;i <= m;i++)
        {
            scanf("%d%d",&u,&v);
            vec[v].push_back(u);
            in[u]++;
        }
        topol(n);
        for(int i = 1;i <= n;i++)
        {
            if(i != n)printf("%d ",ans[i]);
            else printf("%d\n",ans[i]);
        }
    }
}
