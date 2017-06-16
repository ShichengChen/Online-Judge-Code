#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 40015
#define MAXM 415
struct Data
{
    int h,a,c;
    bool operator < (const Data & d)const{
        return a < d.a;
    }
}data[MAXM];
int dp[MAXN];
int main()
{
    int n,ans;
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 0;i < n;i++)
            scanf("%d%d%d",&data[i].h,&data[i].a,&data[i].c);
        sort(data,data + n);
        memset(dp,-1,sizeof(dp));
        ans = dp[0] = 0;
        for(int i = 0;i < n;i++)
            for(int j = 0;j <= data[i].a;j++)
            {
                if(dp[j] >= 0)dp[j] = data[i].c;
                else if(j - data[i].h >= 0)dp[j] = dp[j - data[i].h] - 1;
                if(dp[j] >= 0)ans = max(ans,j);
            }
        printf("%d\n",ans);
    }
}
