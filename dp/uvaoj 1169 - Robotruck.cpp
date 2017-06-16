#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define MAXN 100010
int x[MAXN],y[MAXN],d[MAXN],w[MAXN];
int _,c,n;
int dis(int i)
{
    return abs(x[i]) + abs(y[i]) + abs(x[i - 1]) + abs(y[i - 1]);
}
int main()
{
    cin >> _;
    while(_--)
    {
        scanf("%d%d",&c,&n);
        for(int i = 2;i <= n + 1;i++)
            scanf("%d%d%d",&x[i],&y[i],&w[i]);
        for(int i = 2;i <= n + 1;i++)
        {
            int weight = w[i],road = 0;
            d[i] = dis(i) + d[i - 1] + road;
            for(int j = 1;;j++)
            {
                int k = i - j;
                weight += w[k];
                road += abs(x[k + 1] - x[k]) + abs(y[k + 1] - y[k]);
                if(k <= 1 || weight > c)break;
                d[i] = min(d[i],dis(k) + d[k - 1] + road);
            }
        }
        cout << d[n + 1] + abs(x[n + 1]) + abs(y[n + 1]) << endl;
        if(_ > 0)puts("");
    }
}
