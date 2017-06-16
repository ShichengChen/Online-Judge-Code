/*
part_sum is only the part of the sum
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX 110000
int partsum[MAX];
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
void modify(int i,int n,int key)
{
    while(i <= n)
    {
        partsum[i] += key;
        i += lowbit(i);
    }
}
int main()
{
    int l,r,n;
    while(scanf("%d",&n),n)
    {
        memset(partsum,0,sizeof(partsum));
        for(int i = 1;i <= n;i++)
        {
            scanf("%d%d",&l,&r);
            modify(l,n,1);
            modify(r + 1,n,-1);
        }
        for(int i = 1;i <= n;i++)
        {
            if(i != n)printf("%d ",getsum(i));
            else printf("%d\n",getsum(i));
        }
    }
}
