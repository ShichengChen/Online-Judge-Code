/*
f[0] may not be 0
such as
f1 < f0 < f2 < f3 < f4
lead to overflow
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
#define MAX 200
#define N 15
char matrix[MAX];
int f[N];
queue<int>que;
struct EGDE
{
    int v,next;
    bool w;
}edge[MAX];
int first[N],indu[N];
int number,cnt;
void init()
{
    cnt = number = 0;
    while(!que.empty())que.pop();
    memset(first,-1,sizeof(first));
    memset(indu,0,sizeof(indu));
}
void insert(int x,int y,bool w)
{
    edge[number].next = first[x];
    edge[number].v = y;
    edge[number].w = w;
    first[x] = number++;
}
void BFS(int n)
{
    cnt = 0;
    for(int  i = 0;i <= n;i++)if(!indu[i])
    {
        que.push(i);
        f[i] = cnt;
    }
    while(!que.empty())
    {
        int u = que.front();  que.pop();
        for(int i = first[u];i != -1;i = edge[i].next)
        {
            int v = edge[i].v;
            indu[v]--;
            if(indu[v] == 0)
            {
                if(edge[i].w == 0)f[v] = f[u];
                else f[v] = ++cnt;
                que.push(v);
            }
        }
    }
}
int main()
{
    int _,n;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%s",&n,matrix);
        init();
        for(int i = 0;i < n;i++)
            for(int j = i + 1;j <= n;j++)
            {
                if(matrix[cnt] == '+')
                {
                    insert(i,j,1);
                    indu[j]++;
                }
                else if(matrix[cnt] == '-')
                {
                    insert(j,i,1);
                    indu[i]++;
                }
                else if(matrix[cnt] == '0')
                {
                    insert(i,j,0);
                    indu[j]++;
                }
                cnt ++;
            }
        BFS(n);
        for(int i = 1;i <= n;i++)
        {
            if(i != n)printf("%d ",f[i] - f[i - 1]);
            else printf("%d\n",f[i] - f[i - 1]);
        }
    }
}
