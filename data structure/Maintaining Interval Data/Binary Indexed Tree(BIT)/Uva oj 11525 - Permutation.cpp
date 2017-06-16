#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 50005
#define lowbit(i) (i & -i)
int prefix_sum[MAXN],array[MAXN];
int sum(int i)
{
    int ans = 0;
    while(i)
    {
        ans += prefix_sum[i];
        i -= lowbit(i);
    }
    return ans;
}
int modify(int i,int maxn,int key)
{
    while(i <= maxn)
    {
        prefix_sum[i] += key;
        i += lowbit(i);
    }
}
int binary_search(int value,int l,int r)
{
    while(l < r)
    {
        int mid = l + r >> 1;
        if(sum(mid) < value)l = mid + 1;
        else r = mid;
    }
    return l;
}
int main()
{
    int _,n;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        memset(prefix_sum,0,sizeof(prefix_sum));
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&array[i]);
            modify(i,n,1);
        }
        for(int i = 1;i <= n;i++)
        {
            int ans = binary_search(array[i] + 1,1,n);
            if(i != n)printf("%d ",ans);
            else printf("%d\n",ans);
            modify(ans,n,-1);
        }
    }
}
