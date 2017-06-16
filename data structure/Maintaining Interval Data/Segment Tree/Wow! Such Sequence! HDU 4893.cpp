#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define N 110001
#define FN 92
const int root = 1;
long long farray[FN],ans;
bool flag[N * 4];
long long find_f(long long i)
{
    if(i <= 1)return 1;
    int ind = lower_bound(farray,farray + FN,i) - farray;
    if(farray[ind] == i || i - farray[ind - 1] > farray[ind] - i)return farray[ind];
    return farray[ind - 1];
}
struct Node
{
    long long sum,fsum;
    int l, r;
} node[N * 4];
void pushdown(int cnt)
{
        if(flag[cnt])
        {
            node[cnt << 1].sum = node[cnt << 1].fsum;
            node[cnt << 1 | 1].sum = node[cnt << 1 | 1].fsum;
            flag[cnt << 1] = flag[cnt << 1 | 1] = flag[cnt];
            flag[cnt] = 0;
        }
}
void pushup(int cnt)
{
        node[cnt].sum = node[cnt << 1].sum + node[cnt << 1 | 1].sum;
        node[cnt].fsum = node[cnt << 1].fsum + node[cnt << 1 | 1].fsum;
}
void build(int l,int r,int cnt)
{
        node[cnt].l = l;  node[cnt].r = r;
        if ( l == r )
        {
            node[cnt].fsum = 1;
            node[cnt].sum = 0;
            return ;
        }
        int mid = ( l + r ) >> 1;
        build(l,mid,cnt << 1);
        build(mid + 1,r, cnt << 1 | 1);
        pushup(cnt);
}
void updata(int cnt,int point,int val)
{
        if ( node[cnt].l == point && node[cnt].r == point)
        {
            node[cnt].sum += (long long)val;
            node[cnt].fsum = node[cnt].sum;
            node[cnt].fsum += (find_f(node[cnt].sum) - node[cnt].sum);
            return;
        }
        pushdown(cnt);
        int mid = (node[cnt].l + node[cnt].r) >> 1;
        if (point <= mid)
            updata(cnt << 1,point,val);
        else
            updata(cnt << 1 | 1,point,val);
        pushup(cnt);
}
void updataline(int l,int r,int cnt)
{
        if ( node[cnt].l >= l && node[cnt].r <= r )
        {
            flag[cnt] = 1;
            node[cnt].sum = node[cnt].fsum;
            return;
        }
        pushdown(cnt);
        int mid = ( node[cnt].l + node[cnt].r ) >> 1;
        if ( r <= mid )
            updataline(l,r,cnt << 1);
        else if ( l >= mid + 1 )
            updataline(l,r,cnt << 1 | 1);
        else
        {
            updataline(l,mid,cnt << 1);
            updataline(mid + 1,r,cnt << 1 | 1);
        }
        pushup(cnt);
}
void query(int l, int r,int cnt)
{
        if ( l <= node[cnt].l && node[cnt].r <= r )
        {
            ans += node[cnt].sum;
            return;
        }
        pushdown(cnt);
        int mid = ( node[cnt].l + node[cnt].r ) >> 1;
        if ( r <= mid )
            query(l,r,cnt << 1);
        if ( l >= mid + 1 )
            query(l,r,cnt << 1 | 1);
        else
        {
            query(l,r,cnt << 1);
            query(l,r,cnt << 1 | 1);
        }
}
int main()
{
    farray[0] = 1;
    farray[1] = 1;
    for ( int i = 2; i < 92; i++ )
        farray[i] = farray[i - 1] + farray[i - 2];
    int n,m;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        memset(flag,0,sizeof(flag));
        build(1,n,root);
        for(int i = 0;i < m;i++)
        {
            int q,num,point,right,left;
            scanf("%d",&q);
            if(q == 1)
            {
                scanf("%d%d",&point,&num);
                updata(root,point,num);
            }
            else if(q == 2)
            {
                ans = 0;
                scanf("%d%d",&left,&right);
                query(left,right,root);
                printf("%I64d\n",ans);
            }
            else if(q == 3)
            {
                scanf("%d%d",&left,&right);
                updataline(left,right,root);
            }
        }
    }
    return 0;
}
