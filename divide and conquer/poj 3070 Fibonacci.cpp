#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MOD 10000
#define MAXN 2
struct Matrix
{
    int mat[MAXN][MAXN],n;
    void operator *= (Matrix & ma){
        Matrix cur;
        cur.n = 2;
        memset(cur.mat,0,sizeof(cur.mat));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                for(int k = 0;k < n;k++)
                {
                    cur.mat[i][j] += (mat[i][k] * ma.mat[k][j]);
                    cur.mat[i][j] %= MOD;
                }
        *this = cur;
    }
};
Matrix pow(int n)
{
    Matrix mat,ans;
    mat.mat[0][0] = mat.mat[0][1] = mat.mat[1][0] = 1;
    mat.mat[1][1] = 0;
    mat.n = ans.n = 2;
    ans.mat[0][0] = ans.mat[1][1] = 1;
    ans.mat[0][1] = ans.mat[1][0] = 0;
    while(n)
    {
        if(n & 1)ans *= mat;
        mat *= mat;
        n = n >> 1;
    }
    return ans;
}
int main()
{
    int n;
    while(scanf("%d",&n) , n != -1)
    {
        if(n)printf("%d\n",pow(n - 1).mat[0][0]);
        else puts("0");
    }
}
