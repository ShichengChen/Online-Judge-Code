#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int>pii;
#define MAXN 10000
bool vis[MAXN],prime[MAXN];
void find_prime()
{
    for(int i = 2;i < MAXN;i++)if(!vis[i])
    {
        prime[i] = true;
        for(long long j = (long long)i * i;j < MAXN;j += i)
            vis[j] = true;
    }
}
int change(int a,int i,int j)
{
    if(i == 4 && j == 0)return a;
    switch (i)
    {
        case 1:
            return a / 10 * 10 + j;
        case 2:
            return a / 100 * 100 + a % 10 + j * 10;
        case 3:
            return a / 1000 * 1000 + a % 100 + j * 100;
        case 4:
            return a % 1000 + j * 1000;
    }
}
int BFS(int begin,int end)
{
    if(begin == end)return 0;
    queue<pii>que;
    que.push(pii(begin,0));
    memset(vis,0,sizeof(vis));
    vis[begin] = true;
    while(!que.empty())
    {
        pii cur = que.front(); que.pop();
        for(int i = 1;i <= 4;i++)
        {
            for(int j = 0;j <= 9;j++)
            {
                int u = cur.first;
                int v = change(u,i,j);
                //cout << u << " u  v " << v << endl;
                if(vis[v] || !prime[v])continue;
                vis[v] = true;
                if(v == end)return cur.second + 1;
                que.push(pii(v,cur.second + 1));
            }
        }
    }
}
int main()
{
    int _,a,b;
    scanf("%d",&_);
    find_prime();
    while(_--)
    {
        scanf("%d%d",&a,&b);
        int ans = BFS(a,b);
        printf("%d\n",ans);
    }
}

