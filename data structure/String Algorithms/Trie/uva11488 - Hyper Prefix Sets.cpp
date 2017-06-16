#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 10000000
#define MAXL 202
int val[MAXN],ch[MAXN][2];
int cnt,maxn;
void init()
{
    maxn = val[0] = ch[0][0] = ch[0][1] = 0;
    cnt = 1;
}
void insert(const char * s)
{
    val[0]++;
    int len = strlen(s) , u = 0;
    for(int i = 0;i < len;i++)
    {
        int ind = s[i] - '0';
        if(!ch[u][ind])
        {
            ch[u][ind] = cnt;
            val[cnt] = ch[cnt][0] = ch[cnt][1] = 0;//init new nalote
            cnt++;
        }
        u = ch[u][ind];
        val[u]++;
        maxn = max(maxn,val[u] * (i + 1));
    }
}
char s[MAXL];
int main()
{
    int _,n;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        init();
        while(n--)
        {
            scanf("%s",s);
            insert(s);
        }
        printf("%d\n",maxn);
    }
}
