#include<cstdio>
int main()
{
    int _,n,cur,success;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        success = 0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&cur);
            if(cur > 1)success = 1;
        }
        if(success || n & 1)puts("poopi");
        else puts("piloop");
    }
}
