#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 5005
bool dir[MAXN],f[MAXN];
int solve(int k,int n)
{
    memset(f,0,sizeof(f));
    int sum = 0,m = 0;
    for(int i = 1;i + k - 1 <= n;i++)
    {
        if((sum + dir[i]) & 1)
        {
            f[i] = 1;
            sum++;
            m++;
        }
        if(i - k + 1 > 0)sum -= f[i - k + 1];
    }
    for(int i = n - k + 2;i <= n;i++)
    {
        if((sum + dir[i]) & 1)
            return n + 1;
        if(i - k + 1 > 0)sum -= f[i - k + 1];
    }
    return m;
}
int main()
{
    int n;
    char ch[3];
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 1;i <= n;i++)
        {
            scanf("%s",&ch);
            if(ch[0] == 'F')dir[i] = 0;
            else dir[i] = 1;
        }
        int m = n,k = 1;
        for(int i = 1;i <= n;i++)
        {
            int cur = solve(i,n);
            if(cur < m)
            {
                k = i;
                m = cur;
            }
        }
        printf("%d %d\n",k,m);
    }
}
