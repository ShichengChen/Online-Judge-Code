#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long LL;
#define MAXM 54
int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
LL n,ans,maxi;
void get_crt(int id,LL num,int crt)
{
    for(int i = 1;i <= MAXM;i++)
    {
        num *= prime[id];
        if(num > n || crt * (1 + i) < maxi && ans < num) return;
        if(crt * (1 + i) > maxi)
        {
            maxi = crt * (1 + i);
            ans = num;
        }
        else if(crt * (1 + i) == maxi && ans > num)
            ans = num;
        get_crt(id + 1,num,crt * (1 + i));
    }
}
int main()
{
    while(scanf("%lld",&n) != EOF)
    {
        ans = 1,maxi = 1;
        get_crt(0,1,1);
        printf("%lld\n",ans);
    }
}
