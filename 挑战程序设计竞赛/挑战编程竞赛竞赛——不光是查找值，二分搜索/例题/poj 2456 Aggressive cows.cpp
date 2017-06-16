#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100005
#define INF 1000000005
int pos[MAXN],n,c;
bool isfind(int l)
{
    int num = 1,ind = 0;
    for(int i = 0;i < n;i++)
    {
        if(pos[i] - pos[ind] >= l)
        {
            ind = i;
            num++;
        }
    }
    return num >= c;
}
int binary(int l,int r)
{
    while(l < r)
    {
        int mid = l + r + 1 >> 1;
        if(isfind(mid))l = mid;
        else r = mid - 1;
    }
    return l;
}
int main()
{
    while(scanf("%d%d",&n,&c) != EOF)
    {
        for(int i = 0;i < n;i++)
            scanf("%d",&pos[i]);
        sort(pos,pos + n);
        int ans = binary(0,INF);
        printf("%d\n",ans);
    }
}
