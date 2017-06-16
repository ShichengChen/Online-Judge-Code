#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 2015
#define ALPH 26
int dp[MAXN][MAXN],cost[ALPH];
char al[MAXN];
int main()
{
    int n,m,a,b;
    char ch[2];
    while(scanf("%d%d",&m,&n) != EOF)
    {
        scanf("%s",al);
        for(int i = 1;i <= m;i++)
        {
            scanf("%s%d%d",ch,&a,&b);
            cost[ch[0] - 'a'] = min(a,b);
        }
        memset(dp,0,sizeof(dp));
        for(int i = n - 1;i >= 0;i--)
        {
            for(int j = i + 1;j < n;j++)
            {
                dp[i][j] = min(dp[i][j - 1] + cost[al[j] - 'a'],dp[i + 1][j] + cost[al[i] - 'a']);
                if(al[i] == al[j])
                    dp[i][j] = min(dp[i + 1][j - 1],dp[i][j]);
            }
        }
        printf("%d\n",dp[0][n - 1]);
    }
}
