#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define MAXN 10010
const double PI = acos(-1.0);
int n,f,_;
double arr[MAXN];
bool ok(double mid)
{
    int cnt = 0;
    for(int i = 0;i < n;i++)
        cnt += arr[i] / mid;
    return cnt >= f + 1;
}
int main()
{
    cin >> _;
    while(_--)
    {
        cin >> n >> f;
        for(int i = 0;i < n;i++)
        {
            cin >> arr[i];
            arr[i] = arr[i] * arr[i] * PI;
        }
        double l = 0,r = 1e9;
        while(r - l > 1e-5)
        {
            double mid = (l + r) / 2;
            if(ok(mid))l = mid;
            else r = mid;
        }
        printf("%.4f\n",l);
    }
}
