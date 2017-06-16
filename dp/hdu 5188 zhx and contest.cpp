#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 3000005
#define MAXM 35
struct Node
{
    int l,t,v;
    bool operator < (const Node & n)const{
        return l - t < n.l - n.t;
    }
}node[MAXM];
int dp[MAXN],n,w,maxn,num;
int solve()
{
    if(maxn < w)return -1;
    sort(node,node + n);
    memset(dp,0,(num + 2) * sizeof(int));
    int ans = 0x3f3f3f3f;
    for(int i = 0;i < n;i++)
        for(int j = num;j >= max(0,node[i].l - node[i].t) + node[i].t;j--)
        {
            dp[j] = max(dp[j - node[i].t] + node[i].v,dp[j]);
            if(dp[j] >= w)ans = min(ans,j);
        }
    return ans;
}
int main()
{
    while(scanf("%d%d",&n,&w) != EOF)
    {
        maxn = num = 0;
        for(int i = 0;i < n;i++)
        {
            scanf("%d%d%d",&node[i].t,&node[i].v,&node[i].l);
            maxn += node[i].v;
            num += max(node[i].t,node[i].l);
        }
        int ans = solve();
        if(ans < 0)puts("zhx is naive!");
        else printf("%d\n",ans);
    }
}

