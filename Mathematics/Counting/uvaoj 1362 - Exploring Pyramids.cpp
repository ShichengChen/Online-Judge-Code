#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 305
typedef long long ll;
ll d[MAXN][MAXN];
char s[MAXN];
int len;
const ll MOD = 1e9;
ll dfs(int l,int r)
{
    if(d[l][r] != -1)return d[l][r];
    int ans = 0;
    for(int i = l + 1;i < r;i++)if(s[l] == s[i])
    {
        ans = (ans + dfs(l + 1,i) * dfs(i,r)) % MOD;
    }
    return d[l][r] = ans;
}
int main()
{
    while(scanf("%s",s) != EOF)
    {
        len = strlen(s);
        memset(d,-1,sizeof(d));
        for(int i = 0;i <= len;i++)d[i][i + 1] = 1;
        ll ans = dfs(0,len);
        cout << ans << endl;
    }
}
