#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 101000
#define LOG_N 16
int d[N][LOG_N],value[N],count[N],num[N],left_place[N],right_place[N];
void RMQ_init(int rle)   ///Run Length Encoding
{
    for(int j = 0;(1 << j) <= rle;j++)
        for(int i = 1;i + (1 << j) <= rle;i++)
            if(j == 0)d[i][0] = count[i];
            else d[i][j] = max(d[i][j - 1],d[i + (1 << j - 1)][j - 1]);
}
int RMQ_expand(int l,int r)
{
    if(num[l] == num[r])return r - l + 1;
    int maxn = max(r - left_place[r] + 1,right_place[l] - l + 1);
    if(num[r] - num[l] == 1)return maxn;
    int cur = 0;
    while((num[r] - 1) - (num[l] + 1) + 1 > (1 << cur + 1))cur++;
    maxn = max(max(d[num[l] + 1][cur],d[(num[r] - 1) - (1 << cur) + 1][cur]),maxn);
    return maxn;
}
int main()
{
    int n,query,cur,r,l;
    while(scanf("%d",&n),n)
    {
        scanf("%d",&query);
        int cnt = 1;
        scanf("%d",&cur);
        num[1] = cnt,value[cnt] = cur,count[cnt] = 1;
        for(int i = 2;i <= n;i++)
        {
            scanf("%d",&cur);
            if(cur == value[cnt])
                count[cnt]++;
            else
            {
                count[++cnt] = 1;
                value[cnt] = cur;
            }
            num[i] = cnt;
        }
        for(int rle = 1,i = 1;rle <= cnt;rle++)
        {
            for(int j = 0;j < count[rle];j++)
            {
                left_place[i + j] = i;
                right_place[i + j] = i + count[rle] - 1;
            }
            i += count[rle];
        }
        RMQ_init(cnt);
        for(int i = 0;i < query;i++)
        {
            scanf("%d%d",&l,&r);
            int ans = RMQ_expand(l,r);
            printf("%d\n",ans);
        }
    }
}
