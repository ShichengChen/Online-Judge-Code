#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int _,n,id;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&id);
        printf("%I64d\n",(long long)1 << n - id);
    }
}
