#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<climits>
#include<string>
using namespace std;
#define MAX 100100
#define INF (1 << 30)
int array[MAX];
bool greedy(int top,int N,int M)
{
    int curmax = 0,day = 1;
    for(int i = 0;i < N;i++)
    {
        if(curmax + array[i] <= top)curmax += array[i];
        else
        {
            curmax = array[i];
            day++;
        }
        if(day > M)return false;
    }
    return true;
}
int binary(int l,int r,int N,int M)
{
    int minn = INF;
    while(l < r)
    {
        int mid = (l + r) / 2;
        if(greedy(mid,N,M))
        {
            r = mid;
        }
        else l = mid + 1;
    }
    return l;
}
int main()
{
    int N,M;
    while(scanf("%d%d",&N,&M) != EOF)
    {
        int minn = 0,maxn = 0;
        for(int i = 0;i < N;i++)
        {
            scanf("%d",&array[i]);
            minn = max(minn,array[i]);
            maxn += array[i];
        }
        int ans = binary(minn,maxn,N,M);
        printf("%d\n",ans);
    }
    return 0;
}
