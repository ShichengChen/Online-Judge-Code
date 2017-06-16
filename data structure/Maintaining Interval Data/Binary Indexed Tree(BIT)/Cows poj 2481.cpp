#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define N 550000
#define RES 500005
struct COW
{
    int s,e,index,w;
    bool operator < (const COW & co)const
    {
        if(s == co.s)return e > co.e;
        return s < co.s;
    }
}cow[N];
int order[N],partsum[N];
int lowbit(int i)
{
    return i & (-i);
}
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
    int n;
    while(scanf("%d",&n),n)
    {
        memset(partsum,0,sizeof(partsum));
        for(int i = 0;i < n;i++)
        {
            scanf("%d%d",&cow[i].s,&cow[i].e);
            cow[i].index = i;
        }
        sort(cow,cow + n);
        cow[0].w = 0; modify(RES - cow[0].e,N,1);
        order[cow[0].index] = 0;
        for(int i = 1;i < n;i++)
        {
            if(cow[i].s == cow[i - 1].s && cow[i].e == cow[i - 1].e)
                cow[i].w = cow[i - 1].w;
            else cow[i].w = getsum(RES - cow[i].e);
            modify(RES - cow[i].e,N,1);
            order[cow[i].index] = i;
        }
        for(int i = 0;i < n;i++)
        {
            if(i != n - 1)printf("%d ",cow[order[i]].w);
            else printf("%d\n",cow[order[i]].w);
        }
    }
}
