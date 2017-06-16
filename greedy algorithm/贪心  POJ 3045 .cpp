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
#define MAX 55000
#define MIN 1e-9
#define INF (1 << 30)
struct COW
{
    int w,s;
    bool operator < (const COW &co)const
    {
         return co.w + co.s < w + s;
    }
}cow[MAX];
int risk[MAX];
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 0;i < n;i++)
            scanf("%d%d",&cow[i].w,&cow[i].s);
        sort(cow,cow + n);
        int maxn = -INF,sum = 0;
        cow[n].w = 0;cow[n].s = 0;
        for(int i = n - 1;i >= 0;i--)
        {
            sum += cow[i + 1].w;
            maxn = max(maxn,sum - cow[i] . s);
        }
        printf("%d\n",maxn);
    }
}
