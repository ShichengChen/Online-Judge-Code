#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAXN 2010
#define INF 0x3f3f3f3f
int num[MAXN],cur[MAXN],dp[MAXN];
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&num[i]);
            cur[i] = num[i];
        }
        memset(dp,0,sizeof(dp));
        sort(cur,cur + n);
        for(int i = 0;i < n;i++)
        {
            int minn = INF;
            for(int j = 0;j < n;j++)
            {
                minn = min(minn,dp[j]);
                dp[j] = minn + abs(cur[j] - num[i]);
            }
        }
        int ans = 0x3f3f3f3f;
        for(int i = 0; i < n; i++) ans = min(ans,dp[i]);
        printf("%d\n",ans);
    }
}
