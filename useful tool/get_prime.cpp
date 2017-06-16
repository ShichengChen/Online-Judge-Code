#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 10000
bool vis[MAXN];
int prime[MAXN];
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
int main()
{
    int k = get_prime();
    cout << k << endl;
}
