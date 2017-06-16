#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
typedef pair<int,int>pii;
#define x first
#define y second
#define MAXN 900
pii num[MAXN];
int dp[MAXN];
int main()
{
    int n;
    while(scanf("%d%d",&num[0].x,&num[0].y),num[0].x + 1 | num[0].y + 1)
    {
        n = 1;
        while(scanf("%d%d",&num[n].x,&num[n].y),num[n].x | num[n].y)
            n++;
        sort(num,num + n);
        memset(dp,0,sizeof(dp));
        int ans = 0;
        for(int i = 0;i < n;i++)
        {
            int ind = lower_bound(dp,dp + n,num[i].y,greater<int>()) - dp;
            dp[ind] = num[i].y;
            ans = max(ans,ind);
        }
        printf("%d\n",ans + 1);
    }
}
