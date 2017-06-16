#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXP 22000
#define MAXS 110000
#define lowbit(i) (i & (-i))
int partsum[MAXS],member[MAXP];
int beh[MAXP],fro[MAXP];
int getsum(int i)
{
    int total = 0;
    while(i)
    {
        total += partsum[i];
        i -= lowbit(i);
    }
    return total;
}
void modify(int i,int maxn,int key)
{
    while(i <= maxn)
    {
        partsum[i] += key;
        i += lowbit(i);
    }
}
int main()
{
    int _,n,cur;scanf("%d",&_);
    while(_--)
    {
        memset(partsum,0,sizeof(partsum));
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&member[i]);
            fro[i] = getsum(member[i]);
            modify(member[i],MAXS,1);
        }
        memset(partsum,0,sizeof(partsum));
        for(int i = n;i >= 1;i--)
        {
            beh[i] = getsum(member[i]);
            modify(member[i],MAXS,1);
        }
        long long ans = 0;
        for(int i = 2;i <= n - 1;i++)
            ans += ((long long)(fro[i] * (n - i - beh[i])) + (long long)((i - 1 - fro[i]) * beh[i]));
        printf("%lld\n",ans);
    }
}
