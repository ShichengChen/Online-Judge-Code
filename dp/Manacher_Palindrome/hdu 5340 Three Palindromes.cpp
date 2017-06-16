#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
#define MAXN 20005
#define INF 0x3f3f3f3f
int _,d[MAXN << 1],len,pre[MAXN << 1],suf[MAXN << 1];
char cs[MAXN],s[MAXN << 1];
void Manacher()
{
    len = strlen(cs);
    s[0] = '$';
    for(int i = 0;i <= len;i++)
    {
        s[i << 1 | 1] = '#';
        s[(i << 1) + 2] = cs[i];
    }
    int idx = 0,maxn = 0;
    for(int i = 1;i <= (len << 1);i++)
    {
        if(maxn > i)
            d[i] = min(d[idx * 2 - i],maxn - i);
        else
            d[i] = 1;
        for(;s[i + d[i]] == s[i - d[i]];d[i]++);
        if(i + d[i] > maxn)
        {
            maxn = d[i] + i;
            idx = i;
        }
    }
}
bool solve()
{
    int cnt1 = 0,cnt2 = 0;
    for(int i = 2;i <= (len << 1);i++)
    {
        if(d[i] == i)
            pre[cnt1++] = i * 2 - 1;
        if(d[i] + i == (len << 1) + 2)
            suf[cnt2++] = i - d[i] + 1;
    }
    //for(int i = 0;i < cnt2;i++)cout << suf[i] << " pre ";
    //cout << endl;
    for(int i = 0;i < cnt1;i++)
        for(int j = 0;j < cnt2;j++)if(pre[i] + 1 < suf[j])
        {
            //cout << pre[i] << " p s " << suf[i] << endl;
            int gap = suf[j] - pre[i];
            if(gap == 2 && s[pre[i] + 1] != '#')return true;
            if(d[gap / 2 + pre[i]] * 2 >= gap)return true;
        }
    return false;
}
int main()
{
    scanf("%d",&_);
    while(_--)
    {
        scanf("%s",cs);
        Manacher();
        //for(int i = 1;i <= 6;i++)cout << d[i] << " ";
        if(solve())puts("Yes");
        else puts("No");
    }

}
