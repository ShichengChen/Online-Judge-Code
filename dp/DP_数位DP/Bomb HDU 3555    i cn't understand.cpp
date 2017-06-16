#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long LL;
#define MAXN 20
int reverse[MAXN];
LL dp[MAXN][3];
LL dfs(int pos,int flag,bool limit)
{
    if(pos == -1)return flag == 2;
    if(!limit && dp[pos][flag] != -1)return dp[pos][flag];
    int end = limit ? reverse[pos] : 9;
    LL ans = 0;
    for(int i = 0; i <= end;i++)
    {
        int have = flag;
		if (flag == 1 && i == 9)have = 2;
		if (flag == 0 && i == 4)have = 1;
		if (flag == 1 && i != 4 && i != 9)have = 0;
		ans += dfs(pos - 1,have,limit && i == end);
    }
    if(!limit)return dp[pos][flag] = ans;
    else return ans;
}
LL trans(LL n)
{
    int pos = 0;
    while(n)
    {
        reverse[pos++] = n % 10;
        n /= 10;
    }
    return dfs(pos - 1,0,1);
}
int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        LL num;
        //scanf("%I64d",&num);
        cin >> num;
        memset(dp,-1,sizeof(dp));
        LL ans = trans(num);
        cout << ans << endl;
        //printf("%I64d\n",ans);
    }
}
