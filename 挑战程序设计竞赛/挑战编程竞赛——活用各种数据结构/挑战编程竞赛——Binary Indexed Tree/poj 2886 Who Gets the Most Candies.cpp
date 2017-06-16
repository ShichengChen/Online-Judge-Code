#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAXN 500005
#define LOG 18
#define lowbit(i) (i & -i)
const int b[] = {1,2,3,4,6,8,9,10,12,16,18,20,24,30,32,36,40,48,60,
            64,72,80,84,90,96,100,108,120,128,144,160,168,180,
            192,200,1314521};
const int H[] = {
    1,2,4,6,12,24,36,48,60,120,180,240,360,
    720,840,1260,1680,2520,5040,7560,10080,15120,20160,25200,
    27720,45360,50400,55440,83160,110880,166320, 221760,
    277200, 332640, 498960, 554400, 665280};
int id[MAXN],prefix[MAXN],n,m;
char name[MAXN][15];
void add(int i,int v)
{
    for(;i <= n;i += lowbit(i))
        prefix[i] += v;
}
int sum(int i)
{
    int ans = 0;
    for(;i;i -= lowbit(i))
        ans += prefix[i];
    return ans;
}
int binary(int val)
{
    int curi = 0;
    for(int i = LOG;i >= 0;i--)
    {
        int ind = 1 << i;
        if(curi + ind > n || prefix[ind + curi] >= val)continue;
        val -= prefix[ind + curi];
        curi += ind;
    }
    return curi + 1;
}
int main()
{
    while(scanf("%d%d",&n,&m) != EOF)
    {
        m--;
        memset(prefix,0,sizeof(prefix));
        for(int i = 1;i <= n;i++)
        {
            scanf("%s %d",&name[i],&id[i]);
            add(i,1);
        }
        int ind = upper_bound(H,H + 37,n) - H;
        int total = n,ans;
        for(int i = 0;i < H[ind - 1];i++)
        {
            ans = binary(m + 1);
            add(ans,-1);
            if(!(--total))break;
            m = sum(ans);
            if(id[ans] > 0)
                m = (m - 1 + id[ans] + total) % total;
            else
                m = ((m + id[ans]) % total + total) % total;
        }
        printf("%s %d\n",name[ans],b[ind - 1]);
    }
}
