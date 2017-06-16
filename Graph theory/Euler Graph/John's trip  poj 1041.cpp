/*
pay attention to that road or  junctions
whether they are continuing
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAX 2200
#define MAXP 44
int du[MAXP],cnt,print[MAX],n;
struct Edge
{
   int u,v,num;
   bool vis;
   bool operator < (const Edge & ed)const{
    return  num < ed.num;
   }
}edge[MAX];
void init()
{
    memset(edge,0,sizeof(edge));
    memset(du,0,sizeof(du));
    cnt = 0;n = 1;
}
bool connection()
{
    for(int i = 0;i < 45;i++)
        if(du[i] % 2)return false;
    return true;
}
void Euler(int v,int n)
{
    for(int i = 0;i < n;i++)
        if(!edge[i].vis && edge[i].u == v)
        {
            edge[i].vis = 1;
            Euler(edge[i].v,n);
            print[cnt++] = edge[i].num;
        }
        else if(!edge[i].vis && edge[i].v == v)
        {
            edge[i].vis = 1;
            Euler(edge[i].u,n);
            print[cnt++] = edge[i].num;
        }
}
int main()
{
    int x,y,z;
    while(scanf("%d%d",&x,&y),x,y)
    {
            int begin = min(x,y);
            scanf("%d",&z);
            init();
            edge[0].u = x;edge[0].v = y; edge[0].num = z;
            du[x] ++;du[y]++;
            while(scanf("%d%d",&x,&y),x,y)
            {
                scanf("%d",&z);
                edge[n].u = x;  edge[n].v = y; edge[n++].num = z;
                du[x] ++;du[y]++;
            }
            if(!connection())
            {
                puts("Round trip does not exist.");
                continue;
            }
            sort(edge,edge + n);
            Euler(begin,n);
            for(int i = cnt -1;i >= 0;i--)
            {
                if(i != 0)printf("%d ",print[i]);
                else printf("%d \n",print[i]);
            }
    }
}
