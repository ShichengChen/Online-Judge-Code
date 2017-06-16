#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define lowbit(i) (i & -i)
#define MAXN 200010
#define LOG 18
int prefix[MAXN],fa[MAXN],ind[MAXN];
void modify(int i,int maxn,int key)
{
    for(;i <= maxn;i += lowbit(i))
        prefix[i] += key;
}
int sum(int i)
{
    int total = 0;
    for(;i;i -= lowbit(i))
        total += prefix[i];
    return total;
}
int findfa(int i)
{
    return fa[i] == i ? i : fa[i] = findfa(fa[i]);
}
int find_kth(int n,int num)
{
    int ans = 0;
    for(int i = LOG;i >= 0;i--)
    {
        int cur = 1 << i;
        if(ans + cur > n || prefix[ans + cur] >= num)
            continue;
        ans += cur;
        num -= prefix[ans];
    }
    return ans + 1;
}
int main()
{
    int n,m,c,u,v,num;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        memset(prefix,0,sizeof(prefix));
        for(int i = 1;i <= n;i++)
        {
            ind[i] = 1;
            fa[i] = i;
        }
        modify(1,n,n);
        num = n;
        while(m--)
        {
            scanf("%d",&c);
            if(c)
            {
                scanf("%d",&u);
                int kth = find_kth(n,num - u + 1);
                printf("%d\n",kth);
            }
            else
            {
                scanf("%d%d",&u,&v);
                int fau = findfa(u),fav = findfa(v);
                if(fau == fav)continue;
                modify(ind[fau],n,-1),modify(ind[fav],n,-1);
                modify(ind[fau] + ind[fav],n,1);
                fa[fau] = fav;
                ind[fav] = ind[fau] + ind[fav];
                num--;
            }

        }
    }
}
