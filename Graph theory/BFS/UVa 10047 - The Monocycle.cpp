#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define MAXN 30
struct Status
{
    int x,y,direc,color,time;
    Status(int x,int y,int direc,int color,int time)
    : x(x) , y(y) , direc(direc) , color(color) , time(time){}
};
int dir[4][2] = {{0,-1},{1,0},{0,1},{-1,0}};
char map[MAXN][MAXN];
int vis[MAXN][MAXN][4][5],row,column;
queue<Status>que;
bool check(int x,int y)
{
    if(x > 0 && x <= column && y <= row && y > 0 && map[y][x] != '#' )return true;
    return false;
}
int bfs(int aimx,int aimy)
{
    while(!que.empty())
    {
        Status cur = que.front();  que.pop();
        int curx = cur.x + dir[cur.direc][0] , cury = cur.y + dir[cur.direc][1];
        if(check(curx,cury) && vis[curx][cury][cur.direc][(cur.color + 1) % 5] == 0)
        {
            if(map[cury][curx] == 'T' && (cur.color + 1) % 5 == 0)return cur.time + 1;
            que.push(Status(curx,cury,cur.direc,(cur.color + 1) % 5,cur.time + 1));
            vis[curx][cury][cur.direc][(cur.color + 1) % 5] = true;
        }
        if(vis[cur.x][cur.y][(cur.direc + 5) % 4][cur.color] == 0)
        {
            que.push(Status(cur.x,cur.y,(cur.direc + 5) % 4,cur.color,cur.time + 1));
            vis[cur.x][cur.y][(cur.direc + 5) % 4][cur.color] = true;
        }
        if(vis[cur.x][cur.y][(cur.direc + 3) % 4][cur.color] == 0)
        {
            que.push(Status(cur.x,cur.y,(cur.direc + 3) % 4,cur.color,cur.time + 1));
            vis[cur.x][cur.y][(cur.direc + 3) % 4][cur.color] = true;
        }
    }
    return -1;
}
int main()
{
    int aimx,aimy,cas = 1;
    while(scanf("%d%d",&row,&column) && (row | column))
    {
        for(int i = 1;i <= row;i++)
            scanf("%s",map[i] + 1);
        while(!que.empty())que.pop();
        memset(vis,0,sizeof(vis));
        for(int y = 1;y <= row;y++)
            for(int x = 1;x <= column;x++)
                if(map[y][x] == 'S')
                {
                    que.push(Status(x,y,0,0,0));
                    vis[x][y][0][0] = 1;
                }
        int ans = bfs(aimx,aimy);
        if(cas != 1) printf("\n");
        printf("Case #%d\n", cas++);
        if(ans == -1)printf("destination not reachable\n");
        else printf("minimum time = %d sec\n", ans);
    }
}
