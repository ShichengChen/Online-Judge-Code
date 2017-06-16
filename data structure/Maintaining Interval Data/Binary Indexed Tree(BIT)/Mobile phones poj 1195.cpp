#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define N 1100
int partsum[N][N];
int lowbit(int i)
{
    return i & (-i);
}
int getsum(int x1,int y1)
{
    int total = 0;
    for(int x = x1;x;x -= lowbit(x))
        for(int y = y1;y;y -= lowbit(y))
                total += partsum[x][y];
    return total;
}
void modify(int x1,int y1,int key,int maxn)
{
    for(int x = x1;x <= maxn;x += lowbit(x))
        for(int y = y1;y <= maxn;y += lowbit(y))
                partsum[x][y] += key;
}
int main()
{
    int Case,n;
    while(scanf("%d",&Case) != EOF)
    {
        if(Case == 0)
        {
            scanf("%d",&n);
            memset(partsum,0,sizeof(partsum));
        }
        else if(Case == 2)
        {
                 int x1,x2,y1,y2;
                 scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                 int ans = getsum(x2 + 1,y2 + 1) + getsum(x1,y1) - getsum(x1,y2 + 1) - getsum(x2 + 1,y1);
                 printf("%d\n",ans);
        }
        else if(Case == 1)
        {
               int x,y,num;
               scanf("%d%d%d",&x,&y,&num);
               modify(x + 1,y + 1,num,n);
        }
        else break;
    }
}
