#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 1005
int sorted[MAXN];
int main()
{
    int _,n,cur;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        int cnt = 0;
        if(n & 1)sorted[cnt++] = 0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&cur);
            sorted[cnt++] = cur;
        }
        sort(sorted,sorted + cnt);
        int nim = 0;
        for(int i = 0;i < cnt;i += 2)
            nim ^= sorted[i + 1] - sorted[i] - 1;
        if(nim)puts("Georgia will win");
        else puts("Bob will win");
    }
}
