#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
#define MAXN 5000500
#define lowbit(i) ((i) & (-(i)))
#define MOD 998244353
struct Trie
{
    int ch[MAXN][2],val[MAXN],cnt;
    LL ans;
    void init()
    {
        ans = cnt = val[0] = ch[0][0] = ch[0][1] = 0;
    }
    void insert(int v)
    {
        val[0]++;
        int deep = 0,num = val[0],next = 0;
        for(int i = 0;i < 30;i++)
        {
            int c = v & 1;
            if(!ch[next][c])
            {
                ch[next][c] = ++cnt;
                val[cnt] = ch[cnt][0] = ch[cnt][1] = 0;
            }
            val[ch[next][c]]++;
            deep++;
            ans += ((num - val[ch[next][c]]) << deep);
            ans %= MOD;
            next = ch[next][c];
            v >>= 1;
            num = val[next];
        }
    }
}trie;
int main()
{
    int _,n,cur;
    for(int kcas = scanf("%d",&_);kcas <= _;kcas++)
    {
        trie.init();
        for(int i = scanf("%d",&n);i <= n;i++)
        {
            scanf("%d",&cur);
            trie.insert(cur);
        }
        printf("Case #%d: %I64d\n",kcas,trie.ans);
    }
}
