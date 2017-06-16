#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long LL;
bool prime(LL n)
{
    for(int i = 2;(LL)i * i < n;i++)
        if(n % i == 0)return false;
    return true;
}
LL power(LL a,LL i,LL p)
{
    LL ans = 1;
    while(i)
    {
        if(i & 1)ans = a * ans % p;
        a = a * a % p;
        i = i >> 1;
    }
    return ans;
}
bool test(LL a,LL p)
{
    if(prime(p))return false;
    if(power(a,p,p) % p == a % p)return true;
    return false;
}
int main()
{
    LL a,p;
    while(scanf("%lld%lld",&p,&a),a | p)
        if(test(a,p))puts("yes");
        else puts("no");
}
