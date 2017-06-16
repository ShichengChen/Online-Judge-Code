#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 1000005
int h_number[MAXN],s[MAXN];
void get_prime()
{
    for(int i = 5;i < MAXN;i += 4)
        for(int j = 5;j < MAXN && i * j < MAXN;j += 4)
        {
            if(!h_number[i] && !h_number[j])
                h_number[i * j] = 1;
            else h_number[i * j] = -1;
        }
    int cnt = 0;
    for(int i = 25;i < MAXN;i++)
    {
        if(h_number[i] == 1)
            cnt++;
        s[i] = cnt;
    }
}
int main()
{
    get_prime();
    int n;
    while(scanf("%d",&n),n)
        printf("%d %d\n",n,s[n]);
}
