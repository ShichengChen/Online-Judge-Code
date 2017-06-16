#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
#define MAXN 50005
#define lowbit(i) (i & -i)
int num[MAXN << 1],n,w,h,lans;
LL total,ans,cur,s[MAXN],prefix[MAXN];
LL sum(int i,LL * a)
{
    LL total = a[0];
    for(;i;i -= lowbit(i))
        total += a[i];
    return total;
}
void modify(int i,LL * a,int key)
{
    if(!i)a[i] += key;
    else for(;i < MAXN;i += lowbit(i))a[i] += key;
}
void findbigger()
{
    int h1 = max((LL)h,cur / w) , h2 = max(cur / w + 1,(LL)h);
    h1 = min((LL)h1,total / w), h2 = min((LL)h2,total / w);
    LL cur1 = sum(h1,prefix),cur2 = sum(h2,prefix);
    int w1 = sum(h1,s),w2 = sum(h2,s);
    LL les1 = w1 * h1 - cur1;
    LL les2 = w2 * h2 - cur2;
    LL more1 = (cur - cur1) - (w - w1) * h1;
    LL more2 = (cur - cur2) - (w - w2) * h2;
    LL a = max(les1,more1),b = max(les2,more2);
    if(ans > min(a,b))
    {
        ans = min(a,b);
        lans = a < b ? h1 : h2;
    }
    else if(ans == min(a,b))
        lans = max(lans,a < b ? h1 : h2);
}
void oper(int i,int neg)
{
    modify(num[i],s,neg);
    modify(num[i],prefix,neg * num[i]);
    cur += neg * num[i];
}
bool solve()
{
    if((LL)w * h > total)return true;
    modify(0,s,w);
    for(int i = 0,j = i - w;i < n + w;i++,j++)
    {
        oper(i,1);
        if(j >= 0)oper(j,-1);
        else modify(0,s,-1);
        findbigger();
    }
    return false;
}
int main()
{
    while(scanf("%d%d%d",&n,&w,&h) != EOF)
    {
        cur = total = 0,ans = 1e9,lans = h;
        memset(prefix,0,sizeof(prefix));
        memset(num,0,sizeof(num));
        memset(s,0,sizeof(s));
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&num[i]);
            total += num[i];
        }
        if(solve())puts("-1");
        else printf("%d %I64d\n",lans,ans);
    }
}
