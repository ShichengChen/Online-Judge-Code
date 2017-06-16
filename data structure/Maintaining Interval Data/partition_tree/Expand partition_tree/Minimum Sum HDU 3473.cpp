#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100010
#define LOG 18
int tree[MAXN][LOG],prefix[MAXN][LOG],sorted[MAXN],ql,qr;
long long sum[MAXN] , lnum[MAXN][LOG] , ans;
void build(int l,int r,int deep)
{
    if(l == r)return;
    int same = 0 , mid = l + r >> 1;
    lnum[0][deep] = prefix[0][deep] = 0;
    for(int i = mid;i >= l;i--)
        if(sorted[i] == sorted[mid])same++;
        else break;
    int lcnt = l , rcnt = mid + 1;
    for(int i = l;i <= r;i++)
    {
        if(tree[i][deep] < sorted[mid])
        {
            tree[lcnt++][deep + 1] = tree[i][deep];
            lnum[i][deep] = lnum[i - 1][deep] + tree[i][deep];
        }
        else if(tree[i][deep] == sorted[mid] && same)
        {
            tree[lcnt++][deep + 1] = tree[i][deep];
            same--;
            lnum[i][deep] = lnum[i - 1][deep] + tree[i][deep];
        }
        else
        {
            tree[rcnt++][deep + 1] = tree[i][deep];
            lnum[i][deep] = lnum[i - 1][deep];
        }
        prefix[i][deep] = prefix[l - 1][deep] + lcnt - l;
    }
    build(l,mid,deep + 1) , build(mid + 1,r,deep + 1);
}
void query(int l,int r,int deep,int kth,bool even)
{
    if(qr == ql)
    {
        ans -= (even + 1) * tree[ql][deep];
        return;
    }
    int mid = l + r >> 1;
    int lcnt = prefix[qr][deep] - prefix[ql - 1][deep];
    if(kth <= lcnt)
    {
        ql = l + prefix[ql - 1][deep] - prefix[l - 1][deep];
        qr = ql + lcnt - 1;
        query(l,mid,deep + 1,kth,even);
    }
    else
    {
        ans -= (lnum[qr][deep] - lnum[ql - 1][deep]) * 2;
        qr += prefix[r][deep] - prefix[qr][deep];
        ql += prefix[r][deep] - prefix[ql - 1][deep];
        query(mid + 1,r,deep + 1,kth - lcnt,even);
    }
}
int main()
{
    int _,q,n;
    scanf("%d",&_);
    for(int cas = 1;cas <= _;cas++)
    {
        scanf("%d",&n);
        sum[0] = 0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&tree[i][0]);
            sorted[i] = tree[i][0];
            sum[i] = sum[i - 1] + tree[i][0];
        }
        sort(sorted + 1,sorted + n + 1);
        build(1,n,0);
        scanf("%d",&q);
        printf("Case #%d:\n",cas);
        while(q--)
        {
            scanf("%d%d",&ql,&qr);
            ql++ , qr++;
            ans = sum[qr] - sum[ql - 1];
            query(1,n,0,(qr - ql + 2) / 2,(qr - ql) % 2);
            printf("%I64d\n",ans);
        }
        puts("");
    }
}
