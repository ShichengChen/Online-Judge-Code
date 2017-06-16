#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define MAXN 105
#define INF 0x3f3f3f3f
int map[MAXN][MAXN],dp[MAXN][MAXN][MAXN];
int N;
int dfs(int x,int y,int x1)
{
    int y1 = y + x - x1;
    if(dp[x][y][x1] >= 0)return dp[x][y][x1];
    if(x == x1 || x1 > N || x > N || y > N || y1 > N || y1 == 0)return 0;
    int d = abs(map[x][y] - map[x1][y1]);
    dp[x][y][x1] = max(max(dfs(x + 1,y,x1),dfs(x + 1,y,x1 + 1)),
                       max(dfs(x,y + 1,x1),dfs(x,y + 1,x1 + 1)));
    return dp[x][y][x1] = dp[x][y][x1] + d;
}
int main()
{
    while(scanf("%d",&N) != EOF)
    {
        for(int i = 1;i <= N;i++)
            for(int j = 1;j <= N;j++)
                scanf("%d",&map[i][j]);
        memset(dp,-1,sizeof(dp));
        printf("%d\n",dfs(2,1,1));
    }
}
