#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 5;
int n;
ll num[MAXN],arr[MAXN],total;
int main()
{
    while(scanf("%d",&n) != EOF)
    {
        total = 0;
        for(int i = 0;i < n;i++)
        {
            scanf("%lld",&num[i]);
            total += num[i];
        }
        ll ave = total / n,cur = 0,ans = 0;
        for(int i = 1;i < n;i++)
            arr[i] = arr[i - 1] + num[i] - ave;
        sort(arr,arr + n);
        for(int i = 0;i < n;i++)
            ans += abs(arr[i] - arr[n / 2]);
        printf("%lld\n",ans);
    }
}
