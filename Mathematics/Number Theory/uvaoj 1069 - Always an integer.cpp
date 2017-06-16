#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
#define MAXN 110
#define LEN 10000
char s[LEN];
int cof[MAXN],len,mod,maxn;
int afterDigit(int i)
{
    for(;(isdigit(s[i])) && i < len;i++);
    return i;
}
bool solve()
{
    for(int num = 0;num <= maxn + 1;num++)
    {
        long long ans = 0;
        for(int exp = 0;exp <= maxn + 1;exp++)if(cof[exp])
        {
            long long x = num;
            if(!num && !exp)x = 1;
            for(int k = 1;k < exp;k++)
                x = (x * num) % mod;
            ans = ((x * cof[exp]) % mod + ans) % mod;
        }
        if(ans)return false;
    }
    return true;
}
int main()
{
    int kcas = 1;
    while(scanf("%s",s) && s[0] != '.')
    {
        memset(cof,0,sizeof(cof));
        len = strlen(s);
        maxn = 0;
        for(int i = 0;i < len;i++)if(s[i] == '/')
        {
            len = i;
            mod = atoi(s + i + 1);
            break;
        }
        for(int i = 0;i < len;i++)
        {
            int coff,exp;
            if(s[i] == 'n')
            {
                coff = 1;
            }
            else if((s[i] == '+' || s[i] == '-') && s[i + 1] == 'n')
            {
                if(s[i] == '+')coff = 1;
                else coff = -1;
                i++;
            }
            else if((s[i] == '+' || s[i] == '-') && s[i + 1] != 'n')
            {
                int ind = afterDigit(i + 1);
                coff = atoi(s + i);
                i = ind;
            }
            else if(isdigit(s[i]))
            {
                int ind = afterDigit(i);
                coff = atoi(s + i);
                i = ind;
            }
            else continue;

            if(s[i] == ')')exp = 0;
            else if(s[i + 1] != '^')exp = 1;
            else
            {
                exp = atoi(s + i + 2);
                i = afterDigit(i + 2);
                i--;
            }
            cof[exp] = coff;
            maxn = max(maxn,exp);
        }
        printf("Case %d: ",kcas++);
        if(solve())puts("Always an integer");
        else puts("Not always an integer");
    }
}
