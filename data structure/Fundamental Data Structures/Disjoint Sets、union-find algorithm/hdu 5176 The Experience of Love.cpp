#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
#define MAXN 150005
struct Edge
{
    int u,v;
    ull w;
    bool operator < (const Edge & n)const{
        return w < n.w;
    }
}e[MAXN];
int n,f[MAXN],cnt[MAXN];
ull ans;
void init()
{
    for(int i = 1;i <= n;i++)
    {
        f[i] = i;
        cnt[i] = 1;
    }
}
int findfa(int i)
{
    return f[i] == i ? i : f[i] = findfa(f[i]);
}
void Union(int u,int v,ull w,bool flag)
{
    int fu = findfa(u),fv = findfa(v);
    if(flag)
        ans += w * cnt[fu] * cnt[fv];
    else
        ans -= w * cnt[fu] * cnt[fv];
    f[fv] = fu;
    cnt[fu] += cnt[fv];
}
int main()
{
    int _ = 1;
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 0;i < n - 1;i++)
            scanf("%d%d%llu",&e[i].u,&e[i].v,&e[i].w);
        sort(e,e + n - 1);
        ans = 0;
        init();
        for(int i = 0;i < n - 1;i++)
            Union(e[i].u,e[i].v,e[i].w,true);
        init();
        for(int i = n - 2;i >= 0;i--)
            Union(e[i].u,e[i].v,e[i].w,false);
         printf("Case #%d: %llu\n",_++,ans);
    }
}
