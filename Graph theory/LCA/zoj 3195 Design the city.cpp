#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
typedef pair<int,int>pii;
#define MAXN 151000
#define LOG 20
int rmq[MAXN][LOG],s[MAXN],place[MAXN],id[MAXN],deep[MAXN];
int cnt,vs;
vector<pii>vec[MAXN];
void dfs(int u,int fa,int val)
{
    for(int i = 0;i < vec[u].size();i++)
    {
        int v = vec[u][i].first,w = vec[u][i].second;
        if(v == fa)continue;
        s[v] = val + w;
        id[++cnt] = v;
        rmq[++vs][0] = cnt;
        place[v] = vs;
        dfs(v,u,val + w);
        rmq[++vs][0] = rmq[place[u]][0];
    }
}
void init_rmq()
{
    for(int j = 1;(1 << j) <= vs + 1;j++)
        for(int i = 0;i <= vs;i++)
            rmq[i][j] = min(rmq[i][j - 1],rmq[i + (1 << (j - 1))][j - 1]);
}
int query(int a,int b)
{
    a = place[a],b = place[b];
    if(a > b)swap(a,b);
    int len = -1;
    while(b - a + 1 >= (1 << (len + 1)))
        len++;
    return id[min(rmq[a][len],rmq[b - (1 << len) + 1][len])];
}
int main()
{
    int n,u,v,w,_ = 0,q;
    while(scanf("%d",&n) != EOF)
    {
        if(_++)puts("");
        for(int i = 0;i < n;i++)vec[i].clear();
        for(int i = 1;i < n;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            vec[u].push_back(pii(v,w));
            vec[v].push_back(pii(u,w));
        }
        cnt = vs = 0;
        dfs(0,-1,0);
        init_rmq();
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d%d",&u,&v,&w);
            int ans1 = s[u] + s[v] - (s[query(u,v)] << 1);
            int ans2 = s[u] + s[w] - (s[query(u,w)] << 1);
            int ans3 = s[v] + s[w] - (s[query(v,w)] << 1);
            printf("%d\n",(ans1 + ans2 + ans3) >> 1);
        }
    }
}
