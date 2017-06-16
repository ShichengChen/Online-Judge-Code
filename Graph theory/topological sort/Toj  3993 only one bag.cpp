#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<set>
using namespace std;
#define MAX 110
struct EGDE
{
    int v,next;
}edge[MAX];
int first[MAX],indu[MAX],ans[MAX];
set<int>gather;
int number,end;
void init()
{
    number = 0;end = 0;
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
                            int i = *(gather.begin());
                            gather.erase(i);
                            ans[end++] = i;
                            int index = first[i];
                            for(;index != -1;index = edge[index].next)
                            {
                                    indu[edge[index].v] --;
                                    if(!indu[edge[index].v])
                                            gather.insert(edge[index].v);
                            }
                }
                if(end == n)return true;
                return false;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
            int n,m;scanf("%d%d",&n,&m);
            init();
            for(int i = 1;i <= m;i++)
            {
                int x,y; scanf("%d%d",&x,&y);
                insert(x,y);
                indu[y]++;
            }
            for(int i = 1;i <= n;i++)if(indu[i] == 0)
                    gather.insert(i);
            if(bfs(n))
            {
                    for(int i = 0;i < end;i++)
                    {
                          if(i == end - 1)printf("%d \n",ans[i]);
                          else printf("%d ",ans[i]);
                    }
            }
            else puts("Low IQ");
    }
}
