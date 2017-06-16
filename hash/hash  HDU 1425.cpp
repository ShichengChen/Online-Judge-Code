#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define N 500000
#define MAXN 1001000
int array[MAXN];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        memset(array,0,sizeof(array));
        int cur,maxn = 0;
        for(int i = 0;i < n;i ++)
        {
              scanf("%d",&cur);
              maxn = max(maxn,cur + N);
              array[cur + N]++;
        }
        int num = maxn;
        for(int i = 0;i < m;i ++)
        {
            while(!array[num])num--;
            if(i == m - 1)printf("%d",num - N);
            else printf("%d ",num - N);
            array[num]--;
        }
       printf("\n");
    }
    return 0;
}
