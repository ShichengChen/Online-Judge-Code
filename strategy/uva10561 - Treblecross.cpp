#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 206
int SG[MAXN],ans[MAXN],cnt;
bool vis[MAXN];
char s[MAXN];
void find_SG()
{
    int cur;
    for(int i = 1;i < MAXN;i++)
    {
        memset(vis,0,sizeof(vis));
        for(int ind = 1;ind <= i;ind++)
        {
            cur = SG[max(ind - 3,0)] ^ SG[max(i - ind - 2,0)];
            vis[cur] = true;
        }
        for(cur = 0;vis[cur];cur++);
        SG[i] = cur;
    }
}
bool win(int ind,int len)
{
    if(s[ind + 1] == 'X' && s[ind + 2] == 'X')return true;
    if(s[ind + 1] == 'X' && s[ind - 1] == 'X')return true;
    if(ind != 1 && s[ind - 1] == 'X' && s[ind - 2] == 'X')return true;
    return false;
}
bool towin(int len)
{
    for(int i = 1;i <= len;i++)if(win(i,len))return false;
    int cur = 0,nim = 0;
    for(int i = 1;i <= len;i++)
    {
        if(s[i] == 'X' || s[i + 1] == 'X' || s[i + 2] == 'X' ||
           s[i - 1] == 'X' || (i != 1 && s[i - 2] == 'X'))
        {
            nim ^= SG[cur];
            cur = 0;
        }
        else cur++;
    }
    nim ^= SG[cur];
    if(!nim)return true;
    return false;
}
bool solve(int len)
{
    s[0] = s[len + 1] = s[len + 2] = '.' , cnt = 0;
    for(int i = 1;i <= len;i++)if(win(i,len))ans[cnt++] = i;
    if(cnt)return true;
    for(int i = 1;i <= len;i++)
    {
        if(s[i] == 'X')continue;
        s[i] = 'X';
        if(towin(len))ans[cnt++] = i;
        s[i] = '.';
    }
    if(cnt)return true;
    return false;
}
int main()
{
    find_SG();
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%s",s + 1);
        if(solve(strlen(s + 1)))
        {
            puts("WINNING");
            for(int i = 0;i < cnt;i++)
            {
                if(i == 0)printf("%d",ans[i]);
                else printf(" %d",ans[i]);
            }
            puts("");
        }
        else puts("LOSING\n");
    }
}
