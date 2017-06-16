#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAXP 1600
#define INF 210000000
struct Node
{
    int number_of_childern;
    int children[10];
}child [MAXP];
int fa[MAXP];
int d[MAXP][2];
int vis[MAXP][2];
int min(int a,int b)
{
    if(a < b)return a;
    else return b;
}
int find_father(int m)
{
    while(fa[m] != -1)
    {
        m = fa[m];
    }
    return m;
}
int dp(int fa,int on_or_off)
{
    int &ans = d[fa][on_or_off];
    if(vis[fa][on_or_off] == 1)return ans;
    else vis[fa][on_or_off] = 1;
    if(child[fa].number_of_childern == 0)
    {
        ans = on_or_off;
        return ans;
    }
    else if(on_or_off)
    {
        for(int i = 0;i < child[fa].number_of_childern;i++)
        {
            ans += min(dp(child[fa].children[i],0),dp(child[fa].children[i],1));
        }
        ans ++;
        return ans;
    }
    else if(!on_or_off)
    {
        for(int i = 0;i < child[fa].number_of_childern;i++)
        {
            ans += dp(child[fa].children[i],1);
        }
        return ans;
    }

}
int main()
{
    int T;
    while(cin>>T)
    {
        memset(fa,-1,sizeof(fa));
        memset(child,0,sizeof(child));
        memset(d,0,sizeof(d));
        memset(vis,0,sizeof(vis));
        int m,n;
        for(int i = 0;i < T;i++)
        {
            scanf("%d:(%d)",&m,&n);
            child[m].number_of_childern = n;
            for(int i = 0;i < n;i ++)
            {
                int current;
                scanf("%d",&current);
                fa[current] = m;
                child[m].children[i] = current;
            }
        }
        int begin = find_father(m);
        int ans = min(dp(begin,0),dp(begin,1));
        cout << ans << endl;
    }
    return 0;
}
