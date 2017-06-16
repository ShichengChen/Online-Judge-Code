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
#define MOD 2006
#define MIN 1e-9
#define INF (1 << 29)
int binary(int N,int k)
{
    if(k == 1)return N % MOD;
    int mid = k / 2;
    int ans = binary(N,mid);
    if(mid == k - mid)
        return (long long)ans * ans % MOD;
    else return (long long)((long long)(ans * ans % MOD) * N) % MOD;
}
int main()
{
    int N;
    while(scanf("%d",&N) && N)
    {
        int ans = binary(N,N);
        printf("%d\n",ans);
    }
}
