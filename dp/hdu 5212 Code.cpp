#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long LL;
#define MAXN 10015
#define MOD 10007
int num[MAXN],d[MAXN],n;
int main()
{
    while(cin >> n)
    {
        memset(num,0,sizeof(num));
        memset(d,0,sizeof(d));
        for(int i = 0;i < n;i++)
        {
            int cur;
            scanf("%d",&cur);
            num[cur]++;
        }
        for(int i = 2;i < MAXN;i++)
        {
            for(int j = i;j < MAXN;j += i)
                d[i] += num[j];
            d[i] *= d[i];
        }
        int ans = 0;
        for(int i = MAXN - 1;i >= 2;i--)
        {
            if(!d[i])continue;
            for(int j = i * 2;j < MAXN;j += i)
                d[i] -= d[j];
            ans = (ans + (LL)d[i] * i * (i - 1)) % MOD;
        }
        cout << ans << endl;
    }
}
