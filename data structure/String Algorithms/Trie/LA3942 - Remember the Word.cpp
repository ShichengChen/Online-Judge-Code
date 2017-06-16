#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 300003
#define MAXM 101
#define ALPH 26
#define MOD 20071027
struct Trie
{
    int ch[MAXN][ALPH],val[MAXN];
    int cnt;
    void init()
    {
        cnt = 1;
        memset(ch[0],0,sizeof(ch[0]));
    }
    void insert(char * s,int v)
    {
        int u = 0 , len = strlen(s);
        for(int i = 0;i < len;i++)
        {
            if(!ch[u][s[i] - 'a'])
            {
                memset(ch[cnt],0,sizeof(ch[cnt]));
                val[cnt] = 0;
                ch[u][s[i] - 'a'] = cnt++;
            }
            u = ch[u][s[i] - 'a'];
        }
        val[u] = v;
    }
}trie;
char word[MAXN] , cur[MAXM];
int dp[MAXN];
int main()
{
    int kcas = 1;
    while(scanf("%s",word + 1) != EOF)
    {
        int n;
        scanf("%d",&n);
        trie.init();
        memset(dp,0,sizeof(dp));
        while(n--)
        {
            scanf("%s",cur);
            trie.insert(cur,1);
        }
        dp[strlen(word + 1)] = 1;
        for(int i = strlen(word + 1);i;i--)
        {
            int u = 0;
            for(int j = 0;word[i + j];j++)
            {
                u = trie.ch[u][word[i + j] - 'a'];;
                if(!u)break;
                if(trie.val[u])
                    dp[i - 1] = (dp[i - 1] + dp[i + j]) % MOD;
            }
        }
        printf("Case %d: %d\n",kcas++,dp[0]);
    }
}
