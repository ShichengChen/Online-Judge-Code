#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 210
int dp[MAXN][MAXN];
int n,k;
int dfs(int maxn,int num,int deep)
{
    if(deep == 3)
        return dp[num][min(num,maxn)];
    int ans = 0;
    for(int i = maxn;i >= (num + deep - 1) / deep;i--)
        if(num - i >= deep - 1)
            ans += dfs(i,num - i,deep - 1);
    return ans;
}
int main()
{
    scanf("%d%d",&n,&k);
    if(k == 2)printf("%d\n",n >> 1);
    else
    {
        for(int q = 3;q <= n;q++)
            for(int i = 1;i <= n;i++)
                for(int j = i;q - i - j >= j;j++)
                    dp[q][q - i - j]++;
        for(int q = 3;q <= n;q++)
            for(int i = 1;i <= n;i++)
                dp[q][i] += dp[q][i - 1];
        int ans = dfs(n,n,k);
        printf("%d\n",ans);
    }
}
