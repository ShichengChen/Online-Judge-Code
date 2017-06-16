#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXP 501
#define MAXE 25001
int fa[MAXP],cnt;
struct EDGE
{
    int u,v,w;
    bool operator < (const EDGE & edg)const{
        return w < edg.w;
    }
}edge[MAXE];
int findfa(int i)
{
    return fa[i] == -1 ? i : fa[i] = findfa(fa[i]);
    ///why fa[i] = -1 is wrong
    ///because there is repeat edge
    ///so add findfa(x) != findfa(y) is ok
}
inline void Union(int x,int y)
{
    int fx = findfa(x),fy = findfa(y);
    fa[fx] = fy;
}
inline int Kruskal(int n,int m)
{
    int ans = 0;
    for(int i = 0;i < m;i++)
    {
        int u = edge[i].u,v = edge[i].v;
        if(findfa(u) != findfa(v))
        {
            Union(u,v);
            ans += edge[i].w;
            cnt --;
            if(cnt == 0)return ans;
        }
    }
    return -1;
}
inline int scanf_int()
{
    int t = 0;
    char c = getchar();
    while(c > '9' || c < '0')c = getchar();
    while(c <= '9' && c >= '0')
    {
        t = t * 10 + c - '0';
        c = getchar();
    }
    return t;
}
int main()
{
    int _,n,m,k,u,v,w,t,success;
    _ = scanf_int();
    while(_--)
    {
        memset(fa,-1,sizeof(fa));
        success = 0;
        n = scanf_int(); m = scanf_int(); k = scanf_int();
        cnt = n - 1;
        for(int i = 0;i < m;i++)
        {
            edge[i].u = scanf_int();
            edge[i].v = scanf_int();
            edge[i].w = scanf_int();
        }
        sort(edge,edge + m);
        for(int i = 0;i < k;i++)
        {
            t = scanf_int();    u = scanf_int();
            while(--t)
            {
                v = scanf_int();
                if(findfa(u) != findfa(v))
                {
                    cnt--;
                    Union(u,v);
                    if(cnt == 0)success = 1;
                }
            }
        }
        if(success == 1)
        {
            puts("0");
            continue;
        }
        int ans = Kruskal(n,m);
        printf("%d\n",ans);
    }
}
