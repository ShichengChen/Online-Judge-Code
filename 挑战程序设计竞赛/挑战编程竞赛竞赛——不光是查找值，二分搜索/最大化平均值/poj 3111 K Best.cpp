#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100005
int n,m;
double s;
struct Node
{
    double x,y;
    int index;
    bool operator < (const Node & n)const{
        return x - s * y > n.x - s * n.y;
    }
}node[MAXN];
int ans[MAXN];
bool isfind(double mid)
{
    s = mid;
    sort(node,node + n);
    double x = 0,y = 0;
    for(int i = 0;i < m;i++)
    {
        x += node[i].x;
        y += node[i].y;
    }
    return x / y >= mid;
}
double binary()
{
    double l = 0,r = 1e7;
    for(int i = 0;i < 50;i++)
    {
        double mid = (l + r) / 2;
        if(isfind(mid))l = mid;
        else r = mid;
    }
    return l;
}
int main()
{
    while(scanf("%d%d",&n,&m) != EOF)
    {
        for(int i = 0;i < n;i++)
        {
            scanf("%lf%lf",&node[i].x,&node[i].y);
            node[i].index = i + 1;
        }
        binary();
        for(int i = 0;i < m;i++)
            ans[i] = node[i].index;
        sort(ans,ans + m);
        for(int i = 0;i < m;i++)
            if(i != m - 1)printf("%d ",ans[i]);
            else printf("%d\n",ans[i]);
    }
}
