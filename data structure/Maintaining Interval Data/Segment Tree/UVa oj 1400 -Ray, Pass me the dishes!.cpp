#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 500005
#define root 1
#define lcnt cnt << 1
#define rcnt cnt << 1 | 1
typedef pair<int,int> Interval;
typedef long long LL;
struct Node
{
    Interval sub;
    int prefix,suffix;
}node[MAXN << 2];
LL sum[MAXN];
int ql,qr;
Interval big(Interval a,Interval b)
{
    LL suma = sum[a.second] - sum[a.first - 1];
    LL sumb = sum[b.second] - sum[b.first - 1];
    if(suma != sumb)  return suma < sumb ? b : a;
    else return a < b ? a : b;
}
void build(int l,int r,int cnt)
{
    if(l == r)
    {
        node[cnt].sub.first = l , node[cnt].sub.second = r;
        node[cnt].prefix = r , node[cnt].suffix = l;
        return ;
    }
    int mid = l + r >> 1;
    build(l,mid,lcnt) , build(mid + 1,r,rcnt);
    node[cnt].sub = big(big(node[lcnt].sub,Interval(node[lcnt].suffix,node[rcnt].prefix)),node[rcnt].sub);
    node[cnt].prefix = big(Interval(l,node[lcnt].prefix),Interval(l,node[rcnt].prefix)).second;
    node[cnt].suffix = big(Interval(node[lcnt].suffix,r),Interval(node[rcnt].suffix,r)).first;
}
Interval prefix_query(int l,int r,int cnt)
{
    if(qr >= r)return Interval(l,node[cnt].prefix);
    int mid = l + r >> 1;
    if(qr <= mid)return prefix_query(l,mid,lcnt);
    Interval r_prefix = prefix_query(mid + 1,r,rcnt);
    r_prefix.first = l;
    return big(r_prefix,Interval(l,node[lcnt].prefix));
}
Interval suffix_query(int l,int r,int cnt)
{
    if(ql <= l)return Interval(node[cnt].suffix,r);   //recursion bound
    int mid = l + r >> 1;
    if(mid + 1 <= ql)return suffix_query(mid + 1,r,rcnt);   // only in the right
    Interval l_suffix = suffix_query(l,mid,lcnt);
    l_suffix.second = r;
    return big(l_suffix,Interval(node[rcnt].suffix,r));
}
Interval query(int l,int r,int cnt)
{
    if(ql <= l && r <= qr)return node[cnt].sub;
    int mid = l + r >> 1;
    if(qr <= mid)return query(l,mid,lcnt); // only in the left
    else if(ql >= mid + 1)return query(mid + 1,r,rcnt); //only in the right
    Interval suffix = suffix_query(l,mid,lcnt);
    Interval prefix = prefix_query(mid + 1,r,rcnt);
    Interval cas3 = big(query(l,mid,lcnt),query(mid + 1,r,rcnt));  //finding biggest either in left or right
    return big(Interval(suffix.first,prefix.second),cas3);
}
int main()
{
    int n,num_query,cas = 1;
    while(scanf("%d%d",&n,&num_query) != EOF)
    {
        sum[0] = 0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%lld",&sum[i]);
            sum[i] += sum[i - 1];
        }
        build(1,n,root);
        printf("Case %d:\n", cas++);
        while(num_query--)
        {
            scanf("%d%d",&ql,&qr);
            Interval ans = query(1,n,root);
            printf("%d %d\n",ans.first,ans.second);
        }
    }
}
