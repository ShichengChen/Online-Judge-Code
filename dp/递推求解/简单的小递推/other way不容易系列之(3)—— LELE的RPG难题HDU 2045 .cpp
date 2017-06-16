#include<cstdio>
#define N 51
int main()
{
    int n;
    long long dp[N] = {0,3,6,6};
    for(int i = 4;i < N;i++)dp[i] = dp[i - 1] + (dp[i - 2] << 1);
    while(scanf("%d",&n) != EOF)
        printf("%I64d\n",dp[n]);
}
/*
在格数为n的情况下，第n格的取法影响了第1格和第n-1格的取法。
此种情况下1到n-1格的取法不等于f(n-1)。没有明显的子结构。
所以，我们逆向思考，尝试从n-1格的情况推出n格的情况。
*/
