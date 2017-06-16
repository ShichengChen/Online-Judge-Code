#include<cstdio>
int main()
{
    int _,n;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        printf("%I64d\n",(long long)2 * n * n - n + 1);
    }
}
