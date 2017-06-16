#include<iostream>
#include<cstring>
#include<cstdio>
#include <functional>
#include<algorithm>
using namespace std;
typedef pair<int,int>pii;
#define MAXN 50010
int dp[MAXN];
pii num[MAXN];
int main()
{
    int _,n;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
            scanf("%d%d",&num[i].first,&num[i].second);
        sort(num,num + n);
        memset(dp,0,sizeof(dp));
        int ans = 0;
        for(int i = 0;i < n;i++)
        {
            int ind = lower_bound(dp,dp + n,num[i].second,greater<int>()) - dp;
            dp[ind] = num[i].second;
            ans = max(ans,ind);
        }
        printf("%d\n",ans + 1);
    }
}
