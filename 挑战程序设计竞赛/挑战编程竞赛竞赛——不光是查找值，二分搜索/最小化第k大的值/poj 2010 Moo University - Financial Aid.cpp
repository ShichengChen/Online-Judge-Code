#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>pii;
#define x first
#define y second
#define MAXN 100005
pii cow[MAXN];
LL ans1[MAXN],ans2[MAXN];
LL n,m,f;
void find(LL * A,LL u,LL v,LL key)
{
    LL sum = 0;
    priority_queue<LL>que;
    for(LL i = u;i != v;i += key)
    {
        sum += cow[i].y;
        que.push(cow[i].y);
        if(que.size() > m / 2)
        {
            sum -= que.top();
            que.pop();
        }
        A[i] = sum;
    }
}
LL search()
{
    find(ans1,0,n,1);
    find(ans2,n - 1,-1,-1);
    for(LL i = n - m / 2 - 1;i >= m / 2;i--)
    {
        if(cow[i].y + ans1[i - 1] + ans2[i + 1] <= f)
            return cow[i].x;
    }
    return -1;
}
int main()
{
    while(scanf("%lld%lld%lld",&m,&n,&f) != EOF)
    {
        for(LL i = 0;i < n;i++)
            scanf("%lld%lld",&cow[i].x,&cow[i].y);
        sort(cow,cow + n);
        LL ans = search();
        printf("%lld\n",ans);
    }
}
