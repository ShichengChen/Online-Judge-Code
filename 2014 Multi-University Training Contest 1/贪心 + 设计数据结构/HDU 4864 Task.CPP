#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
#include<iterator>
using namespace std;
typedef pair<int,int>pii;
#define MAXN 100005
#define MAXX 1450
#define MAXY 105
#define fi first
#define se second
multiset<int>machine[MAXY];
pii task[MAXN];
int n,m,num;
long long ans;
bool isfind(int x,int y)
{
    for(int i = y;i < MAXY;i++)
    {
        multiset<int> :: iterator it = machine[i].lower_bound(x);
        if(it != machine[i].end())
        {
            machine[i].erase(it);
            return true;
        }
    }
    return false;
}
void solve()
{
    num = ans = 0;
    for(int i = m - 1;i >= 0;i--)
    {
        if(isfind(task[i].fi,task[i].se))
        {
            ans += 500 * task[i].fi + 2 * task[i].se;
            num++;
        }
    }
    return;
}
int main()
{
    while(scanf("%d%d",&n,&m) != EOF)
    {
        for(int i = 0;i < MAXY;i++)machine[i].clear();
        int x,y;
        for(int i = 0;i < n;i++)
        {
            scanf("%d%d",&x,&y);
            machine[y].insert(x);
        }
        for(int i = 0;i < m;i++)
            scanf("%d%d",&task[i].fi,&task[i].se);
        sort(task,task + m);
        solve();
        printf("%d %I64d\n",num,ans);
    }
}
