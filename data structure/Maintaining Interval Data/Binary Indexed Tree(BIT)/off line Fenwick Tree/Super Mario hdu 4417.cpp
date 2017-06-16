#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100002
#define lowbit(i) (i & (-i))
int prefix[MAXN],ans[MAXN];
struct Interval
{
    int h,index;
    bool operator < (const Interval & inter)const{
        return h < inter.h;
    }
}interval[MAXN];
struct Query
{
    int l,r,h,id;
    bool operator < (const Query & qu)const{
        return h < qu.h;
    }
}query[MAXN];
int sum(int i)
{
    int total = 0;
    while(i)
    {
        total += prefix[i];
        i -= lowbit(i);
    }
    return total;
}
void modify(int i,int maxn,int key)
{
    while(i <= maxn)
    {
        prefix[i] += key;
        i += lowbit(i);
    }
}
int main()
{
    int _,n,m,ql,qr,val;
    scanf("%d",&_);
    for(int kcase = 1;kcase <= _;kcase++)
    {
        printf("Case %d:\n",kcase);
        scanf("%d%d",&n,&m);
        memset(prefix,0,sizeof(prefix));
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&interval[i].h);
            interval[i].index = i;
        }
        for(int i = 1;i <= m;i++)
        {
            scanf("%d%d%d",&query[i].l,&query[i].r,&query[i].h);
            query[i].id = i;
        }
        sort(interval + 1,interval + n + 1);
        sort(query + 1,query + m + 1);
        for(int j = 1,i = 1;i <= m;i++)
        {
            while(j != m + 1 && interval[j].h <= query[i].h)
            {
                modify(interval[j].index,n,1);
                j++;
            }
            ans[query[i].id] = sum(query[i].r + 1) - sum(query[i].l);
        }
        for(int i = 1;i <= m;i++)
            printf("%d\n",ans[i]);
    }
}
