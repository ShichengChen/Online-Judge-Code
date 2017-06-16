#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define MAXN 22
#define MOD 9999991
typedef long long LL;
int C[MAXN][MAXN];
struct BST
{
    int val[MAXN],cnt[MAXN],ch[MAXN][2];
    int sz;
    void init(){
         cnt[0] = -1;
         val[1] = 0;
         sz = 1;
    }
    int cmp(int u,int v){
        return val[u] < v ? 1 : 0;
    }
    void insert(int v)
    {
        int u = 1;
        while(val[u])
        {
            cnt[u]++;
            int r = cmp(u,v);
            if(!ch[u][r])
            {
                ch[u][r] = ++sz;
                val[ch[u][r]] = 0;
            }
            u = ch[u][r];
        }
        val[u] = v;
        ch[u][0] = ch[u][1] = cnt[u] = 0;
    }
    LL dfs(int u)
    {
        if(cnt[u] == -1)return 1;
        return ((LL)C[cnt[ch[u][0]] + 1][cnt[u]] * (dfs(ch[u][0]) % MOD)) % MOD * (dfs(ch[u][1]) % MOD) % MOD;
    }
}bst;
int main()
{
    for(int n = 1;n < MAXN;n++)
    {
        C[n - 1][n - 1] = C[0][n - 1] = 1;
        for(int m = 1;m <= n;m++)
        C[n - m][n] = C[m][n] = C[m - 1][n - 1] + C[m][n - 1];
    }
    int n,_,cur;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        bst.init();
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&cur);
            bst.insert(cur);
        }
        int ans = bst.dfs(1);
        printf("%d\n",ans);
    }
}
