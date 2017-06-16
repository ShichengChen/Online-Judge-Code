#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define INF 0x3f3f3f3f
#define ALPH 30
int mincost[ALPH],cost[ALPH][ALPH];
bool used[ALPH];
int prim(int n)
{
    int ans = 0;
    mincost[0] = 0;
    while(1)
    {
        int v= -1;
        for(int u = 0;u < n;u++)
            if(!used[u] && (v == -1 || mincost[u] < mincost[v]))v = u;

        if(v == -1)break;
        used[v] = 1;
        ans += mincost[v];
        for(int u = 0;u < n;u++)
            mincost[u] = min(mincost[u],cost[u][v]);
    }
    return ans;
}
int main()
{
    int n,num,w;
    char alph1,alph2;
    while(scanf("%d",&n),n)
    {
        memset(used,0,sizeof(used));
        memset(mincost,0x3f,sizeof(mincost));
        memset(cost,0x3f,sizeof(cost));
        for(int i = 1;i < n;i++)
        {
            cin >> alph1 >> num;
            while(num--)
            {
                cin>> alph2 >> w;
                cost[(int)alph1 - 'A'][(int)alph2 - 'A'] = w;
                cost[(int)alph2 - 'A'][(int)alph1 - 'A'] = w;
            }
        }
        int ans = prim(n);
        printf("%d\n",ans);
    }
}
