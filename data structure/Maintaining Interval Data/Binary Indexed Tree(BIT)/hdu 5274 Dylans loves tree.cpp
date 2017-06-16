#pragma comment(linker, "/STACK:102400000,102400000")
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define MAXN 100005
#define MAXM 300005
#define LOG 19
#define lowbit(i) (i & -i)
vector<int>vec[MAXN];
int _,n,q,cnt;
int val[MAXN],uid[MAXN],vid[MAXN],dp[LOG][MAXM],pre[MAXM];
void modify(int i,int v)
{
    for(;i < MAXM;i += lowbit(i))
        pre[i] ^= v;
}
int sum(int i)
{
    int ans = 0;
    for(;i;i -= lowbit(i))
        ans ^= pre[i];
    return ans;
}
void dfs(int u,int fa)
{
    for(int i = 0;i < vec[u].size();i++)
    {
        int v = vec[u][i];
        if(v == fa)continue;
        uid[v] = ++cnt;
        modify(cnt,val[v]);
        dp[0][cnt] = v;
        dfs(v,u);
        vid[v] = ++cnt;
        modify(cnt,val[v]);
        dp[0][cnt] = u;
    }
}
void init_rmq()
{
    for(int i = 1;(1 << i) <= cnt;i++)
        for(int j = 1;j + (1 << i) - 1 <= cnt;j++)
            dp[i][j] = min(dp[i - 1][j],dp[i - 1][j + (1 << i - 1)]);
}
int lca(int l,int r)
{
    if(l > r)swap(l,r);
    int i = 0;
    for(;l + (1 << i) - 1 <= r;i++);
    i--;
    return min(dp[i][l],dp[i][r - (1 << i) + 1]);
}
int main()
{
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&q);
        for(int i = 0;i <= n;i++)vec[i].clear();
        vec[0].push_back(1) , vec[1].push_back(0);
        memset(pre,0,sizeof(pre));
        for(int i = 1;i < n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            vec[u].push_back(v),vec[v].push_back(u);
        }
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&val[i]);
            val[i]++;
        }
        cnt = 0;
        dfs(0,-1);
        init_rmq();
        for(int i = 0;i < q;i++)
        {
            int c,u,v;
            scanf("%d%d%d",&c,&u,&v);
            if(c == 0)
            {
                v++;
                modify(uid[u],val[u] ^ v);
                modify(vid[u],val[u] ^ v);
                val[u] = v;
            }
            else
            {
                int fa = lca(uid[u],uid[v]);
                int ans = sum(uid[u]) ^ sum(uid[v]) ^ val[fa];
                if(!ans)puts("-1");
                else printf("%d\n",ans - 1);
            }
        }
    }
}
