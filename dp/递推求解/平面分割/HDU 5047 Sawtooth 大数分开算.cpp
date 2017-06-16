#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const long long MOD = 1e6;
int main()
{
    int _;
    long long n;
    scanf("%d",&_);
    for(int kcas = 1;kcas <= _;kcas++)
    {
        printf("Case #%d: ",kcas);
        scanf("%I64d",&n);
        if(n <= 1e9)
            printf("%I64d\n",n * (8 * n - 7) + 1);
        else
        {
            long long a = n / MOD,b = n % MOD;
            long long high = 8 * a * a * MOD - 7 * a + 16 * a * b;
            long long low = 8 * b * b - 7 * b + 1;
            if(low < 0)
            {
                low += MOD;
                high--;
            }
            else
            {
                high += low / MOD;
                low %= MOD;
            }

            printf("%I64d%06I64d\n",high,low);
        }
    }
}
