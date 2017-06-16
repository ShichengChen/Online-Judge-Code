#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 1000002
char s[MAXN];
int next[MAXN];
int main()
{
    int n,_ = 1;
    while(scanf("%d",&n),n)
    {
        scanf("%s",s + 1);
        printf("Test case #%d\n",_++);
        int len = strlen(s + 1);
        next[1] = 0;
        for(int i = 2,j;i <= len;i++)
        {
            j = next[i - 1];
            while(j && s[j + 1] != s[i])j = next[j];
            next[i] = (s[i] == s[j + 1] ? j + 1 : 0);
            if(next[i] && next[i] % (i - next[i]) == 0)
                printf("%d %d\n",i,i / (i - next[i]));
        }
        puts("");
    }
}
