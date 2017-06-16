#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 1000005
int mask[MAXN << 2],ql,qr,ans;
bool flag[MAXN << 2];
void pushdown(int cnt)
{
    if(flag[cnt])
    {
        mask[cnt << 1] = mask[cnt << 1 | 1] = mask[cnt];
        flag[cnt << 1] = flag[cnt << 1 | 1] = flag[cnt];
        flag[cnt] = 0;
    }
}
void modify(int l,int r,int cnt,int num)
{
    if(ql <= l && r <= qr)
    {
        mask[cnt] = 1 << num - 1;
        flag[cnt] = 1;
        return;
    }
    pushdown(cnt);
    int mid = l + r >> 1;
    if(ql <= mid)modify(l,mid,cnt << 1,num);
    if(qr >= mid + 1)modify(mid + 1,r,cnt << 1 | 1,num);
    mask[cnt] = mask[cnt << 1] | mask[cnt << 1 | 1];
}
void query(int l,int r,int cnt)
{
    if(ql <= l && r <= qr)
    {
        ans |= mask[cnt];
        return;
    }
    pushdown(cnt);
    int mid = l + r >> 1;
    if(ql <= mid)query(l,mid,cnt << 1);
    if(qr >= mid + 1)query(mid + 1,r,cnt << 1 | 1);
}
int main()
{
    int _,n,m,num,begin;
    char op[3];
    while(scanf("%d%d",&n,&m) , m | n)
    {
        memset(flag,1,sizeof(flag));
        mask[1] = 2;
        while(m--)
        {
            scanf("%s",op);
            if(op[0] == 'P')
            {
                scanf("%d%d%d",&ql,&qr,&num);
                modify(1,n,1,num);
            }
            else
            {
                scanf("%d%d",&ql,&qr);
                ans = begin = 0;
                query(1,n,1);
                for(int i = 0;i < 30;i++)
                    if((1 << i) & ans)
                    {
                        if(begin)printf(" %d",i + 1);
                        else
                        {
                            printf("%d",i + 1);
                            begin = 1;
                        }
                    }
                puts("");
            }
        }
    }
}
