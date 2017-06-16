#include<iostream>
#include<cstdio>
#include<set>
#include<iterator>
using namespace std;
#define MAXN 20015
#define MAXM 300015
int cost[MAXN],fa[MAXN];
multiset<int>se[MAXN];
multiset<int>map[MAXN];
multiset<int> :: iterator it;
struct Q
{
    char c[3];
    int x, y;
}q[MAXM];
int find_fa(int x)
{
    return fa[x] == x ? fa[x] : fa[x] = find_fa(fa[x]);
}
void Union(int x,int y)
{
    int fx = find_fa(x),fy = find_fa(y);
    if(fx == fy)return;
    if(se[fx].size() > se[fy].size())swap(fx,fy);
    fa[fx] = fy;
    ///se[fx].insert(se[fy].begin(),se[fy].end());////wrong!!!!
    for (multiset<int> :: iterator it = se[fx].begin();it != se[fx].end();it++)
       se[fy].insert(*it);

}
int main()
{
    int n,m,query,u,v,_ = 1;
    while(scanf("%d%d%d",&n,&m,&query) != EOF)
    {
        for(int i = 1;i <= n;i++)
        {
            map[i].clear();
            se[i].clear();
            fa[i] = i;
            scanf("%d",&cost[i]);
        }
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d",&u,&v);
            map[min(u,v)].insert(max(u,v));
        }
        for(int i = 1;i <= query;i++)
        {
            scanf("%s%d%d",q[i].c,&q[i].x,&q[i].y);
            if(q[i].c[0] == 'U')
                swap(cost[q[i].x],q[i].y);
            else if(q[i].c[0] == 'E')
            {
                if(q[i].x > q[i].y)swap(q[i].x,q[i].y);
                map[q[i].x].erase(map[q[i].x].find(q[i].y));
            }
        }
        for(int i = 1;i <= n;i++)
            se[i].insert(cost[i]);
        for(int i = 1;i <= n;i++)
            for(it = map[i].begin();it != map[i].end();++it)
                Union(i,*it);
        int avenum = 0;
        double ans = 0;
        for(int i = query;i > 0;i--)
        {
            if(q[i].c[0] == 'U')
            {
                int fx = find_fa(q[i].x);
                it = se[fx].find(cost[q[i].x]);
                ///se[fx].erase(NULL);
                ///wrong
                se[fx].erase(it);
                se[fx].insert(q[i].y);
                cost[q[i].x] = q[i].y;
            }
            else if(q[i].c[0] == 'F')
            {
                avenum++;
                int fx = find_fa(q[i].x);
                it = se[fx].lower_bound(q[i].y);
                if(it != se[fx].end())
                    ans += *it;
            }
            else Union(q[i].x,q[i].y);
        }
        printf("Case %d: %.3lf\n",_++,ans / avenum);
    }
}
