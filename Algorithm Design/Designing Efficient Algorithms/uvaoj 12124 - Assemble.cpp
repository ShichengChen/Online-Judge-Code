#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
#define MAXN 1010
struct Component
{
    int price,quality;
};
vector<Component>vec[MAXN];
map<string,int>ma;
int cnt,n,m,price,quality;
string s1,s2;
int id(string & s)
{
    if(!ma.count(s))ma[s] = cnt++;
    return ma[s];
}
bool ok(int mid)
{
    int ans = 0;
    for(int i = 0;i < cnt;i++)
    {
        int minn = 1e9;
        for(int j = 0;j < vec[i].size();j++)
            if(vec[i][j].quality >= mid)
                minn = min(minn,vec[i][j].price);
        if(minn == 1e9)return false;
        ans += minn;
    }
    return ans <= m;
}
int main()
{
    int _;
    cin >> _;
    while(_--)
    {
        cin >> n >> m;
        cnt = 0;
        for(int i = 0;i < n;i++)vec[i].clear();
        ma.clear();
        for(int i = 0;i < n;i++)
        {
            cin >> s1 >> s2 >> price >> quality;
            vec[id(s1)].push_back((Component){price,quality});
        }
        int l = 0,r = 1e9;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if(ok(mid))l = mid;
            else r = mid - 1;
        }
        cout << l << endl;
    }
}
