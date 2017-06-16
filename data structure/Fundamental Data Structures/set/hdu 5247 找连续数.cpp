#include<cstdio>
#include<set>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const int MAXN = 10005;
set<LL>se;
set<LL> :: iterator it1,it2;
int n,m;
int ans[MAXN];
LL arr[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++)
        scanf("%I64d",&arr[i]);
    for(int j = 0;j < n;j++)
    {
        se.clear();
        for(int i = 0;i < 1000 && i + j < n;i++)
        {
            if(!se.count(arr[j + i]))
                se.insert(arr[j + i]);
            else
                break;
            int minn = *(se.begin());
            int maxn = *(se.rbegin());
            if(maxn - minn == se.size() - 1)
                ans[i]++;
        }
    }
    printf("Case #1:\n");
    while(m--)
    {
        int k;
        scanf("%d",&k);
        printf("%d\n",ans[k - 1]);
    }
}
