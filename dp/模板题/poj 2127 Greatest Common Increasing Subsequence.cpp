#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;
#define MAX 550
#define sss system("pause");
int list1[MAX],list2[MAX];
int dp[MAX][MAX],prev[MAX][MAX];
int main()
{
    int N,M;
    while(~scanf("%d",&N))
    {
        for(int i = 1;i <= N;i++)scanf("%d",&list1[i]);
        scanf("%d",&M);
        for(int i = 1;i <= M;i++)scanf("%d",&list2[i]);
        memset(dp,0,sizeof(dp));
        for(int i = 0;i <= M;i++)
            for(int j = 0;j <=N;j++)prev[i][j] = INT_MIN;
        int ans = 0,ans_x,ans_y;
        for(int i = 1;i <= M;i++)
        {
            int maxnum = 0,row = 0;
            for(int j = 1;j <= N;j++)
            {
                dp[i][j] = dp[i - 1][j];
                if(list2[i] > list1[j] && maxnum < dp[i][j])
                {
                     maxnum = dp[i][j];
                     row = j;
                }
                else if(list2[i] == list1[j])
                {
                    dp[i][j] = maxnum + 1;
                    prev[i][j] = row;
                    if(ans < dp[i][j])
                    {
                        ans = dp[i][j];
                        ans_x = i;ans_y = j;
                    }
                }

            }
        }
        printf("%d\n",ans);
        if(ans == 0)continue;
        int len = ans,y = ans_y;
        while(ans_x && ans_y  && ans && dp[ans_x][ans_y])
        {
            if(prev[ans_x][ans_y] != INT_MIN)
            {
                prev[0][--ans] = prev[ans_x][ans_y];
                int row = prev[ans_x--][ans_y];
                ans_y = row;
            }
            else
                ans_x--;
        }
        for(int i = 1;i < len;i++)
            printf("%d ",list1[prev[0][i]]);
        printf("%d",list1[y]);
        printf("\n");
    }
}
