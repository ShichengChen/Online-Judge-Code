#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
typedef pair<int,int>pii;
#define MAXN 151000
#define LOG 20
int rmq[MAXN][LOG],s[MAXN],place[MAXN],deep[MAXN];
int cnt,vs;
vector<pii>vec[MAXN];
void dfs(int u,int fa,int d,int val)
{
    for(int i = 0;i < vec[u].size();i++)
    {
        int v = vec[u][i].first,w = vec[u][i].second;
        if(v == fa)continue;
        deep[v] = d;
        s[v] = val + w;
        rmq[++vs][0] = v;
        place[v] = vs;
        dfs(v,u,d + 1,val + w);
        rmq[++vs][0] = u;
    }
}
void init_rmq()
{
    for(int j = 1;(1 << j) <= vs + 1;j++)
        for(int i = 0;i <= vs;i++)
        {
            int d1 = deep[rmq[i][j - 1]];
            int d2 = deep[rmq[i + (1 << (j - 1))][j - 1]];
            if(d1 < d2)rmq[i][j] = rmq[i][j - 1];
            else rmq[i][j] = rmq[i + (1 << (j - 1))][j - 1];
        }
}
int query(int a,int b)
{
    a = place[a],b = place[b];
    if(a > b)swap(a,b);
    int len = -1;
    while(b - a + 1 >= (1 << (len + 1)))
        len++;
    int d1 = deep[rmq[a][len]];
    int d2 = deep[rmq[b - (1 << len) + 1][len]];
    if(d1 < d2)return rmq[a][len];
    else return rmq[b - (1 << len) + 1][len];
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
        dfs(0,-1,1,0);
        init_rmq();
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d%d",&u,&v,&w);
            int ans1 = s[u] + s[v] - (s[query(u,v)] << 1);
            int ans2 = s[u] + s[w] - (s[query(u,w)] << 1);
            int ans3 = s[v] + s[w] - (s[query(v,w)] << 1);
            printf("%d\n",(ans1 + ans2 + ans3) / 2);
        }
    }
}
