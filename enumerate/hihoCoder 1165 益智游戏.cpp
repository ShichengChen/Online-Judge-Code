#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
typedef pair<int,int>pii;
#define MAXN 100010
#define MAXM 205
#define MAXP 9594
int n,prime[MAXN],map[MAXN],arr[MAXM][MAXP];
bool nPrime[MAXN];
pii node[MAXN];
int Prime()
{
    int cnt = 0;
    for(int i = 2;i < MAXN;i++)if(!nPrime[i])
    {
        prime[cnt++] = i;
        for(LL j = (LL)i * i;j < MAXN;j += i)
            nPrime[j] = true;
    }
    return cnt;
}
int solve(int len1,int len2,int cnt)
{
    int ans = 0;
    for(int i = max(cnt - len1,0),ii = 0;i < cnt;i++,ii++)
    {
        int cur = node[i].second;
        for(int j = 0;j < len2;j++)
        {
            while(cur % prime[j] == 0)
            {
                arr[ii][j]++;
                cur /= prime[j];
            }
        }
        for(int j = max(cnt - len1,0),jj = 0;j <= i;j++,jj++)
        {
            int temp = 1;
            for(int q = 0;q < len2;q++)
                temp *= (arr[ii][q] + arr[jj][q] + 1);
            ans = max(ans,temp);
        }
    }
    return ans;
}
int main()
{
    int m = Prime();
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        int num,cnt = 0;
        scanf("%d",&num);
        if(map[num])continue;
        for(int k = 1;k * k <= num;k++)
            if(num % k == 0)
                cnt += (k * k == num ? 1 : 2);
        map[num] = cnt;
    }
    int cnt = 0,ans;
    for(int i = 1;i < MAXN;i++)if(map[i])
        node[cnt++] = pii(map[i],i);
    sort(node,node + cnt);
    ans = solve(26,m,cnt);
    printf("%d\n",ans);
}
