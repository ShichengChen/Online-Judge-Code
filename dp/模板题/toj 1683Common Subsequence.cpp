#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define MAX 1010
char sequence[MAX],subsequence[MAX];
int dp[MAX][MAX];
int max(int a,int b)
{
    return a < b ? b : a;
}
int main()
{
    while(scanf("%s%s",&sequence,&subsequence) != EOF)
    //while(scanf("%s%s",&sequence,&subsequence))这样写导致文件读入超时
    {
        memset(dp,0,sizeof(dp));
        int len = strlen(sequence);
        int sublen = strlen(subsequence);
        for(int i = 1;i <= len;i++)
            for(int j = 1;j <= sublen;j++)
            {
                dp[i][j] = max(dp[i][j - 1],dp[i - 1][j]);
                if(sequence[i - 1] == subsequence[j - 1])
                    dp[i][j] = max(dp[i - 1][j - 1] + 1,dp[i][j]);
            }
        printf("%d\n",dp[len][sublen]);
    }
    return 0;
}

