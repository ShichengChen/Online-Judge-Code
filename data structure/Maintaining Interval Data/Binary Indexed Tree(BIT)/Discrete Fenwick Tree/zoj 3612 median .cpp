#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 10010
#define lowbit(i) (i & (-i))
struct Discrete
{
    int num,newnum,id;
    char op[7];
    bool operator < (const Discrete & nu)const{
        return num < nu.num;
    }
}discrete[MAXN];
int order[MAXN],prefix[MAXN],value[MAXN],cnt;
int sum(int i)
{
    int s = 0;
    while(i)
    {
        s += prefix[i];
        i -= lowbit(i);
    }
    return s;
}
void modify(int i,int maxn,int key)
{
    while(i <= maxn)
    {
        prefix[i] += key;
        i += lowbit(i);
    }
}
int binary(int median,int cnt)
{
    int l = 1 , r = cnt;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(sum(mid) < median)l = mid + 1;
        else r = mid;
    }
    return value[l];
}
int solve(int n)
{
    int num = 0;
    for(int i = 1;i <= n;i++)
    {
        if(discrete[order[i]].op[0] == 'a')
        {
            modify(discrete[order[i]].newnum,cnt,1);
            num++;
        }
        else
        {
            if(sum(discrete[order[i]].newnum) == sum(discrete[order[i]].newnum - 1))
            {
                puts("Wrong!");
                continue;
            }
            modify(discrete[order[i]].newnum,cnt,-1);
            num--;
            if(!num)
            {
                puts("Empty!");
                continue;
            }
        }
        if(num & 1)
        {
            int ans = binary(num / 2 + 1,cnt);
            printf("%d\n",ans);
            continue;
        }
        long long ans = 1ll * binary(num / 2,cnt) + binary(num / 2 + 1,cnt);
        if(ans & 1)printf("%.1f\n",ans / 2.0);
        else printf("%d\n",ans / 2);
    }
}
int main()
{
    int _,n;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        memset(prefix,0,sizeof(prefix));
        for(int i = 1;i <= n;i++)
        {
            scanf("%s%d",discrete[i].op,&discrete[i].num);
            discrete[i].id = i;
        }
        sort(discrete + 1,discrete + 1 + n);
        cnt = 1;
        for(int i = 1;i <= n;i++)
        {
            order[discrete[i].id] = i;
            if(i != 1 && discrete[i - 1].num != discrete[i].num)cnt++;
            discrete[i].newnum = cnt;
            value[discrete[i].newnum] = discrete[i].num;
        }
        solve(n);
    }
}
