#include<iostream>
#include<cstdlib>
#include<cstdio>
#define MAX  55000
#define lson l,mid,cnt << 1
#define rson mid + 1,r,cnt << 1 | 1
#define lcnt cnt << 1
#define rcnt cnt << 1 | 1
#define ALL (r - l + 1)
using namespace std;
struct NODE
{
    int sum,rsum,lsum;
}node[MAX * 4];
int mark[MAX * 4];
int const root = 1;
void build(int l,int r,int cnt)
{
    node[cnt].sum = node[cnt].rsum = node[cnt].lsum = ALL;
    if(r == l)return;
    int mid = (r + l) >> 1;
    mark[cnt] = -1;
    build(lson); build(rson);
}
void uppush(int l,int r,int cnt)
{
    node[cnt].lsum = node[lcnt].lsum;
    node[cnt].rsum = node[rcnt].rsum;
    if(node[cnt].lsum == ALL - ALL / 2)node[cnt].lsum += node[rcnt].lsum;
    if(node[cnt].rsum == ALL / 2)node[cnt].rsum += node[lcnt].rsum;
    node[cnt].sum = max(max(node[lcnt].sum,node[rcnt].sum),node[lcnt].rsum + node[rcnt].lsum);
}
void pushdowm(int l,int r,int cnt)
{
    if(mark[cnt] != -1)
    {
        node[lcnt].rsum = node[lcnt].lsum = node[lcnt].sum = mark[cnt] ? 0 : ALL - ALL / 2;
        node[rcnt].rsum = node[rcnt].lsum = node[rcnt].sum = mark[cnt] ? 0 : ALL / 2;
        mark[lcnt] = mark[rcnt] = mark[cnt];
        mark[cnt] = -1;
    }
}
int query(int num,int l,int r,int cnt)
{
    if(l == r)return l;
    pushdowm(l,r,cnt);
    int mid = (l + r) >> 1;
    if(node[lcnt].sum >= num)
        return query(num,lson);
    else if(node[rcnt].lsum + node[lcnt].rsum >= num)
        return mid - node[lcnt].rsum + 1;
    else if(node[rcnt].sum >= num)
        return query(num,rson);
    else return 0;
}
void updata(int sign,int begin,int end,int l,int r,int cnt)
{
    if(begin <= l && r <= end)
    {
        mark[cnt] = sign;
        node[cnt].sum = node[cnt].lsum = node[cnt].rsum = sign ? 0 : ALL;
        return;
    }
    pushdowm(l,r,cnt);
    int mid = (r + l) >> 1;
    if(begin <= mid)
        updata(sign,begin,end,lson);
    if(mid < end)
        updata(sign,begin,end,rson);
    uppush(l,r,cnt);
}
int main()
{
    int N,M;
    while(~scanf("%d%d",&N,&M))
    {
        build(1,N,root);
        for(int i = 0;i < M;i++)
        {
           int instruct,begin,num;
           scanf("%d",&instruct);
           if(instruct == 1)
           {
                scanf("%d",&num);
                int ans = query(num,1,N,root);
                printf("%d\n",ans);
                if(ans)updata(1,ans,ans + num - 1,1,N,root);
           }
           else
           {
                scanf("%d%d",&begin,&num);
                updata(0,begin,begin + num - 1,1,N,root);
           }
        }
    }
}
