//#pragma comment(linker, "/STACK:102400000,102400000")
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
#define MAXN 50005
int dfn[MAXN],stack[MAXN];
bool cut[MAXN];
vector<int>vec[MAXN];
vector<int>bccvec[MAXN];
int cnt,top,bcc;
int dfs(int u,int fa)
{
    int lowu = dfn[u] = ++cnt;
    int child = 0;
    stack[++top] = u;
    for(int i = 0;i < vec[u].size();i++)if(vec[u][i] != fa)
    {
        int v = vec[u][i];
        if(!dfn[v])
        {
            child ++;
            int lowv = dfs(v,u);
            lowu = min(lowu,lowv);
            if(dfn[u] <= lowv)
            {
                bcc++;
                cut[u] = true;
                do
                {
                    bccvec[bcc].push_back(stack[top--]);
                }while(stack[top + 1] != v);
                bccvec[bcc].push_back(u);
            }
        }
        else lowu = min(lowu,dfn[v]);
    }
    if(child == 1 && u == 1)cut[1] = 0;
    return lowu;
}
void Tarjan(int n)
{
    memset(dfn,0,sizeof(dfn));
    memset(cut,false,sizeof(cut));
    cnt = top = bcc = 0;
    dfs(1,-1);
    if(bcc == 1)
    {
        long long ans = (long long)n * (n - 1) / 2;
        printf("2 %lld\n",ans);
        return;
    }
    long long ans = 1;
    int well = 0;
    for(int i = 1;i <= bcc;i++)
    {
        int cnt_cut = 0;
        for(int j = 0;j < bccvec[i].size();j++)
            if(cut[bccvec[i][j]])cnt_cut++;
        if(cnt_cut == 1)
        {
            well ++;
            ans *= (long long)(bccvec[i].size() - cnt_cut);
        }
    }
    printf("%d %lld\n",well,ans);
}
int main()
{
    int n,cas = 1,u,v;
    while(scanf("%d", &n) && n)
    {
        for(int i = 1;i <= n + 1;i++)vec[i].clear();
        for(int i = 1;i <= n + 1;i++)bccvec[i].clear();
        int maxn = 1;
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d",&u,&v);
            maxn = max(max(u,v),maxn);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        printf("Case %d: ", cas++);
        Tarjan(maxn);
    }
}
