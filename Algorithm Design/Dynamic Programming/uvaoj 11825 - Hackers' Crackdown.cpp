#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 20
int p[MAXN],s[1 << MAXN],f[1 << MAXN];
int main()
{
    int n,m,cur,kcas = 0;
    while(cin >> n && n)
    {
        for(int i = 0;i < n;i++)
        {
           cin >> m;
           p[i] = (1 << i);
           while(m--)
           {
               cin >> cur;
               p[i] |= (1 << cur);
           }
        }
        memset(s,0,sizeof(s));
        for(int i = 1;i < (1 << n);i++)
            for(int j = 0;j < n;j++)if(i >> j & 1)
                s[i] |= p[j];
        memset(f,0,sizeof(f));
        for(int i = 1;i < (1 << n);i++)
            for(int j = i;j;j = ((j - 1) & i))
                if(s[j] + 1 == (1 << n))
                    f[i] = max(f[i],f[j ^ i] + 1);
        printf("Case %d: %d\n",++kcas,f[(1 << n) - 1]);
    }
}
