#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 1010
#define INF 0x3f3f3f3f
int d[MAXN],before[MAXN],after[MAXN];
int cnt;
int dp(int cost,int basic,int sum)
{
    if(basic + sum < cost)return basic + sum;
    memset(d,-1,sizeof(d));
    d[min(cost,basic)] = basic;
    for(int i = 0;i < cnt;i++)
        for(int j = cost;j >= 0;j--)
        {
            if(cost == j && d[j] != -1)d[j] += after[i];
            else if(d[j] != -1)
            {
                d[min(j + before[i],cost)] = max(d[j] + before[i],d[min(j + before[i],cost)]);
                d[j] = max(d[j],d[j] + after[i]);
            }
        }
    return d[cost];
}
int main()
{
    int x,y,n,cost,basic,sum;
    char str[5];
    while(scanf("%d%d",&n,&cost) != EOF)
    {
            basic = cnt = sum = 0;
            for(int i = 0;i < n;i++)
            {
                if(i == 0)getchar();
                cin.getline(str,11);
                if(sscanf(str, "%d%d", &x, &y) == 1)
                    basic += x;
                else
                {
                    if(y - x <= cost)
                        basic += x;
                    else
                    {
                        before[cnt] = x;
                        sum += x;
                        after[cnt++] = y - cost;
                    }
                }
            }
            int ans = dp(cost,basic,sum);
            printf("%d\n",ans);
    }
}
