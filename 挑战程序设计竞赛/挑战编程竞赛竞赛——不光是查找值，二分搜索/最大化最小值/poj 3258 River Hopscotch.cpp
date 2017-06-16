#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 50005
#define INF 0x3f3f3f3f
int num[MAXN],len,n,m;
bool isfind(int mid)
{
    int cur = 0,tem = 0;
    for(int i = 0;i <= n;i++)
    {
        if(num[i] - cur >= mid)
            cur = num[i];
        else tem++;
    }
    return tem <= m;
}
int binary()
{
    int l = 0,r = len + 1;
    while(l < r)
    {
        int mid = l + r + 1 >> 1;
        if(isfind(mid))l = mid;
        else r = mid - 1;
    }
    return l;
}
int main()
{
    while(scanf("%d%d%d",&len,&n,&m) != EOF)
    {
       num[n] = len;
       for(int i = 0;i < n;i++)
            scanf("%d",&num[i]);
        sort(num,num + n + 1);
       int ans = binary();
       printf("%d\n",ans);
    }
}
