#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 20020
#define MAXM 50050
int fa[MAXN];
struct Edge
{
    int u,v,w;
    bool operator < (const Edge & e)const{
        return w < e.w;
    }
}edge[MAXM];
int findfa(int i)
{
    return fa[i] = fa[i] == i ? i : findfa(fa[i]);
}
int Kruskal(int n,int m,int r)
{
    sort(edge,edge + r);
    for(int i = 0;i <= n + m;i++)fa[i] = i;
    int ans = 0;
    for(int i = 0;i < r;i++)
    {
        int fu = findfa(edge[i].u),fv = findfa(edge[i].v);
        if(fu != fv)
        {
            ans += edge[i].w;
            fa[fu] = fv;
        }
    }
    return ans;
}
int main()
{
    int _,n,m,r;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d%d",&n,&m,&r);
        for(int i = 0;i < r;i++)
        {
            scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
            edge[i].v += n;
            edge[i].w = -edge[i].w;
        }
        int ans = Kruskal(n,m,r);
        printf("%d\n",(n + m) * 10000 + ans);
    }
}
