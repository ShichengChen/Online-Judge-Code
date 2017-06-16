#include<iostream>
using namespace std;
struct IntervalTree2D
{
    #define MAXN (501 << 2)
    #define INF (1 << 30)
    #define root 1
    int Max[MAXN][MAXN] , Min[MAXN][MAXN];
    bool isleaf;
    int maxn,minn,n,m,val,x1,y1,x2,y2,x,y,o;
    void query2D(int l,int r,int cnt)
    {
        if(x1 <= l && r <= x2)
        {
            o = cnt;
            query1D(1,m,root);
            return;
        }
        int mid = l + r >> 1;
        if(x1 <= mid)query2D(l,mid,cnt << 1);
        if(mid + 1 <= x2)query2D(mid + 1,r,cnt << 1 | 1);
    }
    void query1D(int l,int r,int cnt)
    {
        if(y1 <= l && r <= y2)
        {
            maxn = max(maxn,Max[o][cnt]);
            minn = min(minn,Min[o][cnt]);
            return;
        }
        int mid = l + r >> 1;
        if(y1 <= mid)query1D(l,mid,cnt << 1);
        if(mid + 1 <= y2)query1D(mid + 1,r,cnt << 1 | 1);
    }
    void modify2D(int l,int r,int cnt)
    {
        if(l == r)
        {
            isleaf = 1;
            o = cnt;
            modify1D(1,m,root);
            return;
        }
        int mid = l + r >> 1;
        if(x <= mid)modify2D(l,mid,cnt << 1);
        else modify2D(mid + 1,r,cnt << 1 | 1);
        o = cnt;
        isleaf = 0;
        modify1D(1,m,root);
    }
    void modify1D(int l,int r,int cnt)
    {
        if(l == r)
        {
            if(isleaf)
                Max[o][cnt] = Min[o][cnt] = val;
            else
            {
                Max[o][cnt] = max(Max[o << 1 | 1][cnt],Max[o << 1][cnt]);
                Min[o][cnt] = min(Min[o << 1 | 1][cnt],Min[o << 1][cnt]);
            }
            return;
        }
        int mid = l + r >> 1;
        if(y <= mid)modify1D(l,mid,cnt << 1);
        else modify1D(mid + 1,r,cnt << 1 | 1);
        Max[o][cnt] = max(Max[o][cnt << 1],Max[o][cnt << 1 | 1]);
        Min[o][cnt] = min(Min[o][cnt << 1],Min[o][cnt << 1 | 1]);
    }
    void modify()
    {
        modify2D(1,n,root);
    }
    void query()
    {
        maxn = -INF;
        minn = INF;
        query2D(1,n,root);
    }
};
IntervalTree2D tree;
#include<cstdio>
int main()
{
    int m,n,num;
    char op[2];
    while(scanf("%d%d",&n,&m) != EOF)
    {
        tree.n = n , tree.m = m;
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++)
            {
                scanf("%d",&tree.val);
                tree.x = i , tree.y = j;
                tree.modify();
            }
        scanf("%d",&num);
        while(num--)
        {
            scanf("%s",op);
            if(op[0] == 'q')
            {
                scanf("%d%d%d%d",&tree.x1,&tree.y1,&tree.x2,&tree.y2);
                tree.query();
                printf("%d %d\n",tree.maxn,tree.minn);
            }
            else
            {
                scanf("%d%d%d",&tree.x,&tree.y,&tree.val);
                tree.modify();
            }
        }
    }
}
