#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define MAXN 50010
#define LOG 16
#define lowbit(i) (i & -i)
int prefix[MAXN],ans[MAXN];
void modify(int l,int r,int key)
{
    for(;l <= r;l += lowbit(l))
        prefix[l] += key;
}
int find_kth(int num,int n)
{
    int ans = 0;
    for(int i = LOG;i >= 0;i--)
    {
        int cur = 1 << i;
        if(ans + cur > n || num <= prefix[ans + cur])
            continue;
        ans += cur;
        num -= prefix[ans];
    }
    return ans + 1;
}
int main()
{
    int n,m,cur;
    while(scanf("%d",&n) != EOF)
    {
        memset(prefix,0,sizeof(prefix));
        for(int i = 1;i <= n;i++)
            modify(i,n,1);
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&cur);
            ans[i] = find_kth(cur,n);
            modify(ans[i],n,-1);
        }
        scanf("%d",&m);
        for(int i = 1;i <= m;i++)
        {
            scanf("%d",&cur);
            if(i != m)printf("%d ",ans[cur]);
            else printf("%d\n",ans[cur]);
        }
    }
}
