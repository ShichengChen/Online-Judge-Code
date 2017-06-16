#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define MAX 101000
#define HASH 100003
struct ST
{
    int edge[6];
}st[MAX];
int head[MAX],next[MAX];
bool check(int test,int org)
{
    int flag = 0;
    for(int i = 0;i < 6;i ++)
    {
        for(int j = 0;st[test].edge[(i + j) % 6] == st[org].edge[j];j ++)
            if(j == 5 && st[test].edge[(i + j) % 6] == st[org].edge[j])flag = 1;
        for(int j = 0;st[test].edge[(i - j + 6) % 6] == st[org].edge[j];j ++)
            if(j == 5 && st[test].edge[(i - j + 6) % 6] == st[org].edge[j])flag = 1;
    }
    return flag;
}
int hash(ST snow)
{
    sort(snow.edge,snow.edge + 6);
    long long hash_value = 0;
    for(int i = 0;i < 6;i++)
        hash_value += (long long)snow.edge[i] * pow(10.0,i);
    return hash_value % HASH;
}
bool try_to_insert(int index)
{
    int hash_value = hash(st[index]);
    int v = head[hash_value];
    for(int i= v;i != -1;i = next[i])
        if(check(i,index))return false;
    next[index] = v;
    head[hash_value] = index;
    return true;
}
void solve(int n)
{
    int flag = 0;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < 6;j++)scanf("%d",&st[i].edge[j]);
        if(!flag && !try_to_insert(i))flag = 1;
    }
    if(flag)printf("Twin snowflakes found.\n");
    else printf("No two snowflakes are alike.\n");
}
void init()
{
    memset(head,-1,sizeof(head));
    memset(next,-1,sizeof(next));
}
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        init();
        solve(n);
    }
}
