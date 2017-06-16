#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 1000010
char s[MAXN];
int next[MAXN];
int main()
{
    int len,kcase = 1;
    while(scanf("%d",&len) , len)
    {
        scanf("%s",s);
        next[0] = next[1] = 0;
        printf("Test case #%d\n",kcase++);
        for(int i = 1,j = 0;i < len;i++)
        {
            j = next[i];
            while(j && s[j] != s[i])j = next[j];
            next[i + 1] = (s[i] == s[j] ? j + 1 : 0);
            if(next[i + 1] && (i + 1) % (i + 1 - next[i + 1]) == 0)
                printf("%d %d\n",i + 1,(i + 1) / (i + 1 - next[i + 1]));
        }
        puts("");
    }
}
