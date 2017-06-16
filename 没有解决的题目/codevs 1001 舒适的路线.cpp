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
    int u,v;
    long long w;
    bool operator < (const Edge & e)const{
        return w < e.w;
    }
}edge[MAXM];
int gcd(int a,int b)
{
    if(b)return gcd(b,a % b);
    else return a;
}
int findfa(int i)
{
    return fa[i] == i ? i : fa[i] = findfa(fa[i]);
}
int main()
{
    int n,m,s,t;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        for(int i = 0;i < m;i++)
            scanf("%d%d%lld",&edge[i].u,&edge[i].v,&edge[i].w);
        scanf("%d%d",&s,&t);
        sort(edge,edge + m);
        double ans = 0x7fffffff;
        int u,v;
        for(int i = 0;i < m;i++)
        {
            for(int k = 1;k <= n;k++)fa[k] = k;
            for(int j = i;j < m;j++)
            {
                //cout << edge[i].w << " i j " <<  edge[j].w << endl;
                //cout << edge[i].u << " i j " <<  edge[j].v << endl;
                fa[findfa(edge[j].u)] = findfa(edge[j].v);
                if(findfa(s) == findfa(t))
                {
                    if(ans > (double)edge[j].w / edge[i].w);
                    {
                        //cout << ans << " ans \n";
                        ans = (double)edge[j].w / edge[i].w;
                        u = i,v = j;
                    }
                    break;
                }
            }
        }
        if(ans == 0x7fffffff)puts("IMPOSSIBLE");
        else if(edge[v].w % edge[u].w == 0)printf("%lld\n",edge[v].w / edge[u].w);
        else printf("%lld/%lld\n",edge[v].w / gcd(edge[v].w,edge[u].w),edge[u].w / gcd(edge[v].w,edge[u].w));
    }
}
