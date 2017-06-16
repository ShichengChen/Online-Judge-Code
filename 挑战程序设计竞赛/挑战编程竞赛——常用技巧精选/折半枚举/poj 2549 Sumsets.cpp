#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef pair<int,int>pii;
typedef pair<int,pii>node;
#define MAXN 1005
#define INF 0x3f3f3f3f
#define X first
#define Y second
int num[MAXN],n,cnt,dp[MAXN * MAXN];
node arr[MAXN * MAXN];
int run()
{
    for(int i = n - 1;i >= 0;i--)
    {
        for(int j = 0;j <= n - 1;j++)if(i != j)
        {
            int cur = num[i] - num[j];
            int *p1 = lower_bound(dp,dp + cnt,cur);
            int *p2 = upper_bound(dp,dp + cnt,cur);
            if(p1 == p2 && p1 == dp)break;
            for(int k = 0;k < p2 - p1 && k + p1 - dp < cnt;k++)
            {
                int ind = p1 - dp + k;
                if(arr[ind].Y.X != num[i] && arr[ind].Y.Y != num[i] &&
                   arr[ind].Y.X != num[j] && arr[ind].Y.Y != num[j])
                    return num[i];
            }
        }
    }
    return INF;
}
int main()
{
    while(scanf("%d",&n),n)
    {
        for(int i = 0;i < n;i++)
            scanf("%d",&num[i]);
        sort(num,num + n);
        cnt = 0;
        for(int i = 0;i < n;i++)
            for(int j = i + 1;j < n;j++)
            {
                arr[cnt].X = num[i] + num[j];
                arr[cnt].Y.X = num[i];
                arr[cnt++].Y.Y = num[j];
            }
        sort(arr,arr + cnt);
        for(int i = 0;i < cnt;i++)
            dp[i] = arr[i].X;
        int ans = run();
        if(ans != INF)printf("%d\n",ans);
        else puts("no solution");
    }
}
