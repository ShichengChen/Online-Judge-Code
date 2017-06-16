#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 100010
char s[MAXN];
int main()
{
    int _,n;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%s",&n,s);
        int ans = 0;
        s[n] = s[0];
        for(int i = 0,l = 1;i + l <= n;)
        {
            if(s[i] > s[i + l])
            {
                ans += l;
                l = 1;
                i = ans;
            }
            else if(s[i] < s[i + l])
            {
                l++;
                i = ans;
            }
            else i++;
        }
        printf("%d\n",ans);
    }
}
