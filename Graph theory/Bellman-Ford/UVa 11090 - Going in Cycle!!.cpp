#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
#define MAXP 53
#define eps 1e-3
#define INF 0x3f3f3f3f
vector<int>vec[MAXP];
int cnt[MAXP],weight;
double d[MAXP],w[MAXP][MAXP];
bool inque[MAXP];
bool bellman_negative_cycle(double val,int n)
{
    memset(cnt,0,sizeof(cnt));
    memset(inque,true,sizeof(inque));
    queue<int>que;
    for(int i = 1;i <= n;i++)
    {
         que.push(i);
         d[i] = 0;
    }
    while(!que.empty())
    {
        int u = que.front() ; que.pop();
        inque[u] = false;
        for(int i = 0;i < vec[u].size();i++)
        {
            int v = vec[u][i];
            if(d[v] > d[u] + w[u][v] - val)
            {
                d[v] = d[u] + w[u][v] - val;
                if(!inque[v])
                {
                    que.push(v);
                    inque[v] = true;
                    if(++cnt[v] > n)return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    int kase,n,m,x,y,weight,_;
    for(int kase = scanf("%d",&_);kase <= _;kase++)
    {
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
            w[i][j] = INF;
        for(int i = 1;i <= n;i++)vec[i].clear();
        int ubr = 0;
        while(m--)
        {
            scanf("%d%d%d",&x,&y,&weight);
            vec[x].push_back(y);
            w[x][y] = min(w[x][y],(double)weight);
            ubr = max(ubr,weight);
        }
        printf("Case #%d: ",kase);
        if(!bellman_negative_cycle((double)ubr + 1,n))puts("No cycle found.");
        else
        {
            double L = 0,R = ubr;
            while(R - L > eps)
            {
                double mid = (R + L) / 2;
                if(bellman_negative_cycle(mid,n))R = mid;
                else L = mid;
            }
            printf("%.2lf\n",L);
        }
    }
}
