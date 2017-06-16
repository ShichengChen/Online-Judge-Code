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
    int ans = 0;
    for(int i = 0;i < 16;i++)
    {
        int a = n,b = m,d = 0;
        if(i & 1)
        {
            a--;
            d++;
        }
        if(i & 2)
        {
            a--;
            d++;
        }
        if(i & 4)
        {
            b--;
            d++;
        }
        if(i & 8)
        {
            b--;
            d++;
        }
        if(d & 1)ans -= c[a * b][k];
        else ans += c[a * b][k];
    }
    //cout << ans << " ans " << endl;
    return (ans % MOD + MOD) % MOD;
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
