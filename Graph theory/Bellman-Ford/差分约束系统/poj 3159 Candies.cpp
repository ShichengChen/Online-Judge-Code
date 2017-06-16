#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 30010
#define MAXM 150010
int d[MAXN],w[MAXM],V[MAXM],head[MAXN],next[MAXM],number;
bool inque[MAXN];
void insert(int u,int v,double val)
{
    next[number] = head[u];
    V[number] = v;
    w[number] = val;
    head[u] = number++;
}
void bellman()
{
    memset(inque,false,sizeof(inque));
    memset(d,0x3f,sizeof(d));
    stack<int>st;
    d[1] = 0;inque[1] = 1;
    st.push(1);
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
                }
            }
        }
    }
}
int main()
{
    int n,m,val,u,v;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        memset(head,-1,sizeof(head));
        number = 0;
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d%d",&u,&v,&val);
            insert(u,v,val);
        }
        bellman();
        printf("%d\n",d[n]);
    }
}
