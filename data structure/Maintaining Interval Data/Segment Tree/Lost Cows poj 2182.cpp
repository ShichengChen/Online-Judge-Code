#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define MAXN 8100
int const root = 1;
int cow[MAXN],ans[MAXN];
struct Node
{
    int l,r,len;
}node[MAXN * 4];
void build(int l,int r,int cnt)
{
    node[cnt].l = l;
    node[cnt].r = r;
    node[cnt].len = r - l + 1;
    if(l == r)return;
    int mid = l + r >> 1;
    build(l,mid,cnt << 1);
    build(mid + 1,r,cnt << 1 | 1);
}
int query(int kth,int cnt)
{
    node[cnt].len--;
    if(node[cnt].l == node[cnt].r)return node[cnt].l;
    if(node[cnt << 1].len >= kth)return query(kth,cnt << 1);
    else return query(kth - node[cnt << 1].len,cnt << 1 | 1);
}
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        build(1,n,root);   cow[1] = 0;
        for(int i = 2;i <= n;i++)scanf("%d",&cow[i]);
        for(int i = n;i >= 1;i--)ans[i] = query(cow[i] + 1,root);
        for(int i = 1;i <= n;i++)printf("%d\n",ans[i]);
    }
}
