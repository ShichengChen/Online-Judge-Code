#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
typedef long long ll;
#define debug(x) cout << '>' << #x << ':' << (x) << endl;
#define debug2(y,z) cout << '>' << #y << ':' << (y) << " " << #z << ":" <<(z) << endl;
const int MAXN =1e5+50;
const int LOGMAXN = 18;
ll const MOD=1e9+7;
ll sum[MAXN*4];
int arr[MAXN];
int n,m;
void build(int l,int r,int cnt){
    if(l==r){
        sum[cnt]=arr[l];
        return;
    }
    int mid=l+r>>1;
    build(l,mid,cnt<<1);
    build(mid+1,r,cnt<<1|1);
    sum[cnt]=sum[cnt<<1]+sum[cnt<<1|1];
}
void update(int ql,int val,int l,int r,int cnt){
    if(l==r && l==ql){
        sum[cnt]=val;
        return;
    }
    int mid=l+r>>1;
    if(ql<=mid)update(ql,val,l,mid,cnt<<1);
    else update(ql,val,mid+1,r,cnt<<1|1);
    sum[cnt]=sum[cnt<<1]+sum[cnt<<1|1];
}
ll query(int ql,int qr,int l,int r,int cnt){
    if(qr<l || ql>r)return 0;
    if(ql<=l && r<=qr)return sum[cnt];
    int mid=l+r>>1;
    ll a=query(ql,qr,l,mid,cnt<<1);
    ll b=query(ql,qr,mid+1,r,cnt<<1|1);
    return a+b;
}
int main(){
    cin>>n>>m;
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
    }
    build(1,n,1);
    while(m--){
        int o,a,b;cin>>o>>a>>b;
        if(o==1){
            update(a+1,b,1,n,1);
        }
        else{
            cout << query(a+1,b,1,n,1) << "\n";
        }
    }
}
/*
7
 1 2 3 4 5 6 7

 5
 5 2 3 4 1
 * */