#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
map<int,vector<int> >mapping;
int main()
{
    int n,m,k,v,cur;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        mapping.clear();
        for(int i = 1;i <= n;i ++)
        {
            scanf("%d",&cur);
            if(!mapping.count(cur))mapping[cur] = vector<int>();
            mapping[cur].push_back(i);
        }
        while(m--)
        {
            scanf("%d%d",&k,&v);
            if(!mapping.count(v) || mapping[v].size() < k)puts("0");
            else printf("%d\n",mapping[v][k - 1]);
        }
    }
}
