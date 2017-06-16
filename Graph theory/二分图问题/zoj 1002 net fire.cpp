#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
#define MAX 6
#define MAXP 20
#define sss system("pause");
char chess[MAX][MAX];
int match[MAXP];
bool vis[MAXP],map[MAXP][MAXP];
int begin,end,success = 1,ans;
bool dfs(int v)
{
    for(int u = 1;u <= begin;u++)if(map[u][v] && !vis[u])
    {
        vis[u] = 1;
        int temp = match[u];
        match[u] = v;
        if(temp == -1 || dfs(temp))
            return true;
        match[u] = temp;
    }
    return false;
}
int main()
{
    int n;
    while(scanf("%d",&n) && n)
    {
        begin = end = ans = 0;
        memset(map,0,sizeof(map));
        memset(match,-1,sizeof(match));
        for(int i = 1;i <= n;i++)
        {
            scanf("%s",chess[i] + 1);
            begin++;
            for(int j = 1;j <= n;j++)
            {
                if(chess[i][j] != '.')
                    while(j <= n)
                    {
                        if(j == 1)success = 0;
                        if(chess[i][j] == 'X')j++;
                        else
                        {
                            if(j <= n && success)begin++;
                            break;
                        }
                        if(j > n && !success)begin--;
                    }
                success = 1;
                if(j > n)continue;
                if(chess[i][j] == '.')chess[i][j] = (char)(begin + '0');
            }
        }
        for(int i = 1;i <= n;i++)
        {
            end++;
            for(int j = 1;j <= n;j++)
            {
                if(chess[j][i] == 'X')
                    while(j <= n)
                    {
                        if(j == 1)success = 0;
                        if(chess[j][i] == 'X')j++;
                        else
                        {
                            if(j <= n && success)end++;
                            break;
                        }
                        if(j > n && !success)end--;
                    }
                if(j > n)continue;
                if(chess[j][i] != 'X')
                   map[chess[j][i] - '0'][end] = 1;
                success = 1;
            }
        }
        for(int v = 1;v <= end;v++)
        {
            memset(vis,0,sizeof(vis));
            ans += dfs(v);
        }
        printf("%d\n",ans);
    }
    return 0;
}
