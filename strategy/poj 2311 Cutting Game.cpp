#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 202
int SG[MAXN][MAXN];
bool vis[MAXN];
int find_SG(int w,int h)
{
    if(SG[w][h] != -1)return SG[w][h];
    memset(vis,0,sizeof(vis));
    for(int i = 2;i <= h - i;i++)vis[find_SG(w,i) ^ find_SG(w,h - i)] = 1;
    for(int i = 2;i <= w - i;i++)vis[find_SG(i,h) ^ find_SG(w - i,h)] = 1;
    int num = 0;
    while(vis[num])num++;
    return SG[h][w] = SG[w][h] = num;
}
int main()
{
    memset(SG,-1,sizeof(SG));
    int w,h;
    while(scanf("%d%d",&w,&h) != EOF)
    {
        if(!find_SG(w,h))puts("LOSE");
        else puts("WIN");
    }
}
