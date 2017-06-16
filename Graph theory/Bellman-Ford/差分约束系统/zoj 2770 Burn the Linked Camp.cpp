#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 1010
#define MAXM 12010
int d[MAXN],w[MAXM],V[MAXM],head[MAXN],next[MAXM],cnt[MAXN],number;
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
    memset(d,0,sizeof(d));
    memset(cnt,0,sizeof(cnt));
    memset(inst,0,sizeof(inst));
    stack<int>st;
    st.push(n),d[n] = 0;
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
                    if(cnt[v]++ > n)return false;
                }
            }
        }
    }
    return true;
}
int main()
{
    int n,m,val,u,v;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        memset(head,-1,sizeof(head));
        number = 0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&val);
            insert(i - 1,i,val);
            insert(i,i - 1,0);
        }
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d%d",&u,&v,&val);
            insert(v,u - 1,-val);
        }
        if(bellman(n))printf("%d\n",-d[0]);
        else puts("Bad Estimations");
    }
}
