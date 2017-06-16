#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 110005
char cs[MAXN],s[MAXN << 1];
int p[MAXN << 1];
int main()
{
    while(scanf("%s",cs) != EOF)
    {
        int len = strlen(cs);
        s[0] = '$';
        for(int i = 0;i <= len;i++)
        {
            s[i << 1 | 1] = '#';
            s[(i << 1) + 2] = cs[i];
        }
        int idx = 0,maxn = 0,ans = 1;
        for(int i = 1;i < (len << 1);i++)
        {
            if(maxn > i)
                p[i] = min(p[idx * 2 - i],maxn - i);
            else
                p[i] = 1;
            for(;s[i + p[i]] == s[i - p[i]];p[i]++);
            ans = max(ans,p[i] - 1);
            if(i + p[i] > maxn)
            {
                maxn = p[i] + i;
                idx = i;
            }
        }
        printf("%d\n",ans);
    }
}
