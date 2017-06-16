#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 100010
int fa[MAXN << 1],son[MAXN << 1],sum[MAXN << 1];
int findfa(int i)
{
    return fa[i] == i ? fa[i] : fa[i] = findfa(fa[i]);
}
void Union(int x,int y)
{
    int fx = findfa(x);
    int fy = findfa(y);
    if(fx == fy)return;
    fa[fx] = fy;
    son[fy] += son[fx];
    sum[fy] += sum[fx];
}
void remove_to(int x,int y)
{
    int fy = findfa(y);
    int fx = findfa(x);
    if(fy == fx)return;
    fa[x] = fy;
    son[fy]++;
    son[fx]--;
    sum[fy] += x;
    sum[fx] -= x;
}
void init(int n)
{
    for(int i = 1;i<= n;i++)
    {
        fa[i] = i + n;
        fa[i + n] = i + n;
        son[i + n] = 1;
        sum[i + n] = i;
    }
}
int main()
{
    int mark,x,y,order,n,m;
    while(scanf("%d%d" ,&n ,&m) != EOF)
    {
             init(n);
             while(m--)
             {
                    scanf("%d",&order);
                    if(order == 1)
                    {
                        scanf("%d%d",&x,&y);
                        Union(x,y);
                    }
                    else if(order == 2)
                    {
                        scanf("%d%d",&x,&y);
                        remove_to(x,y);
                    }
                    else
                    {
                        scanf("%d",&x);
                        int fa = findfa(x);
                        printf("%d %d\n",son[fa],sum[fa]);
                    }
             }
    }
}
