#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 4005
int arr[4][MAXN],c[MAXN * MAXN];
int main()
{
    int n;
    long long ans;
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 0;i < n;i++)
            for(int j = 0;j < 4;j++)
                scanf("%d",&arr[j][i]);
        ans = 0;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
            c[i * n + j] = arr[0][i] + arr[1][j];
        sort(c,c + n * n);
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
            {
                int cur = arr[2][i] + arr[3][j];
                ans += upper_bound(c,c + n * n,-cur) - lower_bound(c,c + n * n,-cur);
            }
        printf("%lld\n",ans);
    }
}
