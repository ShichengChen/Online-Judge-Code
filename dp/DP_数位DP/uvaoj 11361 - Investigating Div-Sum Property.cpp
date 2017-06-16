#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define MAXN 10
#define MAXM 100
int d[MAXN][MAXM][MAXM],pow10[MAXN];
int MOD,a,b;
inline int mod(int a)
{
    return (a % MOD + MOD) % MOD;
}
int f(int len,int m1,int m2)
{
    if(len == 0)return m1 == 0 && m2 == 0 ? 1 : 0;
    if(d[len][m1][m2] >= 0)return d[len][m1][m2];
    d[len][m1][m2] = 0;
    for(int i = 0;i < 10;i++)
        d[len][m1][m2] += f(len - 1,mod(m1 - i),mod(m2 - i * pow10[len - 1]));
    return d[len][m1][m2];
}
int solve(int n)
{
    char digits[11];
    sprintf(digits, "%d", n);
    int len = strlen(digits);
    int x = 0,y = 0,ans = 0;
    for(int i = 0;i < len;i++)
    {
        int star = len - i - 1;
        for(int j = 0;j < digits[i] - '0';j++)
            ans += f(star,mod(-x - j),mod(-y - j * pow10[star]));
        x += digits[i] - '0';
        y += (digits[i] - '0') * pow10[star];
    }
    return ans;
}
int main()
{
    int _;
    scanf("%d",&_);
    pow10[0] = 1;
    for(int i = 1;i <= 9;i++)
        pow10[i] = 10 * pow10[i - 1];
    while(_--)
    {
        scanf("%d%d%d",&a,&b,&MOD);
        memset(d,-1,sizeof(d));
        if(MOD < 90)
            printf("%d\n",solve(b + 1) - solve(a));
        else
            puts("0");
    }
}
