#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<climits>
#include<string>
#include<cmath>
#include<deque>
using namespace std;
#define MAX 5500
#define MIN 1e-9
#define INF (1 << 29)
struct PAGE
{
    int a,b;
    bool operator < (const PAGE & pa)const
    {
        return a < pa.a;
    }
}page[MAX];
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        int N;scanf("%d",&N);
        for(int i = 0;i < N;i++)scanf("%d%d",&page[i].a,&page[i].b);
        sort(page,page + N);
        int l = 1,maxr = 1,num = 1;
        for(int i = 0;i < N;i++)
        {
            if(page[i].a <= l)maxr = max(maxr,page[i].b);
            else if(page[i].a > l && page[i].b > maxr)
            {
                l = maxr + 1;
                maxr = page[i].b;
                num++;
            }
        }
        printf("%d\n",num);
    }
}
