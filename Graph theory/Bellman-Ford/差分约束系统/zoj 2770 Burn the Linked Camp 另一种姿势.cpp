#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 1010
#define MAXM 12010
int d[MAXN],s[MAXN],w[MAXM],V[MAXM],head[MAXN],next[MAXM],number;
bool inst[MAXN];
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
    memset(inst,false,sizeof(inst));
    memset(d,0x3f,sizeof(d));
    st.push(n),inst[n] = 1,d[n] = 0;
    while(!st.empty())
    {
        int u = st.top();st.pop();
        inst[u] = 0;
        for(int i = head[u];i != -1;i = next[i])
        {
            int v = V[i];
            if(d[v] > d[u] + w[i])
            {
                d[v] = d[u] + w[i];
                if(!inst[v])
                {
                    inst[v] = 1;
                    st.push(v);
                }
            }
        }
    }
    return true;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        memset(head,-1,sizeof(head));
        number = 0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&s[i]);
            s[i] += s[i - 1];
            insert(i - 1,i,s[i] - s[i - 1]);
            insert(i,i - 1,0);
        }
        bool fail = 0;
        for(int i = 0;i < m;i++)
        {
            int u,v,val;
            scanf("%d%d%d",&u,&v,&val);
            if(s[v] - s[u - 1] < val)fail = 1;
            insert(v,u - 1,-val);
        }
        if(!fail && bellman(n))printf("%d\n",-d[0]);
        else puts("Bad Estimations");
    }
}
