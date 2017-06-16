#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 200020
#define LOG 20
#define lowbit(i) (i & (-i))
int prefix[LOG][MAXN],sorted[LOG][MAXN],inde[MAXN];
long long ans;
int sum(int l,int r,int deep)
{
    int ans = 0;
    for(;r >= l;r -= lowbit(r))ans += prefix[deep][r];
    return ans;
}
void modify(int l,int r,int deep,int key)
{
    for(;l <= r;l += lowbit(l))prefix[deep][l] += key;
}
void build(int l,int r,int deep)
{
    for(int i = l;i <= r;i++)sorted[deep][i] = sorted[deep - 1][i];
    if(l == r)return;
    int mid = l + r >> 1;
    build(l,mid,deep + 1) , build(mid + 1,r,deep + 1);
    sort(sorted[deep] + l,sorted[deep] + r + 1);
}
void query(int l,int r,int deep,int ql,int qr,int val,bool big)
{
    if(ql > qr)return;
    if(ql <= l && r <= qr)
    {
        if(!big)
        {
            int len = lower_bound(sorted[deep] + l,sorted[deep] + r + 1,val) - (sorted[deep] + l);
            if(len == 0)return;
            int sub = sum(l,l + len - 1,deep);
            ans -= len - sub;
            return;
        }
        else
        {
            int len = (sorted[deep] + r + 1) - upper_bound(sorted[deep] + l,sorted[deep] + r + 1,val);
            if(len == 0)return;
            int sub = sum(l,r,deep) - sum(l,r - len,deep);
            ans -= len - sub;
            return;
        }
    }
    int mid = l + r >> 1;
    if(ql <= mid)query(l,mid,deep + 1,ql,qr,val,big);
    if(mid + 1 <= qr)query(mid + 1,r,deep + 1,ql,qr,val,big);
}
void updata(int l,int r,int deep,int val)
{
    if(l == r)
    {
        modify(l,r,deep,1);
        return;
    }
    int mid = l + r >> 1;
    if(inde[val] <= mid)updata(l,mid,deep + 1,val);
    else updata(mid + 1,r,deep + 1,val);
    int ind = lower_bound(sorted[deep] + l,sorted[deep] + r + 1,val) - (sorted[deep] + l);
    modify(ind + l,r,deep,1);
}
int main()
{
    int n,m,cur;
    while(scanf("%d%d",&n,&m) == 2)
    {
        ans = 0;
        memset(prefix,0,sizeof(prefix));
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&sorted[0][i]);
            inde[sorted[0][i]] = i;
            ans += (i - sum(1,sorted[0][i],0) - 1);
            modify(sorted[0][i],n,0,1);
        }
        build(1,n,1);
        for(int i = 1;i <= m;i++)
        {
            printf("%lld\n",ans);
            scanf("%d",&cur);
            if(ans)
            {
                query(1,n,1,1,inde[cur] - 1,cur,1);
                query(1,n,1,inde[cur] + 1,n,cur,0);
                updata(1,n,1,cur);
            }
        }
    }
}
