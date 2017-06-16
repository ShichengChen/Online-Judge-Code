#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<map>
#include<iterator>
using namespace std ;
typedef pair<int,int>p;
map<int,int>F;
#define ind first
#define val second
#define INF 1000000001
int ans;
void solve(int mid,int v)
{
    if(!v)return;
    map<int,int> :: iterator l,r,it;
    if(F[mid] == 0)
    {
        it = l = r = F.find(mid);
        l--, r++;
        if(l -> val > 0 && r -> val < 0)
        {
            if(v > 0)ans -= (mid - l -> ind);
            else ans -= (r -> ind - mid);
        }
        else if(l -> val > 0 && r -> val > 0 && v < 0)
            ans += (mid - l -> ind);
        else if(l -> val < 0 && r -> val < 0 && v > 0)
            ans += (r -> ind - mid);
        F[mid] = v;
    }
    else
    {
        it = l = r = F.find(mid);
        l--,r++;
        if(it == F.begin() || r == F.end())return;
        if(l -> val > 0 && r -> val < 0)
        {
            if(it -> val > 0)ans += (mid - l -> ind);
            else ans += (r -> ind - mid);
        }
        else if(l -> val > 0 && r -> val > 0 && it -> val < 0)
            ans -= (mid - l -> ind);
        else if(l -> val < 0 && r -> val < 0 && it -> val > 0)
            ans -= (r -> ind - mid);
        int cur = it -> val + v;
        F.erase(it);
        solve(mid,cur);
    }
}
int main ()
{
    int n,m,l,r,v;
    while(~scanf("%d%d%d",&n,&m,&r))
    {
        ans = 0;
        F.clear();
        F[1] = -INF;F[n + 1] = +INF;
        while(m--)
        {
            scanf("%d%d%d",&l,&r,&v);
            l ^= ans;
            r ^= ans;
            v ^= ans;
            solve(l,v);
            solve(r + 1,-v);
            printf("%d\n",ans);
        }
    }
}
