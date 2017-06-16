#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
struct pii
{
    int x,y;
    bool operator < (const pii & p)const{
        return x == p.x ? y > p.y : x < p.x;
    }
};
#define MAXN 20005
pii num[MAXN];
int dp[MAXN];
int main()
{
    int n,_;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
            scanf("%d%d",&num[i].x,&num[i].y);
        sort(num,num + n);
        memset(dp,0,sizeof(dp));
        int ans = 0;
        for(int i = 0;i < n;i++)
        {
            int ind = upper_bound(dp,dp + n,num[i].y,greater<int>()) - dp;
            dp[ind] = num[i].y;
            ans = max(ans,ind);
        }
        printf("%d\n",ans + 1);
    }
}
