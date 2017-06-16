#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 4000010
int phi[MAXN];
void phi_table()
{
    phi[1] = 1;
    for(int i = 2;i < MAXN;i++)if(!phi[i])
    {
        phi[i] = i - 1;
        for(int j = i * 2;j < MAXN;j += i)
        {
            if(!phi[j])phi[j] = j;
            phi[j] = phi[j] / i * (i - 1);
        }
    }
}
int main()
{
    phi_table();
    int n;
    while(cin >> n && n)
    {
        long long ans = 0;
        for(long long i = 2;i <= n;i++)
        {
            long long cur = n / i;
            ans += phi[i] * ((1 + cur) * cur / 2);
        }
        cout << ans << endl;
    }
}
