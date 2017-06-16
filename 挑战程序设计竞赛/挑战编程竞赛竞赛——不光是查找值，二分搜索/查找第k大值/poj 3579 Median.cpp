#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100005
int num[MAXN],n;
long long median;
int isfind(int mid)
{
    long long cur = 0;
    for(int i = 0;i < n;i++)
    {
        cur += upper_bound(num + i + 1,num + n,num[i] + mid) - (num + i + 1);
        if(cur >= median)return true;
    }
    return cur >= median;
}
int binary()
{
    int l = 0,r = num[n - 1] - num[0];
    median = ((long long)n * (n - 1) / 2 + 1) / 2;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(isfind(mid))r = mid;
        else l = mid + 1;
    }
    return l;
}
int main()
{
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 0;i < n;i++)
            scanf("%d",&num[i]);
        sort(num,num + n);
        int ans = binary();
        printf("%d\n",ans);
    }
}
