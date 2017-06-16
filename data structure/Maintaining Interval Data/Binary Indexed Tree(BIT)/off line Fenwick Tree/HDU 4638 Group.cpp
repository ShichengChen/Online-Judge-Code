#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100010
#define lowbit(i) (i & -i)
struct Query
{
    int s,e,id;
    bool operator < (const Query & q)const{
        return e < q.e;
    }
}query[MAXN];
int num[MAXN],pos[MAXN],prefix[MAXN],ans[MAXN];
void modify(int l,int r,int key)
{
    for(;l <= r;l += lowbit(l))
        prefix[l] += key;
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
            scanf("%d",&num[i]);
            pos[num[i]] = i;
        }
        for(int i = 1;i <= m;i++)
        {
            scanf("%d%d",&query[i].s,&query[i].e);
            query[i].id = i;
        }
        sort(query + 1,query + m + 1);
        for(int i = 1,j = 1;i <= n;i++)
        {
            modify(i,n,1);
            if(num[i] > 1 && pos[num[i] - 1] < i)modify(pos[num[i] - 1],n,-1);
            if(num[i] < n && pos[num[i] + 1] < i)modify(pos[num[i] + 1],n,-1);
            while(j <= m && query[j].e == i)
            {
                ans[query[j].id] = sum(query[j].e) - sum(query[j].s - 1);
                j++;
            }
        }
        for(int i = 1;i <= m;i++)
            printf("%d\n",ans[i]);
    }
}
