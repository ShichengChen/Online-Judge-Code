#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define MAX 1200
struct Point
{
    int x,y,feet;
    bool peo_fir;
    Point(int xx,int yy,bool pe,int fe)
    {
        x =xx;y =yy;
        peo_fir = pe;
        feet = fe;
    }
};
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}},cnt;
char map[MAX][MAX];
bool vis[MAX][MAX];
queue<Point>que;
bool check(int x,int y,int n,int m)
{
    if(y < n && y >= 0 && x < m && x >= 0)return true;
    return false;
}
int bfs(int x,int y,int n,int m)
{
    if(x == 0 || y == 0 || x == m - 1 || y == n - 1)return cnt = 1;
    que.push(Point(x,y,0,0));
    vis[y][x] = 1;
    while(!que.empty())
    {
        Point po = que.front(); que.pop();
        for(int j = 0;j < 4;j++)
        {
             int x = po.x + dir[j][0], y = po.y + dir[j][1];
             if(check(x,y,n,m) && !vis[y][x] && map[y][x] == '.')
            {
                    if(po.peo_fir == 0 && (x == 0 || x == m - 1 || y == 0 || y == n - 1))
                        return cnt = po.feet + 2;
                    vis[y][x] = 1;
                    que.push(Point(x,y,po.peo_fir,po.feet + 1));
            }
        }
    }
    return -1;
}
int main()
{
     int _,n,m;
     scanf("%d",&_);
     while (_--)
     {
            while(!que.empty())que.pop();
            memset(vis,0,sizeof(vis));
            scanf("%d%d",&n,&m);
            for (int i = 0; i < n; i++)
                scanf("%s",map[i]);
            int jx,jy;
            for(int y = 0;y < n;y++)
                for(int x = 0;x < m;x++)
                    if(map[y][x] == 'J')
                    {
                        jy = y, jx = x;
                    }
                    else if(map[y][x] == 'F')
                    {
                        que.push(Point(x,y,1,0));
                        vis[y][x] = 1;
                    }
            if(bfs(jx,jy,n,m) == -1)puts("IMPOSSIBLE");
            else printf("%d\n",cnt);
     }
}
