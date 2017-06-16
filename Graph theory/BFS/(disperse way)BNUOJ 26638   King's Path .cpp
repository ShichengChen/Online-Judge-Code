#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
typedef pair<int,int> road;
typedef pair<road,int> step;
int dir[8][2] = {{0,1},{1,0},{1,1},{-1,-1},{1,-1},{-1,1},{-1,0},{0,-1}};
set<road>gather;
int bfs(int x1,int y1,int x2,int y2)
{
    queue<step>que;
    que.push(step(road(x1,y1),0));
    while(!que.empty())
    {
        int x = que.front().first.first,y = que.front().first.second;
        int st = que.front().second;
        if(x == x2 && y == y2)return st;
        que.pop();
        for(int i = 0;i < 8;i++)
        {
            int xx = x + dir[i][0],yy = y + dir[i][1];
            if(gather.find(road(xx,yy)) == gather.end())continue;
            gather.erase(road(xx,yy));
            que.push(step(road(xx,yy),st + 1));
        }
    }
    return -1;
}
int main()
{
    int x1,y1,x2,y2,n;
    while(scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&n) != EOF)
    {
        while(n--)
        {
            int a,b,r;
            scanf("%d%d%d",&r,&a,&b);
            for(int i = a;i <=b;i++)
                gather.insert(road(r,i));
        }
        printf("%d\n",bfs(x1,y1,x2,y2));
    }

}
