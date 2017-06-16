#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define lcnt (cnt << 1)
#define rcnt (cnt << 1 | 1)
#define MAXL 100001
#define root 1
struct Node
{
    int maxh,minh,set;
}node[MAXL << 2];
int ans,ql,qr;
void pushdown(int cnt)
{
    if(node[cnt].set > 0)
    {
        node[lcnt].set = node[rcnt].set = node[cnt].set;
        node[lcnt].maxh = node[rcnt].maxh = node[cnt].set;
        node[lcnt].minh = node[rcnt].minh = node[cnt].set;
        node[cnt].set = 0;
    }
}
void pushup(int cnt)
{
    node[cnt].maxh = max(node[rcnt].maxh,node[lcnt].maxh);
    node[cnt].minh = min(node[rcnt].minh,node[lcnt].minh);
}
void modify(int l,int r,int cnt,int heigh)
{
    if(node[cnt].minh > heigh)return;
    if(ql <= l && r <= qr)
    {
        if(node[cnt].maxh <= heigh)
        {
            ans += r - l + 1;
            node[cnt].set = node[cnt].minh = node[cnt].maxh = heigh;
            return;
        }
    }
    pushdown(cnt);
    int mid = l + r >> 1;
    if(ql <= mid)modify(l,mid,lcnt,heigh);
    if(mid + 1<= qr)modify(mid + 1,r,rcnt,heigh);
    pushup(cnt);
}
int main()
{
    int _,n,l,r,h;
    while(scanf("%d",&_) != EOF , _)
    {
        while(_--)
        {
            scanf("%d",&n);
            memset(node,0,sizeof(node));
            ans = 0;
            while(n--)
            {
                scanf("%d%d%d",&ql,&qr,&h);
                qr--;
                modify(1,MAXL,root,h);
            }
            printf("%d\n",ans);
        }
    }
}
