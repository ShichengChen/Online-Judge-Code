#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 10005
int prime[MAXN];
void solve()
{
    for(int i = 2;i <= MAXN;i++)
    {
        if(!prime[i])
        {
            for(int j = 2;i * j <= MAXN;j++)
            {
                int num = i * j;
                while(num % i == 0)
                {
                    prime[i * j]++;
                    num /= i;
                }
            }
            prime[i] = true;
        }
    }
}
int main()
{
    int _,n,m,cur;
    solve();
    scanf("%d",&_);
    for(int kcas = 1;kcas <= _;kcas++)
    {
        printf("Case #%d: ",kcas);
        scanf("%d%d",&n,&m);
        int v = 0,num;
        while(n--)
        {
            num = 0;
            for(int i = 1;i <= m;i++)
            {
                scanf("%d",&cur);
                num += prime[cur];
            }
            v ^= num;
        }
        if(v)puts("YES");
        else puts("NO");
    }
}
