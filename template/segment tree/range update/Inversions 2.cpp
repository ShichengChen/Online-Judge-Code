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
int minn[MAXN*4],lazy[MAXN*4];
int arr[MAXN],ans[MAXN];
int n,m;
void pushup(int cnt){
    minn[cnt]=min(minn[lcnt],minn[rcnt]);
}
void pushdown(int l,int r,int cnt){
    if(lazy[cnt])minn[cnt]+=lazy[cnt];
    if(l!=r)lazy[lcnt]+=lazy[cnt],lazy[rcnt]+=lazy[cnt];
    lazy[cnt]=0;
}
void build(int l,int r,int cnt){
    if(l==r){
        minn[cnt]=arr[l];
        return;
    }
    int mid=l+r>>1;
    build(l,mid,lcnt);
    build(mid+1,r,rcnt);
    pushup(cnt);
}
void update(int ql,int qr,int val,int l,int r,int cnt){
    pushdown(l,r,cnt);
    if(ql<=l && r<=qr){
        if(l!=r)lazy[lcnt]+=val,lazy[rcnt]+=val;
        minn[cnt]+=val;
        return;
    }
    if(qr<l || ql>r)return;
    int mid=l+r>>1;
    update(ql,qr,val,l,mid,lcnt);
    update(ql,qr,val,mid+1,r,rcnt);
    pushup(cnt);
}
int query(int l,int r,int cnt){
    //debug2(l,r);
    //debug(minn[cnt]);
    pushdown(l,r,cnt);
    if(l==r)return l;
    int mid=l+r>>1;
    //debug(minn[rcnt]);
    pushdown(mid+1,r,rcnt);
    if(minn[rcnt]==0)return query(mid+1,r,rcnt);
    else return query(l,mid,lcnt);
}
int main(){
    cin>>n;
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
    }
    build(1,n,1);

    for (int i = 0; i < n; ++i) {
        int idx=query(1,n,1);
        //cout << idx << " ";
        ans[idx]=n-i;
        update(idx+1,n,-1,1,n,1);
        update(idx,idx,2*n+1,1,n,1);
    }
    for (int i = 1; i <=n; ++i) {
        cout << ans[i] << " ";
    }

}

/*

 2
 5
 1 3 1 3 1
 5
 3 1 3 1 3


 * */