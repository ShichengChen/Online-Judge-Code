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
int packets[6];
int main()
{
   while(scanf("%d%d%d%d%d%d",&packets[0],&packets[1],&packets[2],&packets[3],&packets[4],&packets[5]) )
   {
        if(!packets[0] && !packets[1] && !packets[2] && !packets[3] && !packets[4] && !packets[5])break;
        int num = packets[5] + packets[4] + packets[3] + packets[2] / 4;
        if(packets[0])packets[0] = max(packets[0] - packets[4] * (6 * 6 - 5 * 5) , 0);
        if(packets[3] && (packets[0]|| packets[1]))
        {
            int sum = packets[3] * (6 * 6 - 4 * 4);
            if(sum > packets[1] * 4)
            {
                sum -= packets[1] * 4;
                packets[1] = 0;
                packets[0] = max(0,packets[0] - sum);
            }
            else
                 packets[1] = (packets[1] * 4 - sum) / 4;
        }
        if(packets[2] % 4)
        {
            num ++;
            int sum = 6 * 6 - packets[2] % 4 * 3 * 3;
            if(packets[1])
            {
                int cursum = sum;
                (sum - packets[1] * 4) > 0 ? (sum = sum - packets[1] * 4) : (sum = sum - (sum / 4 - 1) * 4);
                packets[1] = max(0,packets[1] - (cursum / 4 - 1));
            }
            if(packets[0])packets[0] = max(0,packets[0] - sum);
        }
        num += (packets[0] + packets[1] * 4) / (6 * 6);
        if((packets[0] + packets[1] * 4) % (6 * 6))num++;
        printf("%d\n",num);
   }
}
