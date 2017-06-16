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
    for(int y = y1;y;y -= lowbit(y))
        for(int x = x1;x;x -= lowbit(x))
                total += partsum[x][y];
    return total;
}
void modify(int x1,int y1,int key,int maxn)
{
    for(int y = y1;y <= maxn;y += lowbit(y))
        for(int x = x1;x <= maxn;x += lowbit(x))
            partsum[x][y] ^= key;
}
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        int n,oper;     char cas[2];
        scanf("%d%d",&n,&oper);
        memset(partsum,0,sizeof(partsum));
        for(int i = 0;i < oper;i++)
        {
            scanf("%s",cas);
            if(cas[0] == 'C')
            {
                int x1,y1,x2,y2;
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                modify(x1,y1,1,n);
                modify(x2 + 1,y2 + 1,1,n);
                modify(x1,y2 + 1,1,n);
                modify(x2 + 1,y1,1,n);
            }
            else
            {
                int x,y;
                scanf("%d%d",&x,&y);
                printf("%d\n",(getsum(x,y) & 1));
            }
        }
        printf("\n");
    }
}
