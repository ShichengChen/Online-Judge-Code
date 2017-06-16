#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MOD 10007
struct Matrix
{
    int mat[3][3];
    void operator *= (Matrix & m)
    {
        Matrix cur;
        memset(cur.mat,0,sizeof(cur.mat));
        for(int i = 0;i < 3;i++)
            for(int j = 0;j < 3;j++)
                for(int k = 0;k < 3;k++)
                    cur.mat[i][j] = (cur.mat[i][j] + mat[i][k] * m.mat[k][j]) % MOD;
        * this = cur;
    }
};
int solve(int b)
{
    Matrix ans,cur;
    memset(ans.mat,0,sizeof(ans.mat));
    for(int i = 0;i < 3;i++)
        ans.mat[i][i] = 1;
    cur.mat[2][0] = cur.mat[0][2] = 0;
    cur.mat[0][1] = cur.mat[2][1] = 1;
    cur.mat[0][0] = cur.mat[1][0] = cur.mat[1][1] = 2;
    cur.mat[1][2] = cur.mat[2][2] = 2;
    while(b)
    {
        if(b & 1)ans *= cur;
        cur *= cur;
        b = b >> 1;
    }
    int total = ans.mat[0][0] % MOD;
    return total;
}
int main()
{
    int _,n;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        int ans = solve(n);
        printf("%d\n",ans);
    }
}
