#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
typedef long long ll;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define debug2(y,z) cout << '>' << #y << ':' << y << " " << #z << ":" <<z << endl;
const int MAXN =2e5+50;
const int LOGMAXN = 18;
ll const MOD=1e9+7;
int arr[MAXN];
int n,m;
vector<int>vec[MAXN];
int depth[MAXN],fa[MAXN][LOGMAXN];
struct LCA_DIS{
    void build(int u,int f){
        depth[u]=depth[f]+1;
        fa[u][0]=f;
        for (int i = 1; i < LOGMAXN; ++i) {
            fa[u][i]=fa[fa[u][i-1]][i-1];
        }
        for (int v:vec[u]) {
            if(v!=f)build(v,u);
        }
    }
    int lca_dis(int u,int v){
        if(u==v)return 0;
        int ans=0;
        if(depth[u]<depth[v])swap(u,v);
        for (int i = LOGMAXN-1; i >= 0; --i) {
            if(depth[fa[u][i]]>=depth[v]){
                u=fa[u][i];
                ans+=(1<<i);
            }
        }
        if(u==v)return ans;
        for (int i = LOGMAXN-1; i >= 0; --i) {
            if(fa[u][i]!=fa[v][i]){
                ans+=(1<<(i+1));
                u=fa[u][i];
                v=fa[v][i];
            }
        }
        return ans+2;
    }
};
int main(){
//    int _;cin>>_;
//    while (_--){
//
//    }
    LCA_DIS lca;
    cin>>n;
    for (int i = 0; i < n-1; ++i) {
        int a,b;cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    lca.build(1,0);
    int q;cin>>q;
    while(q--){
        int x,y,a,b,k;
        cin>>x>>y>>a>>b>>k;
        int dab=lca.lca_dis(a,b);
        int dax=lca.lca_dis(a,x);
        int dbx=lca.lca_dis(b,x);
        int day=lca.lca_dis(a,y);
        int dby=lca.lca_dis(b,y);
        int dab1=dax+dby+1;
        int dab2=dbx+day+1;
        //debug(dab)
        if((dab<=k && (k-dab)%2==0) ||
           (dab1<=k && (k-dab1)%2==0)||
           (dab2<=k && (k-dab2)%2==0)){
            puts("yes");
        }
        else puts("no");
    }
}

/*
4
3 >>
3 <<
7 >><>><
5 >>><



 * */
