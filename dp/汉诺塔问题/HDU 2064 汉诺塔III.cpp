#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 37
long long dp[MAXN];
int main()
{
    for(int i = 1;i < MAXN;i++)
        dp[i] = dp[i - 1] * 3 + 2;
    int n;
    while(scanf("%d",&n) != EOF)
        printf("%I64d\n",dp[n]);
}
