#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 505
#define MAXM 5005
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
    return i == fa[i] ? i : fa[i] = findfa(fa[i]);
}
void Union(int a,int b)
{
    int fx = findfa(a),fy = findfa(fy);
    fx = fa[fy];
}
int main()
{
    int n,m,s,t,u,v,w;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        for(int i = 0;i < m;i++)
            scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
        sort(edge,edge + m);
        for(int i = 0;i < m;i++)
        {

        }
    }
}
