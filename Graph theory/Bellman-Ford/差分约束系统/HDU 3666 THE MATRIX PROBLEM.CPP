#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 810
double d[MAXN],V[MAXN * MAXN],w[MAXN][MAXN];
int cnt[MAXN],head[MAXN],next[MAXN * MAXN],number;
bool inque[MAXN];
void insert(int u,int v,double val)
{
    next[number] = head[u];
    V[number] = v;
    w[u][v] = val;
    head[u] = number++;
}
bool bellman(int n,int m)
{
    memset(inque,false,sizeof(inque));
    memset(cnt,0,sizeof(cnt));
    queue<int>que;
    d[0] = 0;inque[0] = 1;
    que.push(0);
    for(int i = 1;i < n + m;i++)
        d[i] = INF,que.push(i);
    while(!que.empty())
    {
        int u = que.front();que.pop();
        inque[u] = 0;
        for(int i = head[u];i != -1;i = next[i])
        {
            int v = V[i];
            if(d[v] > d[u] + w[u][v])
            {
                d[v] = d[u] + w[u][v];
                if(!inque[v])
                {
                    inque[v] = 1;
                    que.push(v);
                    if(++cnt[v] > sqrt(double(n + m + 1)))return false;
                }
            }
        }
    }
    return true;
}
int main()
{
    int n,m,val,l,r;
    while(scanf("%d%d%d%d",&n,&m,&l,&r) != EOF)
    {
        memset(head,-1,sizeof(head));
        number = 0;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
            {
                scanf("%d",&val);
                insert(i,j + n,-log((double)l / val));
                insert(j + n,i,log((double)r / val));
            }
        if(bellman(n,m))puts("YES");
        else puts("NO");
    }
}
