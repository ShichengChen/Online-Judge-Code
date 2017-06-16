#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 101000
#define lowbit(i) (i & (-i))
struct ELE
{
    int ele,index;
    bool operator < (const ELE & el)const
    {
        return ele > el.ele;
    }
}element[MAXN];
long long partsum[MAXN],partn[MAXN];
long long getsum(int i)
{
    long long total = 0;
    while(i)
    {
        total += partsum[i];
        i -= lowbit(i);
    }
    return total;
}
int getn(int i)
{
    int total = 0;
    while(i)
    {
        total += partn[i];
        i -= lowbit(i);
    }
    return total;
}
void modifyindex(int i,int maxn,int key)
{
    while(i <= maxn)
    {
        partn[i] += key;
        i += lowbit(i);
    }
}
void modifynum(int i,int maxn,int key)
{
    while(i <= maxn)
    {
        partsum[i] += key;
        i += lowbit(i);
    }
}
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        memset(partsum,0,sizeof(partsum));
        memset(partn,0,sizeof(partn));
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&element[i].ele);
            element[i].index = i + 1;
        }
        sort(element,element + n);
        long long ans = 0;
        for(int i = 0;i < n;i++)
        {
            long long num = getn(element[i].index);
            ans += (getsum(element[i].index) +  num * element[i].ele);
            modifyindex(element[i].index,MAXN,1);
            modifynum(element[i].index,MAXN,element[i].ele);
        }
        printf("%I64d\n",ans);
    }
}
