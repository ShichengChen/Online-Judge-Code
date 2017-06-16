#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 40005
#define INF 0x3f3f3f3f
int dp[MAXN];
int main()
{
    int _,n,cur;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        memset(dp,0x3f,sizeof(dp));
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&cur);
            *lower_bound(dp,dp + n,cur) = cur;
        }
        printf("%d\n",lower_bound(dp,dp + n,INF) - dp);
    }
}
