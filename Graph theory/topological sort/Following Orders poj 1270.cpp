#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAX 400
#define N 40
struct EGDE
{
    int v,next;
}edge[MAX];
int first[N],alph[N];
int number;
void init()
{
    number = 0;
    memset(first,-1,sizeof(first));
    memset(edge,-1,sizeof(edge));
}
void insert(int x,int y)
{
    edge[number].next = first[x];
    edge[number].v = y;
    first[x] = number++;
}
bool check(int n)
{
    for(int i = 1;i < n;i++)
        for(int index = first[alph[i]];index != -1;index = edge[index].next)
            for(int j = 0;j < i;j++)
                            if(alph[j] == edge[index].v)return 0;
    return true;
}
int main()
{
    char s1[N],s2[MAX];
    while(gets(s1) && gets(s2))
    {
        int n = 0;
        init();
        for(int i = 1;;i += 2)
        {
            alph[n++] = (int)s1[i - 1] - 'a';
            if(s1[i] == '\0')break;
        }
        for(int i = 3;;i += 4)
        {
            insert((int)s2[i - 3] - 'a',(int)s2[i - 1] - 'a');
            if(s2[i] == '\0')break;
        }
        sort(alph,alph + n);
        do
        {
                if(check(n))
                {
                    for(int i = 0;i < n;i++)
                        printf("%c",(char)alph[i] + 'a');
                    printf("\n");
                }
        }while(next_permutation(alph,alph + n));
        printf("\n");
    }
}
