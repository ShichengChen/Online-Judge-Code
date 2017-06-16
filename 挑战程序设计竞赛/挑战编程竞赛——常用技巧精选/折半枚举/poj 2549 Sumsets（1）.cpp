#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 1005
#define INF 0x3f3f3f3f
int num[MAXN],arr[MAXN * MAXN],n,cnt;
bool check(int a,int b)
{
    int *p1 = lower_bound(num,num + n,a);
    int *p2 = lower_bound(num,num + n,b);
    if(p1 - num == n || p2 - num == n)
        return false;
    if(*p1 == a && *p2 == b)
        return true;
    return false;
}
int run()
{
    for(int i = n - 1;i >= 0;i--)
    {
        for(int j = 0;j <= n - 1;j++)if(i != j)
        {
            int cur = num[i] - num[j];
            int *p1 = lower_bound(arr,arr + cnt,cur);
            int *p2 = upper_bound(arr,arr + cnt,cur);
            if(p1 == p2 && p1 == arr)break;
            int dis = p2 - p1;
            if(dis)
            {
                if(check(num[j],cur - num[j]))
                    dis--;
                if(num[j] && check(num[i],-num[j]))
                    dis--;
                if(dis > 0)
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
                arr[cnt++] = num[i] + num[j];
        sort(arr,arr + cnt);
        int ans = run();
        if(ans != INF)printf("%d\n",ans);
        else puts("no solution");
    }
}
