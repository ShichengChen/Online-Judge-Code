#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 1000
int main()
{
    int n,kcas = 1;
    while(cin >> n && n)
    {
        long long ans = 0;
        if(n < 4 || (n & 1))ans = 0;
        else
        {
            long long o = (n - 4) / 2;
            long long p = o * (o + 1) * (o + 2) * (o + 3) / 24;
            long long a = (o + 1) * (o + 2) * (o + 3) * (o + 4) / 24;
            ans = p + a;
        }
        printf("Case %d: %lld\n",kcas++,ans);
    }
}
