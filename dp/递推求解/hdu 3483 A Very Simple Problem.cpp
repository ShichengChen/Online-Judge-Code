#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
#define MAXN 55
ll mod,n,x;
struct Matrix
{
    ll mat[MAXN][MAXN];
    Matrix(){
        memset(mat,0,sizeof(mat));
    }
    void operator *= (Matrix & m){
        Matrix t;
        for(int i = 0;i < x + 2;i++)
            for(int j = 0;j < x + 2;j++)
                for(int k = 0;k < x + 2;k++)
                    t.mat[i][j] = (t.mat[i][j] + mat[i][k] * m.mat[k][j]) % mod;
        *this = t;
    }
};
Matrix _pow(Matrix & a,int b)
{
    Matrix ans;
    for(int i = 0;i < x + 2;i++)
        ans.mat[i][i] = 1;
    while(b)
    {
        if(b & 1)ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
ll solve()
{
    if(mod == 1)return 0;
    if(n == 1)return x;
    Matrix c;
    for(int i = 0;i < x + 1;i++)
        c.mat[i][0] = 1;
    for(int i = 1;i < x + 1;i++)
        for(int j = 1;j < x + 1;j++)
            c.mat[i][j] = (c.mat[i - 1][j - 1] + c.mat[i - 1][j]) % mod;
    for(int i = 0;i < x + 1;i++)
        for(int j = 0;j <= i;j++)
            c.mat[i][j] = (x * c.mat[i][j]) % mod;
    for(int i = 0;i < x + 1;i++)
        c.mat[x + 1][i] = c.mat[x][i];
    c.mat[x + 1][x + 1] = 1;
    Matrix cur = _pow(c,n - 1);
    ll ans = 0;
    for(int i = 0;i < x + 2;i++)
        ans = (ans + x * cur.mat[x + 1][i]) % mod;
    return ans;
}
int main()
{
    while(cin >> n >> x >> mod && (n != -1 && x != -1 && mod != -1))
    {
        ll ans = solve();
        cout << ans << endl;
    }
}
