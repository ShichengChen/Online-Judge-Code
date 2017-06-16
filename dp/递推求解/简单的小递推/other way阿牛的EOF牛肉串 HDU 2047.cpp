#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define N 42
int main()
{
    long long dp[N] = {0,3,8};
    for(int i = 3;i < N;i++)dp[i] = (dp[i - 1] + dp[i - 2]) << 1;
    int n;
    while(scanf("%d",&n) != EOF)
        printf("%I64d\n",dp[n]);
}
