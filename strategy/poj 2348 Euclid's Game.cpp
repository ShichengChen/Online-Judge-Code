#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int cnt,a,b;
    while(scanf("%d%d",&a,&b) && a | b)
    {
        cnt = 1;
        while(1)
        {
            if(a < b)swap(a,b);
            if(a % b == 0)break;
            if(a - b > b)break;
            a -= b;
            cnt++;
        }
        if(cnt & 1)puts("Stan wins");
        else puts("Ollie wins");
    }
}
