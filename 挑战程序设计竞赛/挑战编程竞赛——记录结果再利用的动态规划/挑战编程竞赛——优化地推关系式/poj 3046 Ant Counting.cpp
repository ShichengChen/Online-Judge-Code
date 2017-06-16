#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 100010
#define MAXM 1010
#define MOD 1000000
int dp[MAXN],num[MAXM],s[MAXN];
int main()
{
    int n,m,b,e,cur;
    while(scanf("%d%d%d%d",&n,&m,&b,&e) != EOF)
    {
        memset(num,0,sizeof(num));
        for(int i = 1;i <= m;i++)
        {
            scanf("%d",&cur);
            num[cur]++;
        }
        dp[0] = 1;
        for(int i = 0;i <= m;i++)s[i] = 1;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
                if(j <= num[i])dp[j] = s[j];
                else dp[j] = (s[j] - s[j - num[i] - 1] + MOD) % MOD;
            for(int j = 1;j <= m;j++)
                s[j] = (s[j - 1] + dp[j]) % MOD;
        }
        int ans = 0;
        for(int i = b;i <= e;i++)
            ans = (ans + dp[i]) % MOD;
        printf("%d\n",ans);
    }
}
