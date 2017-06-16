#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,int>pii;
#define MAXN 300000
#define MAXM 40
#define X first
#define Y second
#define ABS(i) (((i)>=0)?(i):-(i))
pii sum[MAXN],ans;
LL arr[MAXM];
int n,mid;
void check(LL cur,int num)
{
    int ind = lower_bound(sum,sum + (1 << mid),pii(-cur,0)) - sum;
    for(int i = min(ind,(1 << mid) - 1);i >= max(ind - 1,0);i--)
        ans = min(ans,pii(ABS(cur + sum[i].X),num + sum[i].Y));
}
int main()
{
    while(scanf("%d",&n),n)
    {
        for(int i = 0;i < n;i++)
            scanf("%lld",&arr[i]);
        mid = n >> 1;
        ans = pii(ABS(arr[0]),1);
        for(int i = 0;i < 1 << mid;i++)
        {
            int num = 0;
            sum[i].X = 0;
            for(int j = 0;j < mid;j++)if(i >> j & 1)
            {
                num++;
                sum[i].X += arr[j];
            }
            sum[i].Y = num;
            if(i)ans = min(ans,pii(ABS(sum[i].X),sum[i].Y));
        }
        sort(sum,sum + (1 << mid));
        for(int i = 0;i < (1 << mid) - 1;i++)
            if(sum[i].X == sum[i + 1].X)
                sum[i + 1].Y = sum[i].Y;
        for(int i = 1;i < 1 << (n - mid);i++)
        {
            LL cur = 0;
            int num = 0;
            for(int j = 0;j < n - mid;j++)if(i >> j & 1)
            {
                num++;
                cur += arr[mid + j];
            }
            check(cur,num);
        }
        printf("%lld %d\n",ans.X,ans.Y);
    }
}
