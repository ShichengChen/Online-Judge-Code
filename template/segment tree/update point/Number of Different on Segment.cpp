#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
typedef long long ll;
#define debug(x) cout << '>' << #x << ':' << (x) << endl;
#define debug2(y,z) cout << '>' << #y << ':' << (y) << " " << #z << ":" <<(z) << endl;
#define lcnt (cnt<<1)
#define rcnt (cnt<<1|1)
const int MAXN =1e5+50;
const int LOGMAXN = 18;
ll const MOD=1e9+7;
map<int,int>ma[MAXN*4];
map<int,int>ans;
int arr[MAXN];
int n,m;
void build(int l,int r,int cnt){
    if(l==r){
        ma[cnt][arr[l]]=1;
        return;
    }
    int mid=l+r>>1;
    build(l,mid,lcnt);
    build(mid+1,r,rcnt);
    for (auto &[a,b]: ma[lcnt]) {
        ma[cnt][a]+=b;
    }
    for (auto &[a,b]: ma[rcnt]) {
        ma[cnt][a]+=b;
    }
}
void query(int ql,int qr,int l,int r,int cnt){
    if(qr<l || ql>r)return;
    if(ql<=l && r<=qr){
        ans.insert(ma[cnt].begin(),ma[cnt].end());
        return;
    }
    int mid=l+r>>1;
    query(ql,qr,l,mid,lcnt);
    query(ql,qr,mid+1,r,rcnt);

}
void update(int ql,int val,int l,int r,int cnt){
    if(l==r && l==ql){
        ma[cnt].clear();
        ma[cnt][val]++;
        return;
    }
    int mid=l+r>>1;
    if(ql<=mid)update(ql,val,l,mid,lcnt);
    else update(ql,val,mid+1,r,rcnt);
    if(ma[cnt][arr[ql]]==1)ma[cnt].erase(arr[ql]);
    else ma[cnt][arr[ql]]--;
    ma[cnt][val]++;
}
int main(){
    cin>>n>>m;
    for (int i = 1; i <= n; ++i)
        scanf("%d",&arr[i]);
    build(1,n,1);
    while(m--){
        int o,a,b;
        scanf("%d%d%d",&o,&a,&b);
        if(o==1){
            ans.clear();
            query(a,b,1,n,1);
            cout << ans.size() << "\n";
        }
        else{
            update(a,b,1,n,1);
            arr[a]=b;
        }

    }
}
/*
7
 1 2 3 4 5 6 7

 5
 5 2 3 4 1
 * */