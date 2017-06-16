#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 55000
int fa[N],rank[N];
int findfa(int i)
{
    if(fa[i] == i)return i;
    int grandfa = findfa(fa[i]);
    rank[i] = (rank[i] + rank[fa[i]]) % 3;
    fa[i] = grandfa;
    return grandfa;
}
void Union(int type,int x,int y,int fx,int fy)
{
    fa[fy] = fx;
    rank[fy] = (3 - rank[y] + type + rank[x]) % 3;
}
int main()
{
    int n,k,d,x,y,cnt = 0;
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;i++)
    {
        fa[i] = i;
        rank[i] = 0;
    }
    while(k--)
    {
        scanf("%d%d%d",&d,&x,&y);
        if(x > n || y > n)
        {
            cnt ++;
            continue;
        }
        int fx = findfa(x);
        int fy = findfa(y);
        if(fx == fy)
        {
            if((rank[y] - rank[x] + 3) % 3 != d - 1)cnt++;
        }
        else Union(d - 1,x,y,fx,fy);
    }
    printf("%d\n",cnt);
    return 0;
}
