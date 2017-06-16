#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 11000
const int root = 1;
int renew[MAXN * 2],ans;
bool mark[MAXN];
struct POST
{
        int poster,id;
        bool operator < (const POST & pos)const{
            return poster < pos.poster;
        }
}post[MAXN * 2] ;
struct Node
{
    int l,r,kind;
}node[MAXN * 16];
void pushdown(int cnt)
{
    if(node[cnt].kind != -1)
    {
        node[cnt << 1].kind = node[cnt << 1 | 1].kind = node[cnt].kind;
        node[cnt].kind = -1;
    }
}
void build(int l,int r,int cnt)
{
    node[cnt].l =l, node[cnt].r = r;
    node[cnt].kind = -1;
    if(l == r)return;
    int mid = (l + r) >> 1;
    build(l,mid,cnt << 1);
    build(mid + 1,r,cnt << 1 | 1);
}
void updata(int l,int r,int cnt,int val)
{
    if(l <= node[cnt].l && node[cnt].r <= r){
        node[cnt].kind = val;
        return;
    }
    pushdown(cnt);
    int mid = (node[cnt].l + node[cnt].r) >> 1;
    if(r <= mid)updata(l,r,cnt << 1,val);
    else if(l >= mid + 1)updata(l,r,cnt << 1| 1,val);
    else{
        updata(l,mid,cnt << 1,val);
        updata(mid + 1,r,cnt << 1 | 1,val);
    }
}
void query(int l,int r,int cnt)
{
    if(l == r)
    {
        if(node[cnt].kind != -1 && !mark[node[cnt].kind])
        {
            ans++;
            mark[node[cnt].kind] = true;
        }
        return;
    }
    pushdown(cnt);
    int mid = (node[cnt].l + node[cnt].r) >> 1;
    query(l,mid,cnt << 1);
    query(mid + 1,r,cnt << 1 | 1);
}
int main()
{
    int _,n;
    scanf("%d",&_);
    while(_--)
    {
        memset(mark,0,sizeof(mark));
        ans = 0;
        scanf("%d",&n);
        for(int i = 0;i < n;i++){
            scanf("%d%d",&post[i << 1].poster,&post[i << 1 | 1].poster);
            post[i << 1].id = i << 1 , post[i << 1 | 1].id = i << 1 | 1;
        }
        build(1,MAXN * 4,root);
        sort(post,post + 2 * n);
        int cnt = 1;
        renew[post[0].id] = cnt;
        for(int i = 1;i < n * 2;i++)
            if(post[i].poster == post[i - 1].poster)
                renew[post[i].id] = cnt;
            else if(post[i].poster == post[i - 1].poster + 1)
                renew[post[i].id] = ++cnt;
            else
                renew[post[i].id] = (cnt += 2);
        for(int i = 0;i < n;i++)updata(renew[i << 1],renew[i << 1 | 1],root,i);
        query(1,MAXN * 4,root);
        printf("%d\n",ans);
    }
}
