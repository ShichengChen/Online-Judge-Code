#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
vector<pii>vec;
#define MAXN 1e7 + 5
void print_ans(int l,int r)
{
    printf("%d",r - l + 1);
    for(int i = l;i < r;i++)
        printf(" %d",i);
    printf(" %d\n",r);
}
int main()
{
    ll n;
    while(scanf("%lld",&n) != EOF)
    {
        ll cur = 0;
        vec.clear();
        for(ll i = 1,j = 1;i * i <= n;i++)
        {
            //cout << i << " i j " << j << endl;
            cur += i * i;
            while(cur > n)
            {
                cur -= j * j;
                j++;
            }
            if(cur == n)vec.push_back(pii((int)j,(int)i));
        }
        printf("%d\n",vec.size());
        for(int i = 0;i < vec.size();i++)
            print_ans(vec[i].first,vec[i].second);
    }
}
