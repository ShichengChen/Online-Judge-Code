#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX 30003
int fa[MAX],dis[MAX];
int findfa(int i)
{
    if(fa[i] < 0)return i;
    int ancestor = findfa(fa[i]);
    dis[i] += dis[fa[i]];
    fa[i] = ancestor;
    return ancestor;
}
void Union(int x,int y)
{
    int fx = findfa(x),fy = findfa(y);
    dis[fx] -= fa[fy];
    fa[fy] += fa[fx];
    fa[fx] = fy;
}
int main()
{
    int n,x,y;
    char ch[2];
    memset(dis,0,sizeof(dis));
    memset(fa,-1,sizeof(fa));
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s ",ch);
        if(ch[0]=='M')
        {
            scanf("%d%d",&x,&y);
            Union(x,y);
        }
        else
        {
            scanf("%d",&x);
            findfa(x);
            printf("%d\n",dis[x]);
        }
    }
}
