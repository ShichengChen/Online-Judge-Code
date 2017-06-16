#include<cstdio>
int main()
{
    int n,mod,cur,dp1,dp2;
    while(scanf("%d%d",&n,&mod) != EOF)
    {
        scanf("%d",&cur);
        dp1 = cur , dp2 = 2 * cur - 1;
        for(int i = 2;i <= n;i++)
        {
            scanf("%d",&cur);
            if(cur == 1)
                dp2 = dp1 = (2 * dp1 + 1) % mod;
            else
            {
                dp2 = (2 * dp1 + 2 * cur + dp2) % mod;
                dp1 = (2 * dp1 + cur) % mod;
            }
        }
        printf("%d\n",dp2);
    }
}
