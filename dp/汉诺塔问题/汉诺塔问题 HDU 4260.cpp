/*
Î»²Ù×÷£¬ << >> can not use in (1 << 60) long long scope
pow can be used
i also can use in this way ((long long)1 << 60)
*/
//HDU lld is wrong
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define N 65
long long ans;
char disk[N];
void step(int index,int rbegin,int rend)
{
    if(rbegin == rend)
    {
        if(index == 0)return;
        step(index - 1,rbegin,disk[index - 1] - 'A' + 1);
    }
    else
    {
        ans += ((long long)1 << index);
        if(index == 0)return;
        step(index - 1,6 - rbegin - rend,disk[index - 1] - 'A' + 1);
    }
}
int main()
{
    while(scanf("%s",&disk) && disk[0] != 'X')
    {
        int length = strlen(disk);
        ans = 0;
        step(length - 1,2,disk[length - 1] - 'A' + 1);
        printf("%I64d\n",ans);
        //HDU lld is wrong
    }
    return 0;
}
