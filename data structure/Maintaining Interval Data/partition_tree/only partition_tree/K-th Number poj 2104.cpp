#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100010
#define LOG 20
int sort_array[N] , left_cnt[N][LOG];
int partition_tree[N][LOG];
int ql , qr;
void build(int l,int r,int deep)
{
    if(l == r)return;
    int mid = l + r >> 1;
    int same = 0;
    left_cnt[0][deep] = 0;
    for (int i = mid;i >= l;i--)
        if (sort_array[i] == sort_array[mid])
            same++;
        else break;
    int lcnt = l , rcnt = mid + 1;
    for(int i = l;i <= r;i++)
    {
        if(partition_tree[i][deep] < sort_array[mid])
            partition_tree[lcnt++][deep + 1] = partition_tree[i][deep];
        else if(partition_tree[i][deep] == sort_array[mid] && same)
        {
            partition_tree[lcnt++][deep + 1] = partition_tree[i][deep];
            same--;
        }
        else
            partition_tree[rcnt++][deep + 1] = partition_tree[i][deep];
        left_cnt[i][deep] = lcnt - l + left_cnt[l - 1][deep];
    }
    build(l , mid , deep + 1) , build(mid + 1 , r , deep + 1);
}
int query(int l,int r,int deep,int kth)
{
    if(ql == qr)return partition_tree[ql][deep];
    int mid = l + r >> 1;
    int lcnt = left_cnt[qr][deep] - left_cnt[ql - 1][deep];
    if(lcnt >= kth)
    {
        ql = l + left_cnt[ql - 1][deep] - left_cnt[l - 1][deep];
        qr = ql + lcnt - 1;
        return query(l,mid,deep + 1,kth);
    }
    else
    {
        ql += lcnt + left_cnt[r][deep] - left_cnt[qr][deep];
        qr += left_cnt[r][deep] - left_cnt[qr][deep];
        return query(mid + 1,r,deep + 1,kth - lcnt);
    }

}
int main()
{
    int n,m,l,r,kth;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&partition_tree[i][0]);
            sort_array[i] = partition_tree[i][0];
        }
        sort(sort_array + 1,sort_array + n + 1);
        build(1,n,0);
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d%d",&ql,&qr,&kth);
            int ans = query(1,n,0,kth);
            printf("%d\n",ans);
        }
    }
}
