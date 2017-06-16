#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
#define MAXN 100005
int num[MAXN],first[MAXN],deepest,n,e,root,_;
LL d[MAXN];
struct Edge
{
    int v,next;
}edge[MAXN << 1];
void insert(int u,int v)
{
    edge[e].next = first[u];
    edge[e].v = v;
    first[u] = e++;
}
void dfs(int u,int fa,int deep)
{
    if(num[u])deepest = max(deepest,deep);
    d[deep] += num[u];
    for(int i = first[u];i != -1;i = edge[i].next)
    {
        int v = edge[i].v;
        if(v == fa)continue;
        dfs(v,u,deep + 1);
    }
}
int main()
{
    for(int kcas = scanf("%d",&_);kcas <= _;kcas++)
    {
        e = 0;
        memset(first,-1,sizeof(first));
        memset(d,0x3f,sizeof(d));
        scanf("%d%d",&n,&root);
        for(int i = 1;i < n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            insert(u,v);
            insert(v,u);
        }
        for(int i = 1;i <= n;i++)
            scanf("%d",&num[i]);
        LL ans = 0;
        for(int i = first[root];i != -1;i = edge[i].next)
        {
            int v = edge[i].v;
            deepest = 0;
            memset(d,0,sizeof(d));
            dfs(v,root,0);
            LL t1 = 0,t2 = 0;
            for(int i = 0;i <= deepest;i++)
            {
                t1 += d[i];
                if(d[i] == 0 && t1 + t2 <= i)
                    t2++;
            }
            ans = max(t1 + t2,ans);
        }
        printf("Case #%d: %lld\n",kcas,ans);
    }
}
