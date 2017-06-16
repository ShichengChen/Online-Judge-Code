#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 1010
int up[MAXN][MAXN],l[MAXN],r[MAXN];
int main()
{
    int _,n,m;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        int ans = 0;
        memset(l,0,sizeof(l));
        fill(r,r + m,m + 1);
        for(int i = 1;i <= n;i++)
        {
            int lo = 0,ro = m + 1;
            for(int j = 1;j <= m;j++)
            {
                int c = getchar();
                while(c != 'R' && c != 'F')c = getchar();
                if(c == 'R')up[i][j] = 0;
                else up[i][j] = up[i - 1][j] + 1;
                if(up[i][j])l[j] = max(l[j],lo + 1);
                else
                {
                    lo = j;
                    l[j] = 0;
                }
            }
            for(int j = m;j >= 1;j--)
            {
                if(up[i][j])
                {
                    r[j] = min(r[j],ro - 1);
                    ans = max(ans,up[i][j] * (r[j] - l[j] + 1));
                }
                else
                {
                    ro = j;
                    r[j] = m + 1;
                }
            }
        }
        printf("%d\n",ans * 3);
    }
}
