#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 50010
#define lowbit(i) (i & -i)
int prefix[MAXN],pos[MAXN],num[MAXN],ans[MAXN];
struct Query
{
    int l,r,ind;
    bool operator < (const Query & q)const{
        return l > q.l;
    }
}query[MAXN];
void modify(int i,int n,int key)
{
    for(;i <= n;i += lowbit(i))
        prefix[i] = max(prefix[i],key);
}
int getmax(int i)
{
    int maxn = 0;
    for(;i;i -= lowbit(i))
        maxn = max(prefix[i],maxn);
    return maxn;
}
int main()
{
    int _,n,m;
    scanf("%d",&_);
    while(_--)
    {
        memset(prefix,0,sizeof(prefix));
        memset(pos,0,sizeof(pos));
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            scanf("%d",&num[i]);
        scanf("%d",&m);
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d",&query[i].l,&query[i].r);
            query[i].ind = i;
        }
        sort(query,query + m);
        for(int i = n,j = 0;j < m;i--)
        {
            for(int k = 1;(long long)k * k <= num[i];k++)
            {
                if(num[i] % k)continue;
                if(pos[k])
                    modify(pos[k],n,k);
                pos[k] = i;
                if(k != num[i]/ k && pos[num[i] / k])
                    modify(pos[num[i] / k],n,num[i] / k);
                pos[num[i] / k] = i;
            }
            while(j < m && i == query[j].l)
            {
                ans[query[j].ind] = getmax(query[j].r);
                j++;
            }
        }
        for(int i = 0;i < m;i++)
            printf("%d\n",ans[i]);
    }
}
