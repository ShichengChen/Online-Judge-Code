#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
#define MAXN 1000005
int n,p,k;
struct Node
{
    ll s;
    bool operator < (const Node & a)const{
        if(s % p == a.s % p)return s < a.s;
        return s % p < a.s % p;
    }
}node[MAXN];
ll deque[MAXN];
int main()
{
    int _;
    for(int kcas = scanf("%d",&_);kcas <= _;kcas++)
    {
        scanf("%d%d%d",&n,&p,&k);
        bool success = false;
        for(int i = 1;i <= n;i++)
        {
            scanf("%I64d",&node[i].s);
            if(node[i].s == 0)success = true;
            node[i].s += node[i - 1].s;
        }
        sort(node,node + n + 1);
        ll maxn = 0,ans = 0;
        int tail = 0,head = 0;
        for(int i = 1,j = 0;i <= n;i++)
        {
            while(tail != head && deque[tail - 1] > node[i - 1].s)
                tail--;
            deque[tail++] = node[i - 1].s;
            while(tail != head && deque[head] % p + k < node[i].s % p)
                head++;
            if(head != tail)ans = max(ans,node[i].s - deque[head]);

            while(j < i && node[j].s % p + p - node[i].s % p <= k)
            {
                maxn = max(maxn,node[j].s);
                j++;
            }
            ans = max(ans,maxn - node[i].s);
        }
        if(!ans && !success)printf("Case %d: -1\n",kcas);
        else printf("Case %d: %I64d\n",kcas,ans / p);
    }
}
