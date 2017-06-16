#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long LL;
#define MAXN 1000005
LL d[MAXN];
int n;
int main()
{
    for(int i = 4,a = 1,b = 1;i < MAXN;i++)
    {
        d[i] = (LL)a * b + d[i - 1];
        if(a < b)a++;
        else b++;
    }
    while(scanf("%d",&n) && n >= 3)
        printf("%lld\n",d[n]);
}

