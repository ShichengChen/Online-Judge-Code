#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define N 52
int main()
{
    int n;
    long long dp[N] = {1 , 1 , 1 , 2};
    for(int i = 3;i < N;i++)dp[i] = dp[i - 1] + dp[i - 2];
    while(scanf("%d",&n) != EOF)
        printf("%I64d\n",dp[n + 1]);
}
