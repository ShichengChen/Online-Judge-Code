#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN (1 << 20) + 10
#define MAXM 90000
int prime[MAXM],exponential[MAXM];
bool vis[MAXN];
int get_prime()
{
    int cnt = 0;
    for(int i = 2;i < MAXN;i++)if(!vis[i])
    {
        prime[cnt++] = i;
        for(long long j = (long long)i * i;j < MAXN;j += i)
            vis[j] = true;
    }
    return cnt;
}
int get_exponential(int n,int k,int & len)
{
    memset(exponential,0,sizeof(exponential));
    for(int i = 0;i < k;i++)
    {
        while(n % prime[i] == 0)
        {
            n /= prime[i];
            exponential[i]++;
            len++;
        }
        if(n == 1) return i + 1;
    }
}
long long get_factorial(int n)
{
    long long ans = 1;
    for(int i = 2;i <= n;i++)
        ans *= i;
    return ans;
}
int main()
{
    int k = get_prime(),n;
    cout << k << endl;
    while(scanf("%d",&n) != EOF)
    {
        int len = 0;
        int kk = get_exponential(n,k,len);
        long long ans = get_factorial(len);
        for(int i = 0;i < kk;i++)
            while(exponential[i]--)
                ans /= exponential[i] + 1;
        printf("%d %lld\n",len,ans);
    }
}
