#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 1005
double x[MAXN],y[MAXN],cur[MAXN];
int n,m;
bool isfind(double mid)
{
    for(int i = 0;i < n;i++)
        cur[i] = x[i] - mid * y[i];
    sort(cur,cur + n);
    double tem = 0;
    for(int i = m;i < n;i++)
        tem += cur[i];
    return tem >= 0;
}
double binary()
{
    double l = 0,r = 1;
    for(int i = 0;i < 50;i++)
    {
        double mid = (l + r) / 2;
        if(isfind(mid))l = mid;
        else r = mid;
    }
    return l;
}
int main()
{
    while(scanf("%d%d",&n,&m),n | m)
    {
        for(int i = 0;i < n;i++)
            scanf("%lf",&x[i]);
        for(int i = 0;i < n;i++)
            scanf("%lf",&y[i]);
        double ans = binary() * 100;
        printf("%.0f\n",ans);
    }
}
