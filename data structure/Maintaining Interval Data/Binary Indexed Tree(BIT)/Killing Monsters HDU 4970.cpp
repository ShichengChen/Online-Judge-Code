#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 100010
long long damage[MAXN];
int main()
{
    int n,m,l,r,d,k,x;
    long long h;
    while(scanf("%d",&n) , n)
    {
        scanf("%d",&m);
        memset(damage,0,sizeof(damage));
        while(m--)
        {
            scanf("%d%d%d",&l,&r,&d);
            damage[l] += d;
            damage[r + 1] -= d;
        }
        for(int i = 2;i <= n;i++)
            damage[i] += damage[i - 1];
        for(int i = n -1;i > 0;i--)
            damage[i] += damage[i + 1];
        scanf("%d",&k);
        int ans = 0;
        while(k--)
        {
            scanf("%I64d%d",&h,&x);
            if(damage[x] < h)ans++;
        }
        printf("%d\n",ans);
    }
}
