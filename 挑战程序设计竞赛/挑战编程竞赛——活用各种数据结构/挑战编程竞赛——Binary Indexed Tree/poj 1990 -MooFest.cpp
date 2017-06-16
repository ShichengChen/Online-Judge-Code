#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef pair<int,int>pii;
#define MAXN 20005
#define lowbit(i) (i & -i)
#define x first
#define y second
pii arr[MAXN];
int num[MAXN],val[MAXN];
void add(int * cur,int i,int v)
{
    for(;i < MAXN;i += lowbit(i))
        cur[i] += v;
}
int sum(int * cur,int i)
{
    int ans = 0;
    for(;i;i -= lowbit(i))
        ans += cur[i];
    return ans;
}
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 0;i < n;i++)
            scanf("%d%d",&arr[i].x,&arr[i].y);
        sort(arr,arr + n);
        memset(num,0,sizeof(num));
        memset(val,0,sizeof(val));
        long long ans = 0,total = 0;;
        for(int i = 0;i < n;i++)
        {
            int l = sum(num,arr[i].y);
            int v = total - sum(val,arr[i].y) * 2;
            ans += arr[i].x * (v + (l * 2 - i) * (long long)arr[i].y);
            total += arr[i].y;
            add(val,arr[i].y,arr[i].y);
            add(num,arr[i].y,1);
        }
        printf("%lld\n",ans);
    }
}
