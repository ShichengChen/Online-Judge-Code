#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 17
#define F(i,n) for(int i = 0;i < (n);i++)
#define INF 0x3f3f3f3f
bool A[MAXN][MAXN],B[MAXN][MAXN];
int _,n,ans;
bool _find(int i,int j)
{
    int cnt = 0;
    if(i - 1 >= 0)cnt += B[i - 1][j];
    if(j - 1 >= 0)cnt += B[i][j - 1];
    if(j + 1 < n)cnt += B[i][j + 1];
    if(i + 1 < n)cnt += B[i + 1][j];
    if(cnt % 2 == 0)return true;
    if(i + 1 == n || B[i + 1][j])return false;
    return B[i + 1][j] = true;
}
int check(int s)
{
    memcpy(B,A,sizeof(A));
    F(i,n)if(s >> i & 1)B[0][i] = true;
    F(i,n)F(j,n)if(!_find(i,j))return INF;
    int cnt = 0;
    F(i,n)F(j,n)if(A[i][j] != B[i][j])cnt++;
    //cout << cnt << " cnt " << endl;
    return cnt;
}
int main()
{
    cin >> _;
    F(kcas,_)
    {
        cin >> n;
        F(i,n)F(j,n)cin >> A[i][j];
        ans = INF;
        F(i,(1 << n))ans = min(ans,check(i));
        if(ans == INF)printf("Case %d: -1\n",kcas + 1);
        else printf("Case %d: %d\n",kcas + 1,ans);
    }
}
