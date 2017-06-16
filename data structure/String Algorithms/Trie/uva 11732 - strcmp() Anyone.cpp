#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 4000010
#define MAXL 1010
struct Trie
{
    int head[MAXN],next[MAXN],val[MAXN],cnt;
    char alph[MAXN];
    long long ans;
    void init(){
        ans = head[0] = val[0] = next[0] = 0;
        cnt = 1;
    }
    void insert(const char * s){
        int u = 0,ind , len = strlen(s);
        val[0]++;
        for(int i = 0;i <= len;i++)
        {
            for(ind = head[u];ind;ind = next[ind])
                if(alph[ind] == s[i])break;
            if(!ind)
            {
                next[cnt] = head[u];
                alph[cnt] = s[i];
                val[cnt] = head[cnt] = 0; // init new node
                ind = cnt;
                head[u] = cnt++;
            }
            val[ind]++;
            ans += (val[u] + val[ind] - 2);
            u = ind;
        }
    }
}trie;
char word[MAXL];
int main()
{
  int kase = 1,n;
  while(scanf("%d",&n) && n)
  {
    trie.init();
    for(int i = 0;i < n;i++)
    {
      scanf("%s",word);
      trie.insert(word);
    }
    printf("Case %d: %lld\n",kase++,trie.ans);
  }
}
