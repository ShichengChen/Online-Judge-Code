#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 400005
#define ALPH 26
#define MAXL 45
struct Trie
{
    int alph[ALPH],ch[MAXN][ALPH],cnt;
    void init()
    {
        memset(ch[0],0,sizeof(ch[0]));
        cnt = 1;
        memset(alph,0,sizeof(alph));
    }
    void insert(char * s)
    {
        int u = 0,len = strlen(s);
        for(int i = 0;i < len;i++)
        {
            int ind = s[i] - 'a';
            if(!ch[u][ind])
            {
                memset(ch[cnt],0,sizeof(ch[cnt]));
                ch[u][ind] = cnt++;
                if(i)alph[ind]++;
            }
            u = ch[u][ind];
        }
    }
}pre,suf;
char s[MAXL];
bool vis[ALPH];
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        pre.init() , suf.init();
        memset(vis,0,sizeof(vis));
        for(int i = 0;i < n;i++)
        {
            scanf("%s",s);
            int len = strlen(s);
            if(len == 1)vis[s[0] - 'a'] = true;
            pre.insert(s);
            reverse(s,s + len);
            suf.insert(s);
        }
        long long ans = (long long)(pre.cnt - 1) * (suf.cnt - 1);
        for(int i = 0;i < ALPH;i++)
            ans -= (long long)pre.alph[i] * suf.alph[i] - vis[i];
        printf("%lld\n",ans);
    }
}
