#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 110
#define N 16
int d[(1 << N) + 10][MAXN],w[N],sum[(1 << N) + 10];
int n,x,y;
bool dfs(int s,int l)
{
    if(d[s][l] != -1)return d[s][l];
    if(!((s - 1) & s))return true;
    int r = sum[s] / l;
    for(int p = (s - 1) & s;p;p = s & (p - 1))
    {
        int q = s - p;
        if(!(sum[p] % l) && !(sum[q] % l))
            if(dfs(p,min(l,sum[p] / l)) && dfs(q,min(l,sum[q] / l)))
                return d[s][l] = true;
        if(!(sum[p] % r) && !(sum[q] % r))
            if(dfs(p,min(r,sum[p] / r)) && dfs(q,min(r,sum[q] / r)))
                return d[s][l] = true;
    }
    return d[s][l] = false;
}
int main()
{
    int kcas = 1;
    while(cin >> n && n)
    {
        cin >> x >> y;
        for(int i = 0;i < n;i++)cin >> w[i];
        memset(d,-1,sizeof(d));
        memset(sum,0,sizeof(sum));
        int all = (1 << n) - 1;
        for(int i = 1;i <= all;i++)
            for(int j = 0;j < n;j++)
                if(i >> j & 1)sum[i] += w[j];
        bool ans;
        if(sum[all] != x * y)ans = false;
        else ans = dfs(all,min(x,y));
        printf("Case %d: %s\n",kcas++, ans ? "Yes" : "No");
    }
}
