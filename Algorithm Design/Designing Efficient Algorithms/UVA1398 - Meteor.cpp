#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100010
struct Terminal
{
    double p;
    bool type;
    bool operator < (const Terminal & ter)const{
        return p == ter.p ? type > ter.type : p < ter.p;
    }
}terminal[MAXN << 1];
void updata(int x,int v,int w,double & l,double & r)
{
    if(v == 0)
    {
        if(x >= w || x <= 0)r = l - 1;
    }
    else if(v > 0)
    {
        l = max(l,(double)(0 - x) / v);
        r = min(r,(double)(w - x) / v);
    }
    else
    {
        l = max(l,(double)(w - x) / v);
        r = min(r,(double)(0 - x) / v);
    }
}
int main()
{
    int _,w,h,n,x,y,a,b,cnt;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d%d",&w,&h,&n);
        cnt = 0;
        for(int i = 0;i < n;i++)
        {
            scanf("%d%d%d%d",&x,&y,&a,&b);
            double l = 0,r = 1e9;
            updata(x,a,w,l,r);
            updata(y,b,h,l,r);
            if(l < r)
            {
                terminal[cnt++] = (Terminal){l,0};
                terminal[cnt++] = (Terminal){r,1};
            }
        }
        sort(terminal,terminal + cnt);
        int ans = 0,total = 0;
        for(int i = 0;i < cnt;i++)
            if(terminal[i].type)total--;
            else ans = max(++total,ans);
        printf("%d\n",ans);
    }
}
