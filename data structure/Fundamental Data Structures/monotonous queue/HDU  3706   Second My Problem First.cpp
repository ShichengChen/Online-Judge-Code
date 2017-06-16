#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<climits>
#include<string>
#include<cmath>
#include<deque>
using namespace std;
#define MAX 1000005
#define MIN 1e-9
#define INF (1 << 29)
deque<int>que;
void check_push(int prevsum,int A,int B,int sum)
{
    if(!que.empty() && que.front() == prevsum)que.pop_front();
    while(!que.empty() && que.back() >= sum)
        que.pop_back();
    que.push_back(sum);
}
int main()
{
   int A,B,n;
   while(scanf("%d%d%d",&n,&A,&B) != EOF)
   {
        int T = 1,prevsum = -1,sum = 1;
        while(!que.empty())que.pop_back();
        for(int i = 1;i <= n;i++)
        {
                    int minn = INT_MAX;
                    if(i - A - 1 == 0)prevsum = 1;
                    if(i - A - 1 >= 0)prevsum = (long long)sum * A % B;
                    sum = (long long)sum * A % B;
                    check_push(prevsum,A,B,sum);
                    T = (long long)T * (que.front()) % B;
        }
        printf("%d\n",T);
   }
}
