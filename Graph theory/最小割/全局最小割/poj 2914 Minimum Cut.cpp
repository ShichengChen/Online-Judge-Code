#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 510
#define INF 0x3f3f3f3f
int w[MAXN][MAXN],dis[MAXN],shift[MAXN],n,m;
bool inset[MAXN];
int stoer_wagner()
{
    for(int i = 0;i < n;i++)shift[i] = i;
    int ans = INF;
    while(n > 1)
    {
        memset(dis,0,sizeof(dis));
        memset(inset,false,sizeof(inset));
        int pre = 0;
        for(int i = 1;i < n;i++)
        {
            int k = -1;
            for(int j = 1;j < n;j++)
            {
                if(!inset[shift[j]])
                {
                    dis[shift[j]] += w[shift[pre]][shift[j]];
                    if(k == -1 || dis[shift[k]] < dis[shift[j]])
                        k = j;
                }
            }
            inset[shift[k]] = true;
            if(i == n - 1)
            {
                ans = min(ans,dis[shift[k]]);
                if(!ans)return 0;
                for(int j = 0;j < n;j++)
                {
                    w[shift[j]][shift[pre]] += w[shift[k]][shift[j]];
                    w[shift[pre]][shift[j]] += w[shift[k]][shift[j]];
                }
                shift[k] = shift[--n];
            }
            pre = k;
        }
    }
    return ans;
}
int main()
{
    while(scanf("%d%d",&n,&m) != EOF)
    {
        memset(w,0,sizeof(w));
        for(int i = 0;i < m;i++)
        {
            int u,v,cur;
            scanf("%d%d%d",&u,&v,&cur);
            w[u][v] += cur;
            w[v][u] += cur;
        }
        int ans = stoer_wagner();
        printf("%d\n",ans);
    }
}
