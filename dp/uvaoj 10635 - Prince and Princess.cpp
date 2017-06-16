#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int const MAXN = 250 * 250 + 10;
int idx[MAXN],num[MAXN],d[MAXN];
int main()
{
    int _,n,m,p,cur;
    cin >> _;
    int kcas = 1;
    while(_--)
    {
        cin >> n >> m >> p;
        memset(idx,0,sizeof(idx));
        for(int i = 1;i <= m + 1;i++)
        {
            cin >> cur;
            idx[cur] = i;
        }
        for(int i = 0;i < p + 1;i++)
        {
            cin >> cur;
            num[i] = idx[cur];
        }
        memset(d,0x3f,sizeof(d));
        int ans = 0;
        for(int i = 0;i < p + 1;i++)
        {
            int ind = lower_bound(d,d + p + 1,num[i]) - d;
            ans = max(ans,ind);
            d[ind] = num[i];
        }
        printf("Case %d: %d\n",kcas++,ans + 1);
    }
}
