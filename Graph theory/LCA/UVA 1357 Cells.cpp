#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int,int>pii;
#define MAXN 3000010
int son[MAXN],id[MAXN],num[MAXN];
pii stack[MAXN];
vector<int>vec[MAXN];
void dfs()
{
    int top = 1,cnt = 0;
    stack[top] = pii(0,0);
    id[0] = 0;
    while(top)
    {
        int u = stack[top].first,i = stack[top].second;
        //cout << u << " " << vec[u].size() << endl;
        if(vec[u].size() == 0)
        {
            son[u] = 1;
            top--;
        }
        else if(i < vec[u].size())
        {
            stack[top].second++;
            stack[++top] = pii(vec[u][i],0);
            id[vec[u][i]] = ++cnt;
        }
        else
        {
            son[u] = 1;
            for(i = 0;i < vec[u].size();i++)
                son[u] += son[vec[u][i]];
            top--;
        }
    }
}
bool LCA(int a,int b,int n)
{
    if(a >= b || a >= n)return false;
    if(b >= n)b = lower_bound(num,num + n,b) - num;
    if(id[a] <= id[b] && id[b] < id[a] + son[a])return true;
    return false;
}
int main()
{
    int _,n,m,a,b;
    for(int kcas = scanf("%d",&_);kcas <= _;kcas++)
    {
        printf("Case %d:\n",kcas);
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&num[i]);
            if(i)num[i] += num[i - 1];
            vec[i].clear();
        }
        for(int v = 1;v < n;v++)
        {
            int u = lower_bound(num,num + n,v) - num;
            vec[u].push_back(v);
        }
        dfs();
        //for(int i = 0;i < n;i++)cout << son[i] << " son " << i << endl;
        scanf("%d",&m);
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d",&a,&b);
            if(LCA(a,b,n))puts("Yes");
            else puts("No");
        }
        if(_ != kcas)puts("");
    }
}
