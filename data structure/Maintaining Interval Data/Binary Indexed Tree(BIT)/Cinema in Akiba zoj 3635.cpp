#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define MAXN 55000
#define lowbit(i) (i & (-i))
int partsum[MAXN],order[MAXN];
int getsum(int i)
{
    int total = 0;
    while(i)
    {
        total += partsum[i];
        i -= lowbit(i);
    }
    return total;
}
void modify(int i,int maxn,int key)
{
    while(i <= maxn)
    {
        partsum[i] += key;
        i += lowbit(i);
    }
}
int binary(int cur,int maxn)
{
    int l = 1,r = maxn;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(getsum(mid) >= cur)r = mid;
        else l = mid + 1;
    }
    return l;
}
int main()
{
    int n,query,cur,x;
    while(scanf("%d",&n) != EOF)
    {
        memset(partsum,0,sizeof(partsum));
        for(int i = 1;i <= n;i++)
            partsum[i] += lowbit(i);
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&cur);
            order[i] = binary(cur,n);
            modify(order[i],n,-1);
        }
        scanf("%d",&query);
        for(int i = 1;i <= query;i++)
        {
            scanf("%d",&x);
            if(i != query)printf("%d ",order[x]);
            else printf("%d\n",order[x]);
        }
    }
}
