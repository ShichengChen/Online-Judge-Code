/*
if is dense map use matrix and loop is better than EDGE and set;
and this question need thinking deep
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
using namespace std;
#define MAX 40400
#define N 220
struct EGDE
{
    int v,next;
}edge[MAX];
int first[N],indu[N],ans[N];
set<int,greater<int> >gather;
int number,weight;
void init(int n)
{
    number = 0;weight = n;
    memset(first,-1,sizeof(first));
    memset(edge,-1,sizeof(edge));
    memset(indu,0,sizeof(indu));
}
void insert(int x,int y)
{
    edge[number].next = first[x];
    edge[number].v = y;
    first[x] = number++;
}
bool bfs(int n)
{
                if(gather.empty())return false;
                while(!gather.empty())
                {
                            int u = *(gather.begin());
                            gather.erase(u);
                            ans[u] = weight--;
                            for(int index = first[u];index != -1;index = edge[index].next)
                            {
                                    indu[edge[index].v] --;
                                    if(!indu[edge[index].v])
                                            gather.insert(edge[index].v);
                            }
                }
                if(weight == 0)return true;
                return false;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
            int n,m;scanf("%d%d",&n,&m);
            init(n);
            for(int i = 1;i <= m;i++)
            {
                int x,y; scanf("%d%d",&x,&y);
                insert(y,x);
                indu[x]++;
            }
            for(int i = 1;i <= n;i++)if(indu[i] == 0)
                    gather.insert(i);
            if(bfs(n))
            {
                    for(int i = 1;i <= n;i++)
                    {
                          if(i == n)printf("%d\n",ans[i]);
                          else printf("%d ",ans[i]);
                    }
            }
            else puts("-1");
    }
}
