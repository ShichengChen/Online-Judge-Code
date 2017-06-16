#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
#define MAX 20000
multiset<long long>:: iterator it;
multiset<long long>gather;
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        while(n--)
        {
            int cur;scanf("%d",&cur);
            gather.insert((long long)cur);
        }
        long long one,two,ans = 0;
        while(1)
        {
            if(gather.size() == 1)
            {
                gather.clear();
                break;
            }
            one = *(gather.begin());
            it = gather.begin(); it ++;
            gather.erase(gather.begin(),it);
            two = *(gather.begin());
            it = gather.begin(); it ++;
            gather.erase(gather.begin(),it);
            ans += (one + two);
            gather.insert(one + two);
        }
        printf("%lld\n",ans);
    }
}
