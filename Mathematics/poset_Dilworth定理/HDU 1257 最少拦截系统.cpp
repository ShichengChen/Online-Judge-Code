#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
#define MAXN 20005
int num[MAXN],dp[MAXN];
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 0;i < n;i++)
            scanf("%d",&num[i]);
        memset(dp,0x3f,sizeof(dp));
        int ans = 0;
        for(int i = 0;i < n;i++)
        {
            int ind = lower_bound(dp,dp + n,num[i]) - dp;
            dp[ind] = num[i];
            ans = max(ans,ind);
        }
        printf("%d\n",ans + 1);
    }
}
