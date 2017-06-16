#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
#define MOD 1000003
#define MAXN 1005
LL C[MAXN][MAXN];
int odd[35];
int main()
{
    C[0][0] = 1;//c[0][0] = 0;is wrong
    for(int n = 1;n < MAXN;n++)
    {
        C[n][0] = C[n][n] = 1;
        for(int m = 1;m <= n / 2;m++)
            C[n][m] = C[n][n - m] = (C[n - 1][m - 1] + C[n - 1][m]) % MOD;
    }
    int n,cnt,maxn,cur;
    while(scanf("%d",&n) != EOF)
    {
        memset(odd,0,sizeof(odd));
        maxn = 0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&cur);
            cnt = 0;
            while(cur)
            {
                odd[cnt++] += (cur & 1);
                cur /= 2;
            }
            maxn = max(maxn,cnt);
        }
        LL ans,bit,s;
        for(int i = 1;i <= n;i++)
        {
            ans = 0,bit = 1;
            for(int j = 0;j < maxn;j++)
            {
                s = 0;
                for(int k = 1;k <= odd[j];k += 2)
                {
                    if(n - odd[j] < i - k || i - k < 0)continue;
                    s = (s + C[odd[j]][k] * C[n - odd[j]][i - k]) % MOD;
                }
                ans += s * (1 << j);
                ans %= MOD;
            }
            if(i == n)printf("%I64d\n",ans);
            else printf("%I64d ",ans);
        }
    }
}
