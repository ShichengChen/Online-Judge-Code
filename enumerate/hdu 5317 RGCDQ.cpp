#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
#define MAXN 1000005
#define MAXM 10
int num[MAXN],s[MAXN][MAXM],l,r,_;
int gcd(int a,int b)
{
    if(!b)return a;
    return gcd(b,a % b);
}
int main()
{
    for(int i = 2;i < MAXN;i++)if(!num[i])
        for(int j = i;j < MAXN;j += i)
            num[j]++;
    for(int i = 2;i < MAXN;i++)
    {
        for(int j = 1;j <= 7;j++)
            s[i][j] = s[i - 1][j];
        s[i][num[i]]++;
    }
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&l,&r);
        int ans = 1;
        for(int i = 1;i <= 7;i++)
            for(int j = 1;j <= 7;j++)
            {
                if(i == j && s[r][i] - s[l - 1][i] >= 2)ans = max(ans,i);
                if(i != j && s[r][i] - s[l - 1][i] >= 1 &&
                   s[r][j] - s[l - 1][j] >= 1)ans = max(ans,gcd(i,j));
            }
        printf("%d\n",ans);
    }
}
