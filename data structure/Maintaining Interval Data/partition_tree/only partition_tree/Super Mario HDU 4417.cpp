#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100001
#define LOG 20
int sorted[MAXN] , part_tree[MAXN][LOG] , left_cnt[MAXN][LOG];
int ql,qr;
void build(int l,int r,int deep)
{
    if(l == r)return;
    int mid = l + r >> 1 , same = left_cnt[0][deep] = 0;
    for(int i = mid;i >= l;i--)
        if(sorted[mid] == sorted[i])same++;
        else break;
    int lcnt = l , rcnt = mid + 1;
    for(int i = l;i <= r;i++)
    {
        if(part_tree[i][deep] < sorted[mid])
            part_tree[lcnt++][deep + 1] = part_tree[i][deep];
        else if(part_tree[i][deep] == sorted[mid] && same)
        {
            part_tree[lcnt++][deep + 1] = part_tree[i][deep];
            same--;
        }
        else
            part_tree[rcnt++][deep + 1] = part_tree[i][deep];
        left_cnt[i][deep] = lcnt - l + left_cnt[l - 1][deep];
    }
    build(l,mid,deep + 1) , build(mid + 1,r,deep + 1);
}
int query(int l,int r,int deep,int ql,int qr,int kth)
{
    if(ql == qr)return part_tree[ql][deep];
    int mid = l + r >> 1;
    int lcnt = left_cnt[qr][deep] - left_cnt[ql - 1][deep];
    if(lcnt >= kth)
    {
        ql = l + left_cnt[ql - 1][deep] - left_cnt[l - 1][deep];
        qr = ql + lcnt - 1;
        return query(l,mid,deep + 1,ql,qr,kth);
    }
    else
    {
        qr += left_cnt[r][deep] - left_cnt[qr][deep];
        ql += left_cnt[r][deep] - left_cnt[ql - 1][deep];
        return query(mid + 1,r,deep + 1,ql,qr,kth - lcnt);
    }
}
int binary(int val,int n)
{
    int l = 1 , r = qr - ql + 1;
    if(query(1,n,0,ql + 1,qr + 1,1) > val)return 0;
    while(l < r)
    {
        int mid = l + r + 1 >> 1;
        if(query(1,n,0,ql +1,qr + 1,mid) <= val)l = mid;
        else r = mid - 1;
    }
    return r;
}
int main()
{
    int _,n,m,kth,val;
    scanf("%d",&_);
    for(int kcase = 1;kcase <= _;kcase++)
    {
        printf("Case %d:\n",kcase);
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&part_tree[i][0]);
            sorted[i] = part_tree[i][0];
        }
        sort(sorted + 1,sorted + n + 1);
        build(1,n,0);
        while(m--)
        {
            scanf("%d%d%d",&ql,&qr,&val);
            int ans = binary(val,n);
            printf("%d\n",ans);
        }
    }
}
