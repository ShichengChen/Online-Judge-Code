#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAXN 105
const double g = 10.0;
double ans[MAXN];
double solve(int t,double h)
{
    if(t < 0)return h;
    double ct = sqrt(2 * h / g);
    int k = (int)(t / ct);
    if(k & 1)
    {
        double cur = (k * ct + ct - t) * (k * ct + ct - t);
        return h - g * cur / 2;
    }
    else
    {
        double cur = (t - k * ct) * (t - k * ct);
        return h - g * cur / 2;
    }
}
int main()
{
    int _,n,t;
    double r,h;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%lf%lf%d",&n,&h,&r,&t);
        r /= 100.0;
        for(int i = 0;i < n;i++)
            ans[i] = solve(t - i,h);
        sort(ans,ans + n);
        for(int i = 0;i < n;i++)
            if(i != n - 1)printf("%.2f ",ans[i] + i * 2 * r);
            else printf("%.2f\n",ans[i] + i * 2 * r);
    }
}
