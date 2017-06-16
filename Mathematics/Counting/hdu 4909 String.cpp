#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 20005
#define MAXM 67108864
char s[MAXN];
int hash,map[MAXM];
void clear(int l,int r)
{
    int bit = map[0] = 0;
    for(int i = l;i < r;i++)if(s[i] != '?')
    {
        bit ^= 1 << (s[i] - 'a');
        map[bit] = 0;
    }
}
int run(int l,int r)
{
    clear(l,r);
    int ans = hash = 0;
    map[0] = 1;
    for(int i = l;i < r;i++)
    {
        if(s[i] != '?')
            hash ^= 1 << s[i] - 'a';
        ans += map[hash];
        map[hash]++;
    }
    return ans;
}
int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%s",s);
        int len = strlen(s),pos;
        for(pos = 0;pos < len;pos++)
            if(s[pos] == '?')break;
        int ans = run(0,len);
        int cut = run(0,pos) + run(pos + 1,len);
        for(int i = 0;i < 26;i++)
        {
            s[pos] = i + 'a';
            ans += run(0,len);
        }
        printf("%d\n",ans - 26 * cut);
    }
}
