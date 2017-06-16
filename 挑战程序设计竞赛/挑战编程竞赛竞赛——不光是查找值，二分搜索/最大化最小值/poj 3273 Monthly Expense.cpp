#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 110005
#define INF 0x3f3f3f3f
int num[MAXN],n,m;
bool isfind(int mid)
{
    int cur = 0,tem = 1;
    for(int i = 0;i < n;i++)
    {
        if(num[i] + cur > mid)
        {
            tem++;
            cur = num[i];
        }
        else cur += num[i];
    }
    return tem <= m;
}
int binary(int l,int r)
{
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
    while(scanf("%d%d",&n,&m) != EOF)
    {
       int l = 0,r = 0;
       for(int i = 0;i < n;i++)
       {
           scanf("%d",&num[i]);
           r += num[i];
           l = max(l,num[i]);
       }
       int ans = binary(l,r);
       printf("%d\n",ans);
    }
}

