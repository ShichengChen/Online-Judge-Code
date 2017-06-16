#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long LL;
#define MAXN 50005
#define lcnt cnt << 1
#define rcnt cnt << 1 | 1
LL maxn[MAXN << 2],num[MAXN << 2];
void build(int l,int r,int cnt)
{
    num[cnt] = maxn[cnt] = 1;
    if(l == r)return;
    int mid = l + r >> 1;
    build(l,mid,lcnt) , build(mid + 1,r,rcnt);
    num[cnt] = num[lcnt] + num[rcnt];
}
LL query(LL ql,LL qr,int l,int r,int cnt)
{
    if(l == r)return qr - ql + 1;
    if(qr - ql + 1 == num[cnt])return maxn[cnt];
    int mid = l + r >> 1;
    LL cur = num[lcnt];
    if(qr <= cur)
        return query(ql,qr,l,mid,lcnt);
    else if(cur < ql)
        return query(ql - cur,qr - cur,mid + 1,r,rcnt);
    else
        return max(query(ql,cur,l,mid,lcnt),query(1,qr - cur,mid + 1,r,rcnt));
}
void updata(LL ql,LL qr,int l,int r,int cnt)
{
    if(l == r)
    {
        maxn[cnt] = num[cnt]  += qr - ql + 1;
        return;
    }
    int mid = l + r >> 1;
    LL cur = num[lcnt];
    if(qr <= cur)updata(ql,qr,l,mid,lcnt);
    else if(cur < ql)updata(ql - cur,qr - cur,mid + 1,r,rcnt);
    else
        updata(ql,cur,l,mid,lcnt),updata(1,qr - cur,mid + 1,r,rcnt);
    maxn[cnt] = max(maxn[lcnt],maxn[rcnt]);
    num[cnt] = num[lcnt] + num[rcnt];
}
int main()
{
    int _,kcas = 1,m,n;
    LL ql,qr;
    char op[3];
    scanf("%d", &_);
    while(_--)
    {
         scanf("%d%d",&n,&m);
         build(1,n,1);
         printf("Case #%d:\n",kcas++);
         while(m--)
         {
            scanf("%s%I64d%I64d",op,&ql,&qr);
            if(op[0] == 'D')
                updata(ql,qr,1,n,1);
            else
                printf("%I64d\n",query(ql,qr,1,n,1));
         }
    }
}
