#include<cstring>
#include<cstdio>
#define MAXN 20
bool map[MAXN][MAXN],cur[MAXN][MAXN],ans[MAXN][MAXN];
int dy[] = {0,-1,0,0};
int dx[] = {1,0,-1,0};
int find(int n,int m)
{
    int c = map[m][n];
    for(int i = 0;i < 4;i++)
        c += cur[m + dy[i]][n + dx[i]];
    return c & 1;
}
int solve(int n,int m,int c)
{
    for(int i = 2;i <= m;i++)
        for(int j = 1;j <= n;j++)
            if(find(j,i - 1))
                c += (cur[i][j] = 1);
    for(int i = 1;i <= n;i++)
        if(find(i,m))return n * m + 1;
    return c;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&m,&n) != EOF)
    {
        for(int i = 1;i <= m;i++)
            for(int j = 1;j <= n;j++)
                scanf("%d",&map[i][j]);
        int minn = m * n + 1;
        for(int i = 0;i < (1 << n);i++)
        {
            memset(cur,0,sizeof(cur));
            int c = 0;
            for(int j = 0;j < n;j++)
            {
                cur[1][n - j] = i >> j & 1;
                c += cur[1][n - j];
            }
            int num = solve(n,m,c);
            if(num < minn)
            {
                minn = num;
                memcpy(ans,cur,sizeof(cur));
            }
        }
        if(minn == m * n  + 1)puts("IMPOSSIBLE");
        else for(int i = 1;i <= m;i++)
                for(int j = 1;j <= n;j++)
                printf("%d%c",ans[i][j],j == n ? '\n' : ' ');
    }
}
