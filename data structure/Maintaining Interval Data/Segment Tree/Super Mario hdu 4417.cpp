#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define MAXN 100002
const int root = 1;
vector<int>vec[MAXN << 2];
int h[MAXN],ql,qr;
void build(int l,int r,int cnt)
{
    vec[cnt].clear();
    for(int i = l;i <= r;i++)
        vec[cnt].push_back(h[i]);
    sort(vec[cnt].begin(),vec[cnt].end());
    int mid = l + r >> 1;
    if(l == r)return;
    build(l,mid,cnt << 1);
    build(mid + 1,r,cnt << 1 | 1);
}
int query(int l,int r,int cnt,int key)
{
    if(ql <= l && r <= qr)
        return upper_bound(vec[cnt].begin(),vec[cnt].end(),key) - vec[cnt].begin();
    int mid = l + r >> 1 , ret = 0;
    if(ql <= mid)ret = query(l,mid,cnt << 1,key);
    if(qr >= mid + 1)ret += query(mid + 1,r,cnt << 1 | 1,key);
    return ret;
}
int main()
{
    int _,n,m,val;
    scanf("%d",&_);
    for(int kcase = 1;kcase <= _;kcase++)
    {
        printf("Case %d:\n",kcase);
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++)
            scanf("%d",&h[i]);
        build(1,n,root);
        for(int i = 1;i <= m;i++)
        {
            scanf("%d%d%d",&ql,&qr,&val);
            ql++ , qr++;
            int ans = query(1,n,root,val);
            printf("%d\n",ans);
        }
    }
}
