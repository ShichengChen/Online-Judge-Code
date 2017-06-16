#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int k,p;
    while(scanf("%d%d",&k,&p) != EOF)
    {
        if((k / (p - 1)) % 2 == 0)
            puts("NO");
        else puts("YES");
    }
}
