#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define N 10010
int array[N];
int main()
{
    int _,n,x,y1,y2;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        memset(array,0,sizeof(array));
        while(n--)
        {
            scanf("%d%d%d",&x,&y1,&y2);
            array[y1]++;
            array[y2 + 1]--;
        }
        for(int i = 1;i <= N;i++)array[i] += array[i - 1];
        int maxn = 1;
        for(int i = 0;i <= N;i++)maxn = max(maxn,array[i]);
        printf("%d\n",maxn);
    }
}
