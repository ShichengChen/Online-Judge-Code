#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    int _,n,cur,maxn,ans;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        ans = maxn = -150000;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&cur);
            ans = max(ans,maxn - cur);
            maxn = max(maxn,cur);
        }
        printf("%d\n",ans);
    }
}
