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
double dp[N];
int main()
{
    int _,n;
    double temp = 1.0;
    for(int i = 2;i < N;i++)
    {
        temp *= i;
        dp[i] = round(temp / e) / temp;
    }
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        printf("%.2f%%\n",dp[n] * 100);
    }
}
