#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 20020
#define MOD 1000
int fa[MAXN],d[MAXN];
int findfa(int i)
{
    if(fa[i] == -1)return i;
    int ancestor = fa[i];
    // this time i'father maybe not be renew;
    fa[i] = findfa(fa[i]);
    d[i] += d[ancestor];
    return fa[i];
}
int main()
{
    int _,n,father,son;
    scanf("%d",&_);
    while(_--)
    {
        char op[10];
        scanf("%d",&n);
        memset(fa,-1,sizeof(fa));
        memset(d,0,sizeof(d));
        while(scanf("%s",op) && op[0]!='O')
             if(op[0] == 'E')
             {
                    scanf("%d",&son);
                    findfa(son);
                    printf("%d\n",d[son]);
             }
             else
             {
                    scanf("%d%d",&son,&father);
                    fa[son] = father;
                    d[son] = abs(son - father) % MOD;
             }
    }
}
