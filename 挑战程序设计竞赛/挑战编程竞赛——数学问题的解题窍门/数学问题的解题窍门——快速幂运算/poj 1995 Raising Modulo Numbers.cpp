#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long LL;
LL power(LL a,LL i,LL m)
{
    LL ans = 1;
    while(i)
    {
        if(i & 1)ans = a * ans % m;
        a = a * a % m;
        i = i >> 1;
    }
    return ans;
}
int main()
{
    LL a,b;
    int m,n,ans;
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&m,&n);
        ans = 0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%lld%lld",&a,&b);
            ans = (ans + power(a,b,m)) % m;
        }
        printf("%d\n",ans);
    }
}
