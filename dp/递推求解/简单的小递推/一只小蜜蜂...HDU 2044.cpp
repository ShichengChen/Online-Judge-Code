#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define N 52
int main()
{
    int a,b,_;
    scanf("%d",&_);
    long long dp[N] = {1 , 1 , 1 , 2};
    for(int i = 3;i < N;i++)dp[i] = dp[i - 1] + dp[i - 2];
    while(_--)
    {
        scanf("%d%d",&a,&b);
        printf("%I64d\n",dp[b - a + 1]);
    }
}
