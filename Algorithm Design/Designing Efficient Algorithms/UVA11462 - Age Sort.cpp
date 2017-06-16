#include<iostream>
#include<cstring>
#include<cstdio>
#include<cctype>
using namespace std;
#define MAXN 102
int c[MAXN],buf[11];
inline int read_int()
{
    char c = getchar();
    while(!isdigit(c))c = getchar();
    int x = 0;
    while(isdigit(c))
    {
        x = 10 * x + c - '0';
        c = getchar();
    }
    return x;
}
inline void write_int(int i)
{
    int len = 0;
    if(i == 0)buf[len++] = 0;
    while(i)
    {
        buf[len++] = i % 10;
        i /= 10;
    }
    for(int i = len - 1;i >= 0;i--)putchar('0' + buf[i]);
}
int main()
{
    int n;
    while(n = read_int())
    {
        memset(c,0,sizeof(c));
        bool first = 1;
        for(int i = 0;i < n;i++)
            c[read_int()]++;
        for(int i = 1;i <= 100;i++)
            for(int j = 0;j < c[i];j++)
            {
                if(!first)putchar(' ');
                first = 0;
                write_int(i);
            }
        putchar('\n');

    }
}
