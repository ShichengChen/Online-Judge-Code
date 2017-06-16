#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 100005
#define lowbit(i) (i & -i)
int id[MAXN],prefix[MAXN],limit[MAXN],cnt,first[MAXN],next[MAXN];
void insert(int x,int y)
{
    next[y] = first[x];
    first[x] = y;
}
void modify(int i,int maxn,int key)
{
    for(;i <= maxn;i += lowbit(i))
        prefix[i] += key;
}
int sum(int i)
{
    int ans = 0;
    for(;i;i -= lowbit(i))
        ans += prefix[i];
    return ans;
}
void dfs(int u)
{
    id[u] = cnt--;
    for(int v = first[u];v != -1;v = next[v])
        dfs(v);
    limit[u] = cnt;
}
int main()
{
    int n,m,u,v;
    char op[3];
    while(scanf("%d",&n) != EOF)
    {
        memset(prefix,0,sizeof(prefix));
        memset(first,-1,sizeof(first));
        cnt = n;
        for(int i = 1;i < n;i++)
        {
            scanf("%d%d",&u,&v);
            insert(u,v);
            modify(i,n,1);
        }
        modify(n,n,1);
        dfs(1);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%s%d",&op,&u);
            if(op[0] == 'Q')
            {
                int ans = sum(id[u]) - sum(limit[u]);
                printf("%d\n",ans);
            }
            else
            {
                if(sum(id[u]) - sum(id[u] - 1))
                    modify(id[u],n,-1);
                else
                    modify(id[u],n,1);
            }
        }
    }
}
