#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
#define MAXN 760
struct Node
{
    int s,b;
    Node(int s,int b) : s(s) , b(b) {}
    bool operator < (const Node & nod)const{
        return s > nod.s;
    }
};
int ans[MAXN],cur[MAXN];
void merge(int k)
{
    priority_queue<Node>que;
    for(int i = 1;i <= k;i++)
        que.push(Node(ans[i] + cur[1],1));
    for(int i = 1;i <= k;i++)
    {
        ans[i] = que.top().s;
        int b = que.top().b;
        que.pop();
        que.push(Node(ans[i] - cur[b] + cur[b + 1],b + 1));
    }
}
int main()
{
    int k;
    while(scanf("%d",&k) != EOF)
    {
        for(int i = 1;i <= k;i++)scanf("%d",&ans[i]);
        sort(ans + 1,ans + k + 1);
        for(int j = 2;j <= k;j++)
        {
            for(int i = 1;i <= k;i++)scanf("%d",&cur[i]);
            sort(cur + 1,cur + k + 1);
            merge(k);
        }
        for(int i = 1;i <= k;i++)
        {
            if(i == k)printf("%d\n",ans[i]);
            else printf("%d ",ans[i]);
        }
    }
}
