#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define MAXN 50005
#define INF 0x3f3f3f3f
int minn[MAXN << 2],ql,qr;
void updata(int l,int r,int cnt,int val)
{
    if(qr <= l && r <= qr)
    {
        minn[cnt] = min(val,minn[cnt]);
        return;
    }
    int mid = l + r >> 1;
    if(qr <= mid)
        updata(l,mid,cnt << 1,val);
    if(qr > mid)
        updata(mid + 1,r,cnt << 1 | 1,val);
    minn[cnt] = min(minn[cnt << 1],minn[cnt << 1 | 1]);
}
int query(int l,int r,int cnt)
{
    if(ql <= l && r <= qr)
        return minn[cnt];
    int mid = l + r >> 1;
    int ans = INF;
    if(ql <= mid)
        ans = min(ans,query(l,mid,cnt << 1));
    if(mid < qr)
        ans = min(ans,query(mid + 1,r,cnt << 1 | 1));
    return ans;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        int l = 1;
        memset(minn,0x3f,sizeof(minn));
        ql = qr = 1;
        updata(1,n,1,0);;
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d",&ql,&qr);
            if(ql > l)continue;
            else l = max(l,qr);
            int val = query(1,n,1);
            updata(1,n,1,val + 1);
        }
        ql = qr = n;
        int ans = query(1,n,1);
        printf("%d\n",ans);
    }
}
