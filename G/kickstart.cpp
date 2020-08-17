#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << (x) << endl;
#define debug2(y,z) cout << '>' << #y << ':' << (y) << " " << #z << ":" <<(z) << endl;
using namespace __gnu_pbds;
typedef long long ll;
const int MAXN =5e5+20;
double d[2][MAXN],curd[2][MAXN];
int cn[MAXN];
int arr[MAXN];
int f[2];
int n;
vector<int>vec[MAXN];
double ans=0;
void dfs(int u,int dep){
    d[0][u]=d[1][u]=1;
    cn[u]=1;
    for (int v:vec[u]) {
        curd[0][dep]=curd[1][dep]=0;
        dfs(v,dep+1);
        //debug2(u,curd[0][dep])
        d[0][u]+=curd[0][dep];
        d[1][u]+=curd[1][dep];
        cn[u]+=cn[v];
    }
//    debug2(u,cn[u])
//    debug2(d[0][u],d[1][u])
    for (int i = 0; i < 2; ++i) {
        if(dep-f[i]>0){
            curd[i][dep-f[i]]+=d[i][u];
        }
//        debug(dep-f[i])
//        debug(curd[i][dep-f[i]])
    }
    ans+=d[0][u]*n+d[1][u]*n-d[0][u]*d[1][u];
}
void solve() {
    cin>>n>>f[0]>>f[1];
    ans=0;
    for (int i = 1; i <= n; ++i) {
        vec[i].clear();
    }
    for (int i = 2; i <= n; ++i) {
        cin>>arr[i];
        vec[arr[i]].push_back(i);
    }
    dfs(1,1);
    ans/=((double)n*n);
    cout << std::fixed;
    cout << setprecision(9) << ans << "\n";

}
int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    int t, i=1;
    cin >> t;
    while(t--) {
        cout << "Case #" << i << ": ";
        solve();
        ++i;
    }
    return 0;
}
/*
1 1 1
H
H H H H H H H H H H H H H H H H H H H H H H H H H H H H M
M H M H M H M H M H M H M H M H M H M H M H M H M H H M M H M
M M M M M M M M M M M M M M M M M M M M M M M M M M M M
M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M
H H H H C
 * */