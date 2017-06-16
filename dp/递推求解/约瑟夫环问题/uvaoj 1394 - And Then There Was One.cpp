#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN = 10005;
int d[MAXN];
int main()
{
    int n,k,m;
    while(cin >> n >> k >> m && n && k && m)
    {
        d[1] = 0;
        for(int i = 2;i < n;i++)d[i] = (d[i - 1] + k) % i;
        cout << (d[n - 1] + m) % n + 1 << endl;
    }
}
