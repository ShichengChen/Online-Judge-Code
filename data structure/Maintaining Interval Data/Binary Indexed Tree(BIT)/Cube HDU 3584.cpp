#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define N 110
int partsum[N][N][N];
int lowbit(int i)
{
    return i & (-i);
}
int getsum(int x1,int y1,int z1)
{
    int total = 0;
    for(int x = x1;x;x -= lowbit(x))
        for(int y = y1;y;y -= lowbit(y))
            for(int z = z1;z;z -= lowbit(z))
                total += partsum[x][y][z];
    return total;
}
void modify(int x1,int y1,int z1,int key,int maxn)
{
    for(int x = x1;x <= maxn;x += lowbit(x))
        for(int y = y1;y <= maxn;y += lowbit(y))
            for(int z = z1;z <= maxn;z += lowbit(z))
                partsum[x][y][z] ^= key;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        memset(partsum,0,sizeof(partsum));
        for(int i = 0;i < m;i++)
        {
            int query;
            scanf("%d",&query);
            if(query)
            {
                     int x1,x2,y1,y2,z1,z2;
                     scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
                     modify(x1,y1,z1,1,n);
                     modify(x2 + 1,y1,z1,1,n);   modify(x1,y2 + 1,z1,1,n);    modify(x1,y1,z2 + 1,1,n);
                     modify(x2 + 1,y2 + 1,z1,1,n);   modify(x2 + 1,y1,z2 + 1,1,n);    modify(x1,y2 + 1,z2 + 1,1,n);
                     modify(x2 + 1,y2 + 1,z2 + 1,1,n);
            }
            else
            {
                   int x,y,z;
                   scanf("%d%d%d",&x,&y,&z);
                   printf("%d\n",(getsum(x,y,z) & 1));
            }
        }
    }
}
