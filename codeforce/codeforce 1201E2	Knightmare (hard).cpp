#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cstring>
#include <queue>
#include <bits/stdc++.h>
#include <cstdio>
#include <stdio.h>
using namespace std;
int const MAXN=1005;
int n,m;
int dir[]={1,2,2,1,1,-2,2,-1,-1,2,-2,1,-1,-2,-2,-1};
int u0,v0,u1,v1;
int ox,oy;
int dp[2][MAXN][MAXN];
struct Point
{
  int x,y,d;
  Point(int x,int y,int d): x(x) , y(y),d(d) {};
};
int attack(int x0,int y0,int x1,int y1){
  for(int i = 0;i < 16;i+=2){
    int nx=dir[i]+x1,ny=dir[i+1]+y1;
    if(nx==x0 && ny == y0)return 1;
  }
  return 0;
}
void predp(int aimx,int aimy,int turn){
  queue<Point>que;
  que.push(Point(aimx,aimy,0));
  dp[turn][aimx][aimy]=0;
  while(!que.empty()){
    Point cur = que.front(); que.pop();
    int x = cur.x,y = cur.y,d=cur.d;
    for(int i = 0;i < 16;i+=2)
    {
      int nx=dir[i]+x,ny=dir[i+1]+y;
      if(nx > n || nx < 0 || ny > m || ny < 0 || dp[turn][nx][ny]!=-1)continue;
      dp[turn][nx][ny]=d+1;
      que.push(Point(nx,ny,d+1));
    }
  }
}
int bfs(int x0,int y0,int x1,int y1,int turn){
  int minn=10000000;
  for(int i = 0;i < 16;i+=2){
    int nx=dir[i]+x0,ny=dir[i+1]+y0;
    if(nx > n || nx < 0 || ny > m || ny < 0)continue;
    if(dp[turn][nx][ny]==-1)puts("wrong");
    if(attack(nx,ny,x1,y1)==0)
      minn=min(minn,dp[turn][nx][ny]);
  }
  return minn+1;
}
void go(int x0,int y0,int x1,int y1,int turn0,int turn1){
  while(true){
    if(attack(x0,y0,x1,y1)){
      cout << x1 << " " << y1 << endl;
      exit(0);
    }
    int a=bfs(x0,y0,x1,y1,turn0);
    int b=bfs(x0,y0,x1,y1,turn1);
    int c=bfs(x1,y1,-100,-100,turn1);
    int d=bfs(x1,y1,-100,-100,turn0);
//  cout << "a" << a << endl;
//  cout << "b" << b << endl;
//  cout << "c" << c << endl;
//  cout << "d" << d << endl;
    if(a <= c && (a < d || (a >= d && (a - d)%2))){
      for(int i = 0;i < 16;i+=2){
        int nx=dir[i]+x0,ny=dir[i+1]+y0;
        if(nx > n || nx < 0 || ny > m || ny < 0)continue;
        if(attack(nx,ny,x1,y1)==0){
          int a1=dp[turn0][nx][ny];
//          cout << "a1:" << a1 << endl;
//          cout << "nx:" << nx << endl;
//          cout << "ny:" << ny << endl;
//          cout << "ax0:" << ax0 << endl;
//          cout << "ay0:" << ay0 << endl;
          if(a1 == 0){
            cout << nx << " " << ny << endl;
            exit(0);
          }
          if(a1 == a - 1){
            cout << nx << " " << ny << endl;
            x0=nx,y0=ny;
            cin >> x1 >> y1;
            if(x1 == -1 && y1 == -1)exit(0);
            break;
          }
        }
      }
    }
    else if(a > c && b <= c + 1 && (c + 1 - b) % 2 == 0){
      int curx=-1,cury=-1;
      for(int i = 0;i < 16;i+=2){
        int nx=dir[i]+x0,ny=dir[i+1]+y0;

        if(nx > n || nx < 0 || ny > m || ny < 0)continue;
        if(attack(nx,ny,x1,y1)==0){
          int a1=dp[turn0][nx][ny];
          int b1=dp[turn1][nx][ny];
//          cout << "a1:" << a1 << endl;
//          cout << "b1:" << b1 << endl;
          if(a1 == 0){
            cout << nx << " " << ny << endl;
            exit(0);
          }
          if(b1 <= c && (c - b1) % 2 == 0){

            curx=nx,cury=ny;
//            cout << curx << " curx cury " << cury << endl;
          }
          if(a1 == a - 1 && b1 <= c && (c - b1) % 2 == 0){
            cout << nx << " " << ny << endl;
            x0=nx,y0=ny;
            cin >> x1 >> y1;
            if(x1 == -1 && y1 == -1)exit(0);
            break;
          }
        }
        if(i == 14){
          cout << curx << " " << cury << endl;
          x0=curx,y0=cury;
          cin >> x1 >> y1;
          if(x1 == -1 && y1 == -1)exit(0);
          break;
        }
      }
    }
    else exit(0);
  }
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  cin >> u0 >> v0 >> u1 >> v1;
  if(attack(u0,v0,u1,v1)){
    cout << "WHITE" << endl;
    cout << u1 << " " << v1 << endl;
    exit(0);
  }
  memset(dp,-1,sizeof dp);
  predp(n/2,m/2,0);
  predp(n/2+1,m/2,1);
  int a=bfs(u0,v0,u1,v1,0);
  int b=bfs(u0,v0,u1,v1,1);
  int c=bfs(u1,v1,-100,-100,1);
  int d=bfs(u1,v1,-100,-100,0);
//  cout << "a" << a << endl;
//  cout << "b" << b << endl;
//  cout << "c" << c << endl;
//  cout << "d" << d << endl;
//  if(a < 0 && b < 0){
//    cout << "BLACK" << endl;
//    cin >> ox >> oy;
//    go(u1,v1,ox,oy,1,0);
//  }
  if(a <= c && (a < d || (a >= d && (a - d)%2))){
    cout << "WHITE" << endl;
    go(u0,v0,u1,v1,0,1);
  }
  if(a <= c && a >= d && (a-d)%2==0){
    cout << "BLACK" << endl;
    cin >> ox >> oy;
    go(u1,v1,ox,oy,1,0);
  }
  if(a > c && (b > c + 1 || (b <= c + 1 && (c + 1 - b)%2))){
    cout << "BLACK" << endl;
    cin >> ox >> oy;
    go(u1,v1,ox,oy,1,0);
  }
  if(a > c && b <= c + 1 && (c + 1 - b) % 2 == 0){
    cout << "WHITE" << endl;
    go(u0,v0,u1,v1,0,1);

  }


  return 0;
}
/*
 40 40
 21 18 21 22

 40 40
 19 16 20 22
 */