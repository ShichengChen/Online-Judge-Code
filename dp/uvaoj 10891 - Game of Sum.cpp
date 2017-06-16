#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 105
int d[MAXN][MAXN],f[MAXN][MAXN],g[MAXN][MAXN],s[MAXN];
int main()
{
    int n;
    while(cin >> n && n)
    {
        for(int i = 1;i <= n;i++)
        {
            cin >> s[i];
            f[i][i] = g[i][i] = d[i][i] = s[i];
            s[i] += s[i - 1];
        }
        for(int k = 1;k < n;k++)
            for(int j = 1 + k;j <= n;j++)
        {
            int i = j - k;
            d[i][j] = s[j] - s[i - 1] - min(min(f[i + 1][j],g[i][j - 1]),0);
            f[i][j] = min(d[i][j],f[i + 1][j]);
            g[i][j] = min(d[i][j],g[i][j - 1]);
        }
        cout << 2 * d[1][n] - s[n] << endl;
    }
}
