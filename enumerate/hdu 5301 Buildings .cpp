#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 10000
int n,m,x,y;
int solve()
{
    if(n == m && (n & 1) && (n + 1) / 2 == x && x == y)
        return n / 2;
    if(m == 1 || n == 1)return 1;
    if(x > n / 2)x = n - x + 1;
    if(y > m / 2)y = m - y + 1;
    int ans1 = min(max(x,n - x),max(y,m - y));
    int ans2 = min(max(x,(m + 1) / 2),max(y,(n + 1) / 2));
    int ans3 = max(x - 1,max(m - y,(m + 1) / 2));
    int ans4 = max(y - 1,max(n - x,(n + 1) / 2));
    return min(min(ans1,ans2),min(ans3,ans4));
}
int main()
{
    while(cin >> n >> m >> x >> y)
    {
        int ans = solve();
        cout << ans << endl;
    }
}
