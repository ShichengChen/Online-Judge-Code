#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
#define MAXN 100005
int n,k,_,que1[MAXN],que2[MAXN],num[MAXN];
LL ans;
int main()
{
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&k);
        for(int i = 1;i <= n;i++)
            scanf("%d",&num[i]);
        ans = 0;
        int head1 = 0,tail1 = 0,head2 = 0,tail2 = 0;
        for(int i = 1,j = 1;i <= n;i++)
        {
            while(head1 < tail1 && )
            ans += (i - j + 1);
        }
        cout << ans << endl;
    }
}
