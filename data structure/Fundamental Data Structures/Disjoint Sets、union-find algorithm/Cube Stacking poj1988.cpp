#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX 33000
int fa[MAX],son[MAX],dis[MAX];
int findfa(int i)
{
    if(i == fa[i])return i;
    int ancestor = findfa(fa[i]);
    dis[i] += dis[fa[i]];
    fa[i] = ancestor;
    return ancestor;
}
void Union(int x,int y)
{
    int fx = findfa(x),fy = findfa(y);
    dis[fx] = son[fy] + 1;
    son[fy] += (son[fx] + 1);
    fa[fx] = fy;
}
int main()
{
    int n,x,y;
    char ch[2];
    memset(dis,0,sizeof(dis));
    memset(son,0,sizeof(son));
    for(int i = 1;i <= MAX;i++)fa[i] = i;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s ",ch);
        if(ch[0]=='M')
        {
            scanf("%d%d",&x,&y);
            Union(x,y);
        }
        else if(ch[0]=='C')
        {
            scanf("%d",&x);
            findfa(x);
            printf("%d\n",dis[x]);
        }
    }
}
