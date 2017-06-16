#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define N 21
int main()
{
    int _,n = 6;
    long long dp[N] = {0,0,1};
    long long factorial[N] = {0,1,2,6};
    for(int i = 3;i < N;i++)
    {
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
        factorial[i] = i * factorial[i - 1];
    }
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        printf("%.2f%%\n",(double)dp[n] / factorial[n] * 100);
    }
}
