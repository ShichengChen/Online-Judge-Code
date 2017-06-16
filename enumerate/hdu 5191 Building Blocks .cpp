#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
#define MAXN 50005
int num[MAXN << 1],n,w,h;
int main()
{
    while(scanf("%d%d%d",&n,&w,&h) != EOF)
    {
        LL sum = 0,more = 0,les = -w * h,ans = 1000000000000000;
        for(int i = 0;i < n + w;i++)
        {
            if(i < n)scanf("%d",&num[i]);
            else num[i] = 0;
            sum += num[i];
            num[i] -= h;
            if(num[i] > 0)more += num[i];
            else les += num[i];
            int j = i - w;
            if(j >= 0)
            {
                if(num[j] < 0)les -= num[j];
                else more -= num[j];
            }
            else les -= -h;
            ans = min(ans,max(more,-les));
        }
        if((LL)w * h > sum)puts("-1");
        else printf("%I64d\n",ans);
    }
}
