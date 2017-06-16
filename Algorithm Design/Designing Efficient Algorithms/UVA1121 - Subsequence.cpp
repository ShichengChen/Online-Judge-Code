#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 100005
int s[MAXN];
int main()
{
    int n,num,cur;
    while(scanf("%d%d",&n,&num) != EOF)
    {
        s[0] = 0;
        int ans = n + 1;
        for(int i = 1,j = 0;i <= n;i++)
        {
            scanf("%d",&s[i]);
            s[i] += s[i - 1];
            if(s[j] > s[i] - num)continue;
            while(s[j] <= s[i] - num)j++;
            ans = min(ans,i - j + 1);
        }
        printf("%d\n",ans == n + 1 ? 0 : ans);
    }
}
