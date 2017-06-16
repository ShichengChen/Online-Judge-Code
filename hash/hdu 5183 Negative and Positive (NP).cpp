#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long LL;
#define MAXN 1000005
#define MOD 1000007
LL s[MAXN],n,k;
vector<LL>vec[MOD];
void insert(LL x)
{
    LL val = x % MOD;
    if(val < 0)val += MOD;
    vec[val].push_back(x);
}
bool find(LL x)
{
    LL val = x % MOD;
    if(val < 0)val += MOD;
    for(int i = 0;i < vec[val].size();i++)
        if(vec[val][i] == x)return true;
    return false;
}
inline bool run()
{
    for(int i = 0;i < MOD;i++)vec[i].clear();
    for(int i = n;i >= 0;i--)
    {
        if(i & 1)
        {
            if(find(s[i] - k))return true;
        }
        else
        {
            if(find(s[i] + k))return true;
        }
        insert(s[i]);
    }
    return false;
}
int main()
{
    int _;
    scanf("%d",&_);
    for(int kcas = 1;kcas <= _;kcas++)
    {
        printf("Case #%d: ",kcas);
        scanf("%I64d%I64d",&n,&k);
        for(int i = 1;i <= n;i++)
        {
            scanf("%I64d",&s[i]);
            if(i & 1)s[i] += s[i - 1];
            else s[i] = s[i - 1] - s[i];
        }
        if(run())puts("Yes.");
        else puts("No.");
    }
}
