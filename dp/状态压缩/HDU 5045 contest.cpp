#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 1027
#define MAXM 12
double dp[MAXN][MAXN],p[MAXN][MAXM];
int main()
{
    int _,n,m;
    scanf("%d",&_);
    for(int kcas = 1;kcas <= _;kcas++)
    {
        scanf("%d%d",&n,&m);
        double maxn = 0;
		for(int k = 0;k < n;k++)
			for(int i = 0;i < m;i++)
            scanf("%lf",&p[i][k]);
        for(int i = 0;i <= m;i++)
            for(int j = 0;j <= (1 << n);j++)
            dp[i][j] = -1.0;
        dp[0][0] = 0;
        for(int i = 0;i < m;i++)
        {
            if(i && i % n == 0)dp[i][0] = dp[i][(1 << n) - 1];
            for(int j = 0;j < (1 << n);j++)
            {
                if(dp[i][j] < 0)continue;
                for(int k = 0;k < n;k++)
                {
                    if((1 << k) & j)continue;
                    dp[i + 1][(1 << k) | j] = max(dp[i + 1][(1 << k) | j],dp[i][j] + p[i][k]);
                    maxn = max(maxn,dp[i + 1][(1 << k) | j]);
                }
            }
        }
        printf("Case #%d: %.5lf\n",kcas,maxn);
    }
}
