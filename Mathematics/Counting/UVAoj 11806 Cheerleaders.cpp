#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 505
#define MOD 1000007
int n,m,k,_,c[MAXN][MAXN];
int solve()
{
    if(k > n * m)return 0;
    int minn = c[(m - 2) * (n - 2)][k];
    int a1 = 2 * (c[(n - 1) * (m - 2)][k] - minn);
    int a2 = 2 * (c[(n - 2) * (m - 1)][k] - minn);
    int b1 = c[n * (m - 2)][k] - minn - a1;
    int b2 = c[(n - 2) * m][k] - a2 - minn;
    int c1 = 4 * (c[(m - 1) * (n - 1)][k] - a1 / 2 - a2 / 2 - minn);
    int d1 = 2 * (c[m * (n - 1)][k] - b2 - a1 / 2 - a2 - c1 / 2 - minn);
    int d2 = 2 * (c[(m - 1) * n][k] - b1 - a2 / 2 - a1 - c1 / 2 - minn);
    return ((c[n * m][k] - a1 - a2 - b1 - b2 - c1 - d1 - d2 - minn) % MOD + MOD) % MOD;
}
int main()
{
    scanf("%d",&_);
    for(int i = 0;i < MAXN;i++)c[i][0] = 1;
    for(int i = 1;i < MAXN;i++)
        for(int j = 1;j < MAXN;j++)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    int kcas = 0;
    while(_--)
    {
        scanf("%d%d%d",&n,&m,&k);
        int ans = solve();
        printf("Case %d: %d\n",++kcas,ans);
    }
}
