#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
#define MAX 100000
multiset<int>:: iterator it;
multiset<int>gather;
int main()
{
    int t; scanf("%d",&t);
    while(t--)
    {
        int n; scanf("%d",&n);
        while(n--)
        {
            int cur;scanf("%d",&cur);
            gather.insert(cur);
        }
        int one,two,num,ans = 0;
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
        printf("%d\n",ans);
    }
}
