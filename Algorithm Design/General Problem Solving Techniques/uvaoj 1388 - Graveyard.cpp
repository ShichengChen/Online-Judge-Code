#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m;
int main()
{
    while(cin >> n >> m)
    {
        double d1 = 10000.0 / n;
        double d2 = 10000.0 / (m + n);
        double ans = 0;
        for(int i = 0;i < n;i++)
        {
            double loc = d1 * i;
            ans += fabs(round(loc / d2) * d2 - loc);
        }
        printf("%.4lf\n",ans);
    }
}
