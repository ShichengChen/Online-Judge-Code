#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;
typedef pair<int,int>pii;
#define MAXN 25
#define MAXM 1010
vector<pii>vec[MAXN];
int r[MAXN],t[MAXN],d[MAXN],cnt[MAXN];
bool inque[MAXN];
bool bellman()
{
    stack<int>st;
    for(int i = 0;i <= 24;i++)
        st.push(i),cnt[i] = inque[i] = 1,d[i] = 0;
    while(!st.empty())
    {
        int u = st.top();st.pop();
        inque[u] = 0;
        for(int i = 0;i < vec[u].size();i++)
        {
            int v = vec[u][i].first,val = vec[u][i].second;
            if(d[v] > d[u] + val)
            {
                d[v] = d[u] + val;
                if(!inque[v])
                {
                    inque[v] = 1;
                    st.push(v);
                    if(cnt[v]++ > MAXN)return true;
                }
            }
        }
    }
    return false;
}
bool modify(int val)
{
    for(int i = 0;i <= 24;i++)vec[i].clear();
    for(int i = 1;i <= 24;i++)
    {
        vec[i - 1].push_back(pii(i,t[i]));
        vec[i].push_back(pii(i - 1,0));
    }
    for(int i = 8;i <= 24;i++)
        vec[i].push_back(pii(i - 8,-r[i]));
    for(int i = 1;i <= 7;i++)
        vec[i].push_back(pii(i + 16,-r[i] + val));
    vec[24].push_back(pii(0,-val));
    return bellman();
}
int binary_search(int l,int r)
{
    int ans = -1;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(modify(mid))
            l = mid + 1;
        else
            ans = r = mid;
    }
    return ans;
}
int main()
{
    int _,m,cur;
    scanf("%d",&_);
    while(_--)
    {
        memset(t,0,sizeof(t));
        for(int i = 1;i <= 24;i++)
            scanf("%d",&r[i]);
        scanf("%d",&m);
        for(int i = 1;i <= m;i++)
        {
            scanf("%d",&cur);
            t[cur + 1]++;
        }
        int ans = binary_search(0,m);
        if(ans == -1)puts("No Solution");
        else printf("%d\n",ans);
    }
}
