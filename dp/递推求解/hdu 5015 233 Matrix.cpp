#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long LL;
#define MAXN 15
#define MOD 10000007
int arr[MAXN];
struct Matrix
{
    int mat[MAXN][MAXN],n;
    void init(int n)
    {
        memset(mat,0,sizeof(mat));
        this -> n = n;
    }
    void operator *= (Matrix & m){
        Matrix cur;
        cur.init(n);
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                for(int k = 1;k <= n;k++)
                    cur.mat[i][j] = (cur.mat[i][j] + (LL)mat[i][k] * m.mat[k][j]) % MOD;
        *this = cur;
    }
};
Matrix pow(Matrix temp,int b,int n)
{
    Matrix ans;
    ans.init(n);
    for(int i = 1;i <= n;i++)
        ans.mat[i][i] = 1;
    while(b)
    {
        if(b & 1)ans *= temp;
        temp *= temp;
        b = b >> 1;
    }
    return ans;
}
int solve(int n,int b)
{
    Matrix temp;
    temp.init(n);
    for(int i = 1;i < n;i++)
    {
        temp.mat[i][1] = 10;
        for(int j = 2;j <= i;j++)
            temp.mat[i][j] = 1;
        temp.mat[i][n] = 3;
    }
    temp.mat[n][n] = 1;
    Matrix cur = pow(temp,b,n);
    int ans = 0;
    for(int i = 1;i <= n;i++)
        ans = (ans + (LL)cur.mat[n - 1][i] * arr[i]) % MOD;
    return ans;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        for(int i = 2;i <= n + 1;i++)
        {
            scanf("%d",&arr[i]);
            arr[i] %= MOD;
        }
        arr[n + 2] = 1,arr[1] = 23;
        int ans = solve(n + 2,m);
        printf("%d\n",ans);
    }
}
