#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 25
int arr[MAXN],num[MAXN];
int run(int from)
{
    memset(num,0,sizeof(num));
    int have = 0,ans = 0;
    for(int i = from;i <= 20;i++)
    {
        have += num[i];
        if((arr[i] + have) % 2)
        {
            num[i + 3]--;
            have++;
            ans++;
        }
    }
    return ans;
}
int main()
{
    arr[0] = 1;
    for(int i = 1;i <= 20;i++)
        scanf("%d",&arr[i]);
    int ans = min(run(0),run(1));
    printf("%d\n",ans);
}
