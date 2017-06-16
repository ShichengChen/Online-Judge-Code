#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 23
long long d1[MAXN],d2[MAXN];
int main()
{
    d1[1] = 1,d2[1] = 2;
    for(int i = 2;i < MAXN;i++)
    {
        d2[i] = 2 + 3 * d2[i - 1];
        d1[i] = 1 + d1[i - 1] + d2[i - 1];
    }
    int n,_;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        printf("%I64d\n",2 + (d1[n - 1] << 1));
    }
}
