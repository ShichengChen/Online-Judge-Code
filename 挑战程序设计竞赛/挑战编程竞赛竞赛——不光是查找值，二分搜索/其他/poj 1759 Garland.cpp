#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
double n,u;
bool isfind(double val)
{
    double v1 = u,v2;
    for(double i = 2;i < n;i++)
    {
        v2 = ((n - i) * v1 + val - (n - i + 1) * (n - i)) / (n - i + 1);
        if(v2 < 0)return false;
        else v1 = v2;
    }
    return true;
}
double binary()
{
    double l = 0,r = 1e15;
    for(int i = 0;i < 100;i++)
    {
        double mid = (l + r) / 2;
        if(isfind(mid))r = mid;
        else l = mid;
    }
    return l;
}
int main()
{
    while(scanf("%lf%lf",&n,&u) != EOF)
    {
        double ans = binary();
        printf("%.2f\n",ans);
    }
}
