#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 8
typedef long long LL;
LL ans;
char arr[MAXN];
void dfs(int deep,int u,int v,LL num)
{
    if(deep == 0)
    {
        ans = max(ans,num);
        return;
    }
    LL cur = 1;
    for(int i = u;i <= v - deep;i++)
    {
        if(i == u)cur = (arr[i] - '0');
        else cur = 10 * cur + (arr[i] - '0');
        dfs(deep - 1,i + 1,v,num * cur);
    }
}
int main()
{
    int k,n;
    while(scanf("%d%d%s",&n,&k,&arr) != EOF)
    {
        ans = 0;
        dfs(k + 1,0,n,1);
        printf("%lld\n",ans);
    }
}
