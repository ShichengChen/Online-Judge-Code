#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define MAXN 70
int a[MAXN],b[MAXN];
ll solve(int from,int k,int *p)
{
    while(k >= 0 && from == p[k])k--;
    if(k < 0)return 0;
    return solve(6 - p[k] - from,k - 1,p) + ((ll)1 << k);
}
int main()
{
    int kcas = 1,n;
    while(cin >> n && n)
    {
        for(int i = 0;i < n;i++)cin >> a[i];
        for(int i = 0;i < n;i++)cin >> b[i];
        int k = n - 1;
        while(k >= 0 && a[k] == b[k])k--;
        ll ans = 0;
        if(k >= 0)
        {
            int other = 6 - a[k] - b[k];
            ans = solve(other,k - 1,a) + solve(other,k - 1,b) + 1;
        }
        printf("Case %d: %lld\n",kcas++,ans);
    }
}
