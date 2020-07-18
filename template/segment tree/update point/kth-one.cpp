#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
typedef long long ll;
#define debug(x) cout << '>' << #x << ':' << (x) << endl;
#define debug2(y,z) cout << '>' << #y << ':' << (y) << " " << #z << ":" <<(z) << endl;
#define lcnt (cnt<<1)
#define rcnt (cnt<<1|1)
const int MAXN =1e5+50;
ll const MOD=1e9+7;
int sum[MAXN*4];
int arr[MAXN];
int n,m;
void pushup(int cnt){
    sum[cnt]=sum[lcnt]+sum[rcnt];
}
void update(int ql,int l,int r,int cnt){
    if(l==r && l==ql){
        sum[cnt]=1-sum[cnt];
        return;
    }
    int mid=l+r>>1;
    if(ql<=mid)update(ql,l,mid,lcnt);
    else update(ql,mid+1,r,rcnt);
    pushup(cnt);
}
int query(int kth,int l,int r,int cnt){
    if(l==r)return l;
    int mid=l+r>>1;
    if(sum[lcnt]<kth)return query(kth-sum[lcnt],mid+1,r,rcnt);
    else return query(kth,l,mid,lcnt);
}
int main(){
    cin>>n>>m;
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
        if(arr[i])update(i,1,n,1);
    }
    //debug(sum[1])
    while(m--){
        int o,a;cin>>o>>a;
        if(o==1)update(a+1,1,n,1);
        else {
            cout << query(a+1,1,n,1)-1 << "\n";
        }
    }
}
/*
7
 1 2 3 4 5 6 7

 5
 5 2 3 4 1
 * */