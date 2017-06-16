#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<climits>
#include<string>
using namespace std;
#define N 40000
#define INF (1 << 29)
int list[6],sum;
bool success;
bool dfs()
{
    for(int i = 1;i <= 6;i ++)
    {
        if(list[i - 1] && sum - i >= 0)
        {
            sum -= i;   list[i - 1]--;
            if(!dfs())
            {
                sum += i;  ++list[i - 1];
                return 1;
            }
            sum += i;  ++list[i - 1];
        }
    }
    return 0;
}
int main()
{
    string ss;
    while(cin >> ss)
    {
        cout << ss << " ";
        int length = ss.length();
        for(int i = 0;i < 6;i++)list[i] = 4;
        sum = 31;
        for(int i = 0;i < length;i++)
        {
            sum -= (int)(ss[i] - '0');
            list[(int)ss[i] - '1']--;
        }
        if(dfs())cout << (char)('A' + (length % 2))<< endl;
        else cout << (char)('A' + ((length + 1) % 2)) << endl;
    }
    return 0;
}
