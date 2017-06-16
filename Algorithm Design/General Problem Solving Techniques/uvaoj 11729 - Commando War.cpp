#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 1005
struct Job
{
    int b,j;
    bool operator < (const Job & c)const{
        return j > c.j;
    }
}a[MAXN];
int main()
{
    int n,kcas = 1;
    while(cin >> n && n)
    {
        for(int i = 0;i < n;i++)
            cin >> a[i].b >> a[i].j;
        sort(a,a + n);
        int cur = 0,ans = 0;
        for(int i = 0;i < n;i++)
        {
            cur += a[i].b;
            ans = max(ans,cur + a[i].j);
        }
        printf("Case %d: %d\n",kcas++,ans);
    }
}
