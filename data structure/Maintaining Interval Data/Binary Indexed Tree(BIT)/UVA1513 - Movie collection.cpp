#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 100010
#define lowbit(i) (i & -i)
int prefix[MAXN << 1],ind[MAXN];
void modify(int i,int maxn,int key)
{
    for(;i < maxn;i += lowbit(i))
        prefix[i] += key;
}
int sum(int i)
{
    int total = 0;
    for(;i;i -= lowbit(i))
        total += prefix[i];
    return total;
}
int main()
{
    int _,n,m;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        memset(prefix,0,sizeof(prefix));
        for(int i = 1;i <= n;i++)
        {
            ind[i] = n - i + 1;
            modify(i,MAXN << 1,1);
        }
        int cur = n,num;
        while(m--)
        {
            scanf("%d",&num);
            if(m)
                printf("%d ",n - sum(ind[num]));
            else
                printf("%d\n",n - sum(ind[num]));
            modify(ind[num],MAXN << 1,-1);
            ind[num] = ++cur;
            modify(ind[num],MAXN << 1,1);
        }
    }
}
