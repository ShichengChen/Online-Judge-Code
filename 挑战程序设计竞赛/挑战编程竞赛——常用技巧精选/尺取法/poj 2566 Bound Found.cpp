#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,int>pii;
#define MAXN 100005
#define x first
#define y second
#define ABS(i) ((i) < 0 ? (-(i)) : (i))
pii s[MAXN];
int n,k;
void enquiry(LL cur)
{
    LL minn = 1000000001,ans;
    int l,r;
    for(int i = 1,j = 0;i <= n;i++)
    {
        while(j + 1 < i && ABS(s[i].x - s[j].x - cur) >= ABS(s[i].x - s[j + 1].x - cur))
            j++;
        if(ABS(s[i].x - s[j].x - cur) < minn)
        {
            minn = ABS(s[i].x - s[j].x - cur);
            ans = s[i].x - s[j].x;
            r = max(s[i].y,s[j].y);
            l = min(s[j].y,s[i].y) + 1;
            if(!minn)break;
        }
    }
    printf("%lld %d %d\n",ans,l,r);
}
int main()
{
    while(scanf("%d%d",&n,&k) && (n | k))
    {
        s[0] = pii(0,0);
        for(int i = 1;i <= n;i++)
        {
            scanf("%lld",&s[i].x);
            s[i].x = s[i].x + s[i - 1].x;
            s[i].y = i;
        }
        sort(s,s + n + 1);
        int cur;
        while(k--)
        {
            scanf("%d",&cur);
            enquiry((LL)cur);
        }
    }
}
