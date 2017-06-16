#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int buf[10];
int next(int n,int k)
{
    if(!k)return 0;
    long long k2 = (long long)k * k;
    int len = 0;
    while(k2)
    {
        buf[len++] = k2 % 10;
        k2 /= 10;
    }
    if(n > len)n = len;
    int ans = 0;
    for(int i = 0;i < n;i++)
        ans = ans * 10 + buf[--len];
    return ans;
}
int main()
{
    int _,n,k,k1,k2,ans;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&k);
        ans = k1 = k2 = k;
        do
        {
            k1 = next(n,k1);
            k2 = next(n,k2);
            ans = max(ans,k2);
            k2 = next(n,k2);
            ans = max(ans,k2);
        }while(k1 != k2);
        printf("%d\n",ans);
    }
}
