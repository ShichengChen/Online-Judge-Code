#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXP 101000
struct EDGE
{
    int u,v,w;
    bool operator < (const EDGE & edg)const{
        return w > edg.w;
    }
}edge[MAXP];
int fa[MAXP];
bool machine[MAXP];
int findfa(int i)
{
    fa[i] == i ? i : fa[i] = findfa(fa[i]);
}
bool Union(int x,int y)
{
    int fx = findfa(x),fy = findfa(y);
    if(machine[fx] && machine[fy])return true;
    else if(machine[fx] && !machine[fy])fa[fy] = fx;
    else fa[fx] = fy;
    return false;
}
long long greedy(int n)
{
    long long ans = 0;
    sort(edge,edge + n - 1);
    for(int i = 0;i < n - 1;i++)
        if(Union(edge[i].v,edge[i].u))ans += edge[i].w;
    return ans;
}
int main()
{
    int _,n,k,u,v,w,num;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&k);
        memset(machine,0,sizeof(machine));
        for(int i = 0;i < n;i++)fa[i] = i;
        for(int i = 0;i < n - 1;i++)scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
        for(int i = 0;i < k;i++)
        {
            scanf("%d",&num);
            machine[num] = 1;
        }
        long long ans = greedy(n);
        printf("%I64d\n",ans);
    }
}
