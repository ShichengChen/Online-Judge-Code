#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define N 200020
int a[N],b[N],c[N];
int main()
{
        int n,x,y,z;
        while(scanf("%d",&n) , n)
        {
            for(int i = 0;i < n;i++)
            {
                scanf("%d%d%d",&x,&y,&z);
                a[i] = x - y;
                b[i] = y - z;
                c[i] = x - z;
            }
            sort(a,a + n) , sort(b,b + n) , sort(c,c + n);
            long long ans = 0;
            for(long long i = 0;i < n;i++)
            {
                ans += (2 * i - n + 1) * a[i];
                ans += (2 * i - n + 1) * b[i];
                ans += (2 * i - n + 1) * c[i];
            }
            printf("%lld\n",ans / 2);
        }
}
