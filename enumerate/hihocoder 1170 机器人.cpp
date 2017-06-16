#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long LL;
#define MAXN 100005
#define INF 0x3f3f3f3f3f3f3f3f
#define MAXM 16
#define MAXP 65536
int n,m,pre[MAXM][MAXM];
LL dp[MAXP];
vector<int>vec[MAXM];
int main()
{
    int _,cur;
    for(int kcas = scanf("%d",&_);kcas <= _;kcas++)
    {
        scanf("%d%d",&n,&m);
        for(int i = 0;i < m;i++)vec[i].clear();
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&cur);
            vec[cur - 1].push_back(i);
        }
        memset(pre,0,sizeof(pre));
        for(int i = 0;i < m;i++)
            for(int j = 0;j < m;j++)if(i != j)
                for(int u = 0,v = 0;u < vec[i].size();u++)
                {
                    while(v < vec[j].size() && vec[i][u] > vec[j][v])
                        v++;
                    pre[i][j] += v;
                }
        memset(dp,0x3f,sizeof(dp));
        dp[0] = 0;
        int cnt = 1 << m;
        for(int i = 0;i < cnt;i++)
        {
            for(int j = 0;j < m;j++)if(!(i >> j & 1))
            {
                LL num = 0;
                for(int k = 0;k < m;k++)if(!(i >> k & 1) && k != j)
                    num += pre[j][k];
                dp[i | (1 << j)] = min(dp[i | (1 << j)],dp[i] + num);
            }
        }
        printf("Case #%d: %lld\n",kcas,dp[(1 << m) - 1]);
    }
}
