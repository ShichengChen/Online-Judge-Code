#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 110
#define INF 0x3f3f3f3f
int d[MAXN][MAXN];
void floyd(int n)
{
    for(int k = 1;k <= n;k++)
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                d[i][j] = min(d[i][j],max(d[i][k],d[k][j]));
}

int main()
{
    int n,m,q,u,v,w,k = 1;
    while(scanf("%d%d%d",&n,&m,&q) && (n | m | q))
    {
        memset(d,0x3f,sizeof(d));
        for(int i = 1;i <= n;i++)d[i][i] = 0;
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            d[u][v] = d[v][u] = w;
        }
        floyd(n);
        if(k - 1)puts("");
        printf("Case #%d\n",k++);
        while(q--)
        {
            scanf("%d%d",&u,&v);
            if(d[u][v] == INF)
                printf("no path\n");
            else
                printf("%d\n",d[u][v]);
        }
    }
}
