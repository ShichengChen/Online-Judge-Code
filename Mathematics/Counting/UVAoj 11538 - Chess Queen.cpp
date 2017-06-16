#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef unsigned long long ull;
#define MAXN 1000005
ull s[MAXN];
ull n,m;
int main()
{
    for(ull i = 1;i < MAXN;i++)
        s[i] = s[i - 1] + (i + 1) * i / 2;
    while(cin >> n >> m && (n | m))
    {
        if(n > m)swap(n,m);
        ull ans1 = (n * m) * ((n - 1) + (m - 1));
        //cout << ans1 << " ans1 "  << endl;
        ull ans2 = 4 * (m - n) * ((n - 1) * n / 2);
        //cout << ans2 << " ans2 " << endl;
        ull ans3 = 4 * ((n - 1) * n / 2 * n - s[n - 1]);
        //cout << ans3 << " ans3 " << endl;
        cout << ans1 + ans2 + ans3 << endl;
    }
}

