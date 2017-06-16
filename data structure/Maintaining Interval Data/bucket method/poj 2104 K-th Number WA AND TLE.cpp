#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define B 1000
#define MAXN 100010
int num[MAXN],arr[MAXN];
vector<int>vec[B];
inline int read_int()
{
    char c = getchar();
    while(!isdigit(c))c = getchar();
    int x = 0;
    while(isdigit(c))
    {
        x = 10 * x + c - '0';
        c = getchar();
    }
    return x;
}
int main()
{
    int n,m,l,r,kth;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        for(int i = 0;i < n;i++)
        {
            //scanf("%d",&num[i]);
            num[i] = read_int();
            arr[i] = num[i];
            if(i % B == 0)vec[i / B].clear();
            vec[i / B].push_back(num[i]);
            if((i + 1) % B == 0)sort(vec[i / B].begin(),vec[i / B].end());
        }
        sort(num,num + n);
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d%d",&l,&r,&kth);
            int lb = 0,ub = n - 1;
            while(ub != lb)
            {
                int ll = l - 1,rr = r;///[l,r)
                int mid = lb + ub >> 1,c = 0;
                while(ll < rr && ll % B != 0)if(arr[ll++] <= num[mid])c++;
                while(ll < rr && rr % B != 0)if(arr[--rr] <= num[mid])c++;
                while(ll < rr)
                {
                    int b = ll / B;
                    c += upper_bound(vec[b].begin(),vec[b].end(),num[mid]) - vec[b].begin();
                    ll += B;
                }
                if(c < kth)lb = mid + 1;
                else ub = mid;
            }
            printf("%d\n",num[ub]);
        }
    }
}
