#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[30],b[30],c[30];
void transform(int a[],long long num,int & len)
{
    while(num)
    {
        a[len++] = num % 10;
        num /= 10;
    }
}
void solve(int len1,int len2)
{
    memset(c,0,sizeof(c));
    for(int i = 0;i < len1;i++)
        for(int j = 0;j < len2;j++)
        c[i + j] += a[i] * b[j];
    c[0] += 2;
    for(int i = 0;i < len1 + len2;i++)
    {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    if(!c[len1 + len2 - 1])len1--;
    for(int i = len1 + len2 - 1;i >= 0;i--)
        printf("%d",c[i]);
    puts("");
}
int main()
{
    int _;
    long long n;
    scanf("%d",&_);
    for(int kcas = 1;kcas <= _;kcas++)
    {
        printf("Case #%d: ",kcas);
        scanf("%I64d",&n);
        if(n <= 1e8)
            printf("%I64d\n",n * (8 * n - 7) + 1);
        else
        {
            long long n1 = 8 * n + 1,n2 = n - 1;
            int len1 = 0,len2 = 0;
            transform(a,n1,len1) , transform(b,n2,len2);
            solve(len1,len2);
        }
    }
}
