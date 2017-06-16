#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 70
int n,mod,b;
struct Matrix
{
    int mat[MAXN][MAXN];
    void operator *= (Matrix & m)
    {
        Matrix temp;
        memset(temp.mat,0,sizeof(temp.mat));
        for(int i = 0;i < n * 2;i++)
            for(int j = 0;j < n * 2;j++)
                for(int k = 0;k < n * 2;k++)
                    temp.mat[i][j] = (temp.mat[i][j] + mat[i][k] * m.mat[k][j]) % mod;
        * this = temp;
    }
}ans,cur;
void solve()
{
    memset(ans.mat,0,sizeof(ans.mat));
    for(int i = 0;i < n * 2;i++)
        ans.mat[i][i] = 1;
    while(b)
    {
        if(b & 1)ans *= cur;
        cur *= cur;
        b = b >> 1;
    }
}
int main()
{
    while(scanf("%d%d%d",&n,&b,&mod) != EOF)
    {
        b++;
        memset(cur.mat,0,sizeof(cur.mat));
        for(int i = 0;i < 2 * n;i++)
            for(int j = 0;j < 2 * n;j++)
                if(i < n && j < n)
                {
                    scanf("%d",&cur.mat[i][j]);
                    if(i == j && i < n)cur.mat[i][j + n] = 1;
                }
                else if(i == j && i >= n)cur.mat[i][j] = 1;
        solve();
        for(int i = 0;i < n;i++)
            for(int j = n;j < n * 2;j++)
            {
                if(i == j - n)ans.mat[i][j]--;
                if(j != 2 * n - 1)printf("%d ",(ans.mat[i][j] + mod) % mod);
                else printf("%d\n",(ans.mat[i][j] + mod) % mod);
            }
    }
}
