#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long LL;
#define MAXN 50010
#define lowbit(i) ((i) & (-i))
LL pre2[MAXN],pre1[MAXN];
int arr[MAXN];
inline LL sum(int i,LL * cur)
{
    LL ans = 0;
    for(;i;i -= lowbit(i))
        ans += cur[i];
    return ans;
}
inline void modify(int i,int maxn,LL key,LL * cur)
{
    for(;i <= maxn;i += lowbit(i))
        cur[i] += key;
}
int main()
{
    int _,n;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
            scanf("%d",&arr[i]);
        memset(pre1,0,8 * n + 20);
        memset(pre2,0,8 * n + 20);
        LL prefix = 0,ans = 0;
        for(int i = 0;i < n;i++)
        {
            modify(arr[i],n,prefix,pre2);
            prefix += sum(arr[i],pre1);
            modify(arr[i],n,1,pre1);
            ans += sum(arr[i] - 1,pre2);
        }
        printf("%I64d\n",ans);
    }
}
