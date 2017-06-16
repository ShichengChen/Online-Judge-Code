#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define check(i) (i != 1 && i != 2)
#define done(a,b,c,d) (b == c && max(a,d) <= b && b <= a + d)
inline bool _check_(int a,int b,int c,int d)
{
    for(int i = max(a - b,0);i <= a && (a - i) + d >= b;i++)
        for(int j = d - b;j <= d && (a - i) + (d - j) >= b;j++)
            if(check(i) && check(j) && done(a - i,b,c,d - j))
                return true;
    return false;
}
inline bool run(int a,int b,int c,int d)
{
    if(done(a,b,c,d))return true;
    if(a > 2 && b > 2 && c > 2 && d > 2)return true;
    if(b > c)swap(b,c);
    if(a > d)swap(a,d);
    for(int i = max(b - (a + d),0);i <= b;i++)
        if(check(i) && check(c - b + i))
            if(done(a,b - i,b - i,d) || _check_(a,b - i,b - i,d))
                return true;
    return false;
}
int main()
{
    int _,a,b,c,d;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        bool ans = run(a,b,c,d);
        if(ans)puts("Yes");
        else puts("No");
    }
}
