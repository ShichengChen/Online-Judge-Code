#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<map>
using namespace std;
int dice[24][6] = {{0,1,2,4,3,5},{5,3,4,2,1,0},{1,2,0,3,5,4},{4,0,2,5,3,1},{2,0,1,5,4,3},{3,4,5,1,0,2},
                   {0,2,4,3,1,5},{5,4,2,1,3,0},{1,0,3,5,2,4},{4,2,5,3,0,1},{2,1,5,4,0,3},{3,5,1,0,4,2},
                   {0,4,3,1,2,5},{5,2,1,3,4,0},{1,3,5,2,0,4},{4,5,3,0,2,1},{2,5,4,0,1,3},{3,1,0,4,5,2},
                   {0,3,1,2,4,5},{5,1,3,4,2,0},{1,5,2,0,3,4},{4,3,0,2,5,1},{2,4,0,1,5,3},{3,0,4,5,1,2}};
#define MAXN 7
#define F(i,n) for(int i = 0;i < (n);i++)
vector<string>vec[MAXN];
map<string,int>ma;
int n,trace[MAXN],ans;
string s;
void dfs(int level)
{
    if(level == n)
    {
        ma.clear();
        int cur = 0;
        F(i,6)
        {
            int maxn = 0;
            F(j,n)
            {
                int ith = dice[trace[j]][i];
                ma[vec[j][ith]]++;
                maxn = max(maxn,ma[vec[j][ith]]);
            }
            cur += n - maxn;
            ma.clear();
        }
        ans = min(ans,cur);
    }
    else F(i,24)
    {
        trace[level] = i;
        dfs(level + 1);
    }
}
int main()
{
    while(cin >> n && n)
    {
        F(i,n)vec[i].clear();
        F(i,n)F(j,6)
        {
            cin >> s;
            vec[i].push_back(s);
        }
        ans = 0x3f3f3f3f;
        trace[0] = 0;
        dfs(1);
        cout << ans << endl;
    }
}
