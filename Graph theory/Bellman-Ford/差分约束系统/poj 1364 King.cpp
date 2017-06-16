#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
using namespace std;
#define MAXN 110
#define MAXM 110
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
    for(int i = 0;i <= n;i++)
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
                    if(cnt[v]++ > n)return false;
                }
            }
        }
    }
    return true;
}
int main()
{
	int n,m,u,v,val;
	char cmd[3];
	while(scanf("%d",&n),n)
	{
		memset(head,-1,sizeof(head));
		number = 0;
		scanf("%d",&m);
		for(int i = 0;i < m;i++)
		{
			scanf("%d%d%s%d",&u,&v,cmd,&val);
			if(cmd[0] == 'g')insert(u + v,u - 1,-(val + 1));
			else insert(u - 1,u + v,val - 1);
		}
		if(!bellman(n))puts("successful conspiracy");
		else puts("lamentable kingdom");
	}
}
