#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define MAXN 10010
#define MAXL 100010
#define EPS 1e-9
double line[MAXN];
int n,k;
bool C(double l)
{
    int ans = 0;
    for(int i = 0;i < n;i++)
        ans += (int)(line[i] / l);
    return ans >= k;
}
double binary(double l,double r)
{
    for(int i = 1;i <= 100;i++)
    {
        double mid = (l + r) / 2;
        if(C(mid))l = mid;
        else r = mid;
    }
    return l;
}
int main()
{
    while(scanf("%d%d",&n,&k) != EOF)
    {
        for(int i = 0;i < n;i++)
            scanf("%lf",&line[i]);
        double ans = binary(0,MAXL);
        printf("%.2f\n",floor(ans * 100) / 100);
    }
}
