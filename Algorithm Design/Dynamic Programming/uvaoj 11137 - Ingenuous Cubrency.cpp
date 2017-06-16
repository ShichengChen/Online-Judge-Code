#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 10005
typedef long long ll;
ll d[2][MAXN];
int main()
{
    for(int i = 0;i < MAXN;i++)d[0][i] = 1;
    for(int i = 2;i * i * i < MAXN;i++)
    {
        for(int j = 0;j < MAXN;j++)
        {
            d[(i + 1) & 1][j] = d[i & 1][j];
            for(int k = 1;k * i * i * i <= j;k++)
            {
                d[(i + 1) & 1][j] += d[i & 1][j - k * i * i * i];
            }
        }
    }
    int n;
    while(cin >> n)
    {
        cout << max(d[0][n],d[1][n]) << endl;
    }
}
