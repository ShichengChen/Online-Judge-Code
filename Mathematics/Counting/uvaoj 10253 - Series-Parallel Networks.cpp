#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 40
typedef long long ll;
ll d[MAXN][MAXN],s[MAXN];
ll getsum(int k,int u,int v = MAXN)
{
    ll ans = 0;
    for(int i = u;i < v;i++)
        ans += d[k][i];
    return ans;
}
ll C(ll n,ll m)
{
    double ans = 1;
    for(int i = 0;i < m;i++)
        ans *= n - i;
    for(int i = 1;i <= m;i++)
        ans /= i;
    return (ll)(ans + 0.5);
}
int main()
{
    int n;
    s[1] = 1;s[2] = 1,s[3] = 2;s[4] = 5;
    d[2][1] = d[2][2] = 1;
    for(int i = 3;i <= 30;i++)
    {
        for(int j = 1;j <= i / 2;j++)
        {
            for(int k = 1;j * k <= i;k++)
            {
                int surplus = i - j * k;
                if(!surplus)d[i][j] += C(s[j] + k - 1,k);
                else if(surplus > j)
                    d[i][j] += getsum(surplus,j + 1) * C(s[j] + k - 1,k);
            }
        }
        s[i] = d[i][i] = getsum(i,1);
    }
    while(cin >> n && n)
    {
        if(n != 1)cout << 2 * s[n] << endl;
        else puts("1");
    }
}
