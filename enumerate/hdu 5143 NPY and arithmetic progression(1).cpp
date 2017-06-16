#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define FOR(i) for(int i = 0;i <= 2;i++)
#define test(i) (i != 1 && i != 2 && i >= 0)
#define MAXN 30
int cnt = 0;
struct Node
{
    int a,b,c,d;
}node[MAXN];
void run()
{
    FOR(i)FOR(j)FOR(k)
    {
        node[cnt].a = i + j;
        node[cnt].b = i + j + k;
        node[cnt].c = i + j + k;
        node[cnt++].d = i + k;
    }
}
bool check(int a,int b,int c,int d)
{
    for(int i = 0;i < cnt;i++)
        if(test(a - node[i].a) && test(b - node[i].b) && test(c - node[i].c) && test(d - node[i].d))
            return true;
    return false;
}
int main()
{
    int _,a,b,c,d;
    run();
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        bool ans = check(a,b,c,d);
        if(ans)puts("Yes");
        else puts("No");
    }
}
