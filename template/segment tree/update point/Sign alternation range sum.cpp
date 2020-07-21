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
ll sum[MAXN*4];
int arr[MAXN];
int n,m;
void pushup(int cnt){
    sum[cnt]=sum[lcnt]+sum[rcnt];
}
void build(int l,int r,int cnt){
    if(l==r){
        if(l%2)sum[cnt]=+arr[l];
        else sum[cnt]=-arr[l];
        return;
    }
    int mid=l+r>>1;
    build(l,mid,lcnt);
    build(mid+1,r,rcnt);
    pushup(cnt);
}
void update(int ql,int val,int l,int r,int cnt){
    if(l==r && l==ql){
        if(l%2)sum[cnt]=+val;
        else sum[cnt]=-val;
        return;
    }
    int mid=l+r>>1;
    if(ql<=mid)update(ql,val,l,mid,lcnt);
    else update(ql,val,mid+1,r,rcnt);
    pushup(cnt);
}
ll query(int ql,int qr,int l,int r,int cnt){
    if(qr<l || ql>r)return 0;
    if(ql<=l && r<=qr)return sum[cnt];
    int mid=l+r>>1;
    ll a=query(ql,qr,l,mid,lcnt);
    ll b=query(ql,qr,mid+1,r,rcnt);
    return a+b;
}
int main(){
    cin>>n;
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
    }
    build(1,n,1);
    cin>>m;
    while(m--){
        int o,a,b;cin>>o>>a>>b;
        if(o==0){
            update(a,b,1,n,1);
        }
        else{
            ll ans=query(a,b,1,n,1);
            if(a%2)cout << ans << "\n";
            else cout << -ans << "\n";
        }
    }
}
/*
7
 1 2 3 4 5 6 7

 5
 5 2 3 4 1
 * */