#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 200005
int rock[MAXN],n,m,l;
int solve()
{
    int cur = 0,ans = 0,step = 0;
    for(int i = 1;i < n && rock[i] <= m && cur != m;i++)
    {
        int len = rock[i] - rock[i - 1];
        if(len + step <= l)
            step += len;
        else if(len <= l)
        {
            cur += step;
            step = len;
            ans++;
        }
        else if(step == 0)
        {
            ans += len / (l + 1) * 2;
            step = len % (l + 1);
            cur += len - step;
        }
        else
        {
            int x = (step + len) % (l + 1);
            int x2 = l + 1 - step;
            ans += (len + step) / (l + 1) * 2;
            if(x + x2 < l)
            {
                step = x + x2;
                ans--;
            }
            else if(x2 + x == l)
                step = 0;
            else if(x + x2 > l)
                step = x;
            cur = rock[i] - step;
        }
        if(step == l)
        {
            ans++;
            cur += step;
            step = 0;
        }
    }
    return ans + (bool)(m - cur);
}
int main()
{
    int _,ans;
    scanf("%d",&_);
    for(int kcas = 1;kcas <= _;kcas++)
    {
        scanf("%d%d%d",&n,&m,&l);
        for(int i = 0;i < n;i++)
            scanf("%d",&rock[i]);
        rock[n + 1] = 0 , rock[n] = m;
        sort(rock,rock + n + 2);
        n = unique(rock,rock + n + 2) - rock;
        ans = solve();
        printf("Case #%d: %d\n",kcas,ans);
    }
}
