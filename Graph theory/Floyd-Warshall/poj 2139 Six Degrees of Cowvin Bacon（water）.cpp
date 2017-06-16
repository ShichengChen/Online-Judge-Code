#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 310
int w[MAXN][MAXN],id[MAXN];
int floyd(int n)
{
    int ans = INF;
    for(int k = 1;k <= n;k++)
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                    w[i][j] = min(w[i][j],w[i][k] + w[k][j]);
    for(int i = 1;i <= n;i++)
    {
        int minn = 0;
        for(int j = 1;j <= n;j++)
            minn += w[i][j];
        ans = min(ans,minn);
    }
    return ans * 100 / (n - 1);
}
int main()
{
    int n,m,t;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        memset(w,0x3f,sizeof(w));
        while(m--)
        {
            scanf("%d",&t);
            for(int i = 1;i <= t;i++)
                scanf("%d",&id[i]);
            for(int i = 1;i <= t;i++)
                for(int j = 1;j <= t;j++)
                    if(i == j)w[id[j]][id[i]] = 0;
                    else w[id[j]][id[i]] = w[id[i]][id[j]] = 1;
        }
        int ans = floyd(n);
        printf("%d\n",ans);
    }
}
