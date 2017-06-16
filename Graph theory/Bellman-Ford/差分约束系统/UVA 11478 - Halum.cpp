#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int>pii;
#define MAXN 510
vector<pii>vec[MAXN];
int d[MAXN],cnt[MAXN];
bool inque[MAXN];
void updata(int n,int w)
{
    for(int u = 1;u <= n;u++)
        for(int i = 0;i < vec[u].size();i++)
            vec[u][i].second += w;
}
bool bellman(int n)
{
    queue<int>que;
    for(int i = 1;i <= n;i++)
        d[i] = 0,inque[i] = 1,que.push(i),cnt[i] = 1;
    while(!que.empty())
    {
        int u = que.front();que.pop();
        inque[u] = 0;
        for(int i = 0;i < vec[u].size();i++)
        {
            int v = vec[u][i].first,w = vec[u][i].second;
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                if(!inque[v])
                {
                    inque[v] = 1;
                    que.push(v);
                    if(++cnt[v] > n)return false;
                }
            }
        }
    }
    return true;
}
int binary(int l,int r,int n)
{
    updata(n,-l);
    if(!bellman(n))return -2;
    else updata(n,l);
    updata(n,-r - 1);
    if(bellman(n))return -1;
    else updata(n,r + 1);
    while(l < r)
    {
        int mid = l + (r - l + 1) / 2;
        updata(n,-mid);
        if(bellman(n))l = mid;
        else r = mid - 1;
        updata(n,mid);
    }
    return l;
}
int main()
{
    int n,m,u,v,w;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        for(int i = 1;i <= n;i++)vec[i].clear();
        int maxn = 0;
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            maxn = max(maxn,w);
            vec[u].push_back(pii(v,w));
        }
        int ans = binary(1,maxn,n);
        if(ans == -1)puts("Infinite");
        else if(ans == -2)puts("No Solution");
        else printf("%d\n",ans);
    }
}
