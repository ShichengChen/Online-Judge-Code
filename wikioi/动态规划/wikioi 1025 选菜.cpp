#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 105
#define MAXM 1005
#define INF 0x3f3f3f3f
int dp[MAXM],nutrition[MAXN],price[MAXN],num1[MAXN],num2[MAXN];
int n,k;
double x;
int main()
{
    int cur,m = 0;;
    while(scanf("%d%d%lf",&n,&k,&x) != EOF)
    {
        memset(price,0x3f,sizeof(price));
        for(int j = 0;j < 3;j++)
            for(int i = 0;i < n;i++)
            {
                if(j == 0)
                {
                    double cur;
                    scanf("%lf",&cur);
                    num1[i] = cur * 10;
                    continue;
                }
                scanf("%d",&cur);
                if(j == 1)
                    num2[i] = cur;
                else
                {
                    nutrition[cur] = num2[i];
                    price[cur] = num1[i];
                }
            }
        int begin = 0,v = 0;
        for(int i = 0;i < k;i++)
        {
            scanf("%d",&cur);
            begin += price[cur];
            v += nutrition[cur];
            price[cur] = INF;
        }
        memset(dp,-0x3f,sizeof(dp));
        int ans = 0;
        dp[begin] = v;
        for(int i = 0;i < MAXN;i++)
            for(int j = 10 * x;j >= price[i];j--)
            {
                dp[j] = max(dp[j - price[i]] + nutrition[i],dp[j]);
                ans = max(ans,dp[j]);
            }
        printf("%d\n",ans);
    }
}
