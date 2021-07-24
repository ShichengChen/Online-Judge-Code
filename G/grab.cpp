#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)
template<class T> bool umin(T& a, const T& b) {return b<a?a=b, 1:0;}
template<class T> bool umax(T& a, const T& b) {return a<b?a=b, 1:0;}
vt<int> solution(vt<int>&arr){
    vt<vt<int>>vec(sz(arr)+1);
    vt<int>vis(sz(arr)+1,0);
    int cap=0;
    FOR(sz(arr)) {
        if(i==arr[i])cap=i;
        else{
            vec[i].push_back(arr[i]);
            vec[arr[i]].push_back(i);
        }
    }
    queue<pair<int,int>>q;
    q.push({cap,0});vis[cap]=1;
    vt<int>ans(sz(arr)-1,0);
    while(sz(q)){
        auto cur=q.front();q.pop();
        int u=cur.first,d=cur.second;
        for (int v:vec[u]) {
            if(!vis[v]) {
                q.push({v,d+1});
                ans[d]++;
                vis[v]=1;
            }
        }
    }
    return ans;
}
int main(){
    //vt<int>v={-1,0,1,2,-3,5,0,6,-10};
}