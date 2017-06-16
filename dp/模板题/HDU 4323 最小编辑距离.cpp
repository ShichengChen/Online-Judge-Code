#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<cstdlib>
#include<cmath>
using namespace std;
#define LEN 15
#define MAXM 1600
#define MAXQ 1100
#define INF (1 << 29)
#define sss system("pause");
char magic[MAXM][LEN];
char query[MAXQ][LEN];
int limit[MAXQ];
int dp[LEN][LEN];
int main()
{
    int T;scanf("%d",&T);
    for(int t = 1;t <= T;t++)
    {
        printf("Case #%d:\n",t);
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++)scanf("%s",magic[i] + 1);
        for(int i = 1;i <= m;i++)
        {
            scanf("%s",query[i] + 1);
            scanf("%d",&limit[i]);
        }
        for(int i = 1;i <= m;i++)
        {
            int len_q = strlen(query[i] + 1);
            int ans = 0;
            for(int j = 1;j <= n;j++)
            {
                int len_m = strlen(magic[j] + 1);
                if(len_m - len_q > limit[i] || len_m - len_q < -limit[i])
                    continue;
                if(len_m <= limit[i] && len_q <= limit[i])
                {
                    ans++;
                    continue;
                }
                for(int p = 0;p <= len_m;p++)dp[p][0] = p;
                for(int q = 0;q <= len_q;q++)dp[0][q] = q;

                for(int p = 1;p <= len_m;p++)
                {
                    for(int q = 1;q <= len_q;q++)
                    {
                        dp[p][q] = min(dp[p - 1][q] + 1,dp[p][q - 1] + 1);
                        dp[p][q] = min(dp[p][q],dp[p - 1][q - 1] + (query[i][q] == magic[j][p] ? 0 : 1));
                    }
                }
                if(dp[len_m][len_q] <= limit[i])ans++;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
