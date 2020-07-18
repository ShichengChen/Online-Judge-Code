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
int maxn[MAXN*4];
int arr[MAXN];
int n,m;
void pushup(int cnt){
    maxn[cnt]=max(maxn[lcnt],maxn[rcnt]);
}
void update(int ql,int val,int l,int r,int cnt){
    if(l==r && l==ql){
        maxn[cnt]=val;
        return;
    }
    int mid=l+r>>1;
    if(ql<=mid)update(ql,val,l,mid,lcnt);
    else update(ql,val,mid+1,r,rcnt);
    pushup(cnt);
}
int query(int ql,int val,int l,int r,int cnt){
    if(maxn[cnt]<val)return 0;
    if(l==r)return l;
    int mid=l+r>>1;
    if(maxn[lcnt]<val || ql>=mid+1)return query(ql,val,mid+1,r,rcnt);
    else{
        int a= query(ql,val,l,mid,lcnt);
        if(!a)return query(ql,val,mid+1,r,rcnt);
        else return a;
    }
}
int main(){
    cin>>n>>m;
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
        update(i,arr[i],1,n,1);
    }
    while(m--){
        int o,a,b;cin>>o>>a>>b;
        if(o==1){
            update(a+1,b,1,n,1);
        }
        else {
            cout << query(b+1,a,1,n,1)-1 << "\n";
        }
    }
}
/*
7
 1 2 3 4 5 6 7

 5
 5 2 3 4 1
 * */