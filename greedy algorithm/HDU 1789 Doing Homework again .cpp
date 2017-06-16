#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int,int>pii;
#define MAXN 1005
pii num[MAXN];
int solve(int n)
{
    priority_queue<int,vector<int>,greater<int> >que;
    int ans = 0;
    for(int i = 0;i < n;i++)
    {
        que.push(num[i].second);
        while(que.size() > num[i].first)
        {
            ans += que.top();
            que.pop();
        }
    }
    return ans;
}
int main()
{
    int _,n;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
            scanf("%d",&num[i].first);
        for(int i = 0;i < n;i++)
            scanf("%d",&num[i].second);
        sort(num,num + n);
        int ans = solve(n);
        printf("%d\n",ans);
    }
}
