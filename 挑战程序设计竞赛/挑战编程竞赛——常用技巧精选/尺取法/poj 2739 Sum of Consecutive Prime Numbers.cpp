#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 10005
int prime[MAXN],cnt;
bool vis[MAXN];
void find_prime()
{
    cnt = 0;
    for(int i = 2;i < MAXN;i++)if(!vis[i])
    {
        prime[cnt++] = i;
        for(int j = i * i;j < MAXN;j += i)
            vis[j] = true;
    }
}
int main()
{
    find_prime();
    int n,u,v;

    while(scanf("%d",&n),n)
    {
        int cur = 0,ans = 0;
        for(int i = 0,j = 0;i < cnt;i++)
        {
            cur += prime[i];
            while(cur > n)cur -= prime[j++];
            if(cur == n)ans++;
        }
        printf("%d\n",ans);
    }
}
