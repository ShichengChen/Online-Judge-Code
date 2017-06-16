#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
using namespace std;
#define MAXN 1010
#define MAXM 200010
int d[MAXN],w[MAXM],V[MAXM],head[MAXN],next[MAXM],cnt[MAXN],number;
bool inque[MAXN];
void insert(int u,int v,int val)
{
    next[number] = head[u];
    V[number] = v;
    w[number] = val;
    head[u] = number++;
}
bool bellman(int n)
{
    stack<int>st;
    for(int i = 1;i <= n;i++)
        d[i] = 0,st.push(i),inque[i] = cnt[i] = 1;
    while(!st.empty())
    {
        int u = st.top();st.pop();
        inque[u] = 0;
        for(int i = head[u];i != -1;i = next[i])
        {
            int v = V[i];
            if(d[v] > d[u] + w[i])
            {
                d[v] = d[u] + w[i];
                if(!inque[v])
                {
                    inque[v] = 1;
                    st.push(v);
                    if(++cnt[v] > n)return false;
                }
            }
        }
    }
    return true;
}
int main()
{
	int n,m,u,v,w;
	char cmd[3];
	while(scanf("%d%d",&n,&m) != EOF)
	{
		memset(head,-1,sizeof(head));
		number = 0;
		for(int i = 0;i < m;i++)
		{
			scanf("%s",cmd);
			if(cmd[0]=='P')
			{
				scanf("%d%d%d",&u,&v,&w);
                insert(u,v,-w) , insert(v,u,w);
			}
			else
			{
				scanf("%d%d",&u,&v);
				insert(u,v,-1);
			}
		}
		if(!bellman(n))puts("Unreliable");
		else puts("Reliable");
	}
}
