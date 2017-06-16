#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 20020
#define MAXK 20
int fa[MAXN],rank[MAXN],cur[MAXK],vis[MAXN];
int findfa(int i)
{
    if(fa[i] == i)return i;
    int original_fa = fa[i];
    fa[i] = findfa(fa[i]);
    rank[i] ^= rank[original_fa];
    return fa[i];
}
bool Union(int x,int y,int value)
{
    int fx = findfa(x);
    int fy = findfa(y);
    if(fx == fy)
        return (rank[x] ^ rank[y]) == value;
    if(fx == 0)swap(fx,fy);
    fa[fx] = fy;
    rank[fx] = value ^ rank[y] ^ rank[x];
    return true;
}
int query(int k)
{
    int ans = 0;
    for (int i = 1;i <= k;i++)
    {
        scanf("%d",&cur[i]);
        cur[i] ++;
        int father = findfa(cur[i]);
        ans ^= rank[cur[i]];
        cur[i] = father;
        vis[father] ^= 1;
    }
    for (int i = 1;i <= k;i++)
        if (vis[cur[i]]){
            if (cur[i] != 0)ans = -1;
             vis[cur[i]] = 0;
    }
    return ans;
}
void init()
{
    for(int i = 0;i <= MAXN;i++)
        fa[i] = i;
    memset(rank,0,sizeof(rank));
    memset(vis,0,sizeof(vis));
}
int main()
{
    int cas = 1,n,m,p,q,v,fact;
    char str[22],op[2];
    bool fail;
    while(scanf("%d%d",&n,&m) && (n | m))
    {
        printf("Case %d:\n", cas++);
        fail = fact = 0;
        init();
        while(m--)
        {
            scanf("%s",op);
            if(fail)
            {
                gets(str);
                continue;
            }
            if(op[0] == 'I')
            {
                fact++;
                gets(str);
                if(sscanf(str, "%d%d%d", &p, &q, &v) == 2)v = q , q = -1;
                if(!Union(p + 1, q + 1, v))
                {
                    printf("The first %d facts are conflicting.\n", fact);
                    fail = 1;
                }
            }
            else
            {
                int k,ans;
                scanf("%d",&k);
                ans = query(k);
                if(ans == -1)puts("I don't know.");
                else printf("%d\n",ans);
            }
        }
        puts("");
    }
}
