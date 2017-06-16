/*
Dn=(n-1)(Dn-1+Dn-2)
Dn = n!Mn
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const double e = exp(1.0);
#define N 22
long long dp[N] , C[N][N];
int main()
{
    int _,n,m;

    dp[1] = 0 , dp[2] = 1;
    for(int i = 3;i < N;i++)
        dp[i] = (i - 1) * (dp[i - 2] + dp[i - 1]);
    //double temp = 1.0;
    /*for(int i = 2;i < N;i++)
    {
        temp *= i;
        dp[i] = (long long)(round(temp / e) + 0.5);
    }*/
    ///use double make wrong
    for(int i = 1;i < N;i++)
    {
        C[i][0] = C[i][i] = 1;
        for(int j = 1;j < i;j++)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        printf("%I64d\n",dp[m] * C[n][m]);
    }
}
