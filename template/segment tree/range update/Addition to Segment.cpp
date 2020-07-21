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
ll lazy[MAXN*4];
int arr[MAXN],ans[MAXN];
int n,m;
void pushup(int cnt){
    sum[cnt]=sum[lcnt]+sum[rcnt];
}
void pushdown(int l,int r,int cnt){
    if(lazy[cnt])sum[cnt]+=lazy[cnt]*(r-l+1);
    if(l!=r)lazy[lcnt]+=lazy[cnt],lazy[rcnt]+=lazy[cnt];
    lazy[cnt]=0;
}
void update(int ql,int qr,int val,int l,int r,int cnt){
    pushdown(l,r,cnt);
    if(ql<=l && r<=qr){
        if(l!=r)lazy[lcnt]+=val,lazy[rcnt]+=val;
        sum[cnt]+=(ll)val*(r-l+1);
        //debug2(l,r)
        //debug(sum[cnt])
        return;
    }
    if(qr<l || ql>r)return;
    int mid=l+r>>1;
    update(ql,qr,val,l,mid,lcnt);
    update(ql,qr,val,mid+1,r,rcnt);
    pushup(cnt);
}
ll query(int ql,int l,int r,int cnt){
    pushdown(l,r,cnt);
    //debug2(l,r)
    //debug(sum[cnt])
    if(l==r && ql==l)return sum[cnt];
    int mid=l+r>>1;
    if(ql<=mid)return query(ql,l,mid,lcnt);
    else return query(ql,mid+1,r,rcnt);
}
int main(){
    cin>>n>>m;
    while (m--){
        int o;cin>>o;
        if(o==1){
            int a,b,v;cin>>a>>b>>v;
            update(a+1,b,v,1,n,1);
        }
        else{
            int a;cin>>a;
            cout << query(a+1,1,n,1) << "\n";
        }
    }

}

/*

 2
 5
 1 3 1 3 1
 5
 3 1 3 1 3


 * */