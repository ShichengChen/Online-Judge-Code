#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 33
#define MAXS 512
#define INF 0x3f3f3f3f
int w[MAXN][MAXN],tic[MAXN];
double dp[MAXS][MAXN];
int main()
{
    int n,m,t,a,b,u,v,val;
    while(scanf("%d%d%d%d%d",&t,&n,&m,&a,&b), t | m | n | a | b)
    {
        memset(w,-1,sizeof(w));
        for(int i = 0;i < t;i++)
            scanf("%d",&tic[i]);
        for(int i = 1;i <= m;i++)
        {
            scanf("%d%d%d",&u,&v,&val);
            w[v][u] = w[u][v] = val;
        }
        for(int i = 0;i < (1 << t);i++)
            fill(dp[i],dp[i] + n + 1,INF);
        dp[0][a] = 0;
        double ans = INF;
        for(int i = 0;i < (1 << t);i++)
        {
            for(int u = 1;u <= n;u++)
                for(int k = 0;k < t;k++)
                    if((i >> k & 1) == 0)
                        for(int  v = 1;v <= n;v++)
                            if(w[u][v] >= 0)
                                dp[i | (1 << k)][v] = min(dp[i | (1 << k)][v],dp[i][u] + (double)w[u][v] / tic[k]);
            ans = min(ans,dp[i][b]);
        }
        if(ans == INF)
            puts("Impossible");
        else
            printf("%.3f\n",ans);
    }
}
