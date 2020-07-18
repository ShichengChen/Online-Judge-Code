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
int query(int val,int l,int r,int cnt){
    if(l==r)return l;
    int mid=l+r>>1;
    if(maxn[lcnt]<val)return query(val,mid+1,r,rcnt);
    else return query(val,l,mid,lcnt);
}
int main(){
    cin>>n>>m;
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
        update(i,arr[i],1,n,1);
    }
    while(m--){
        int o;cin>>o;
        if(o==1){
            int a,b;cin>>a>>b;
            update(a+1,b,1,n,1);
        }
        else {
            int a;cin>>a;
            if(maxn[1]<a)puts("-1");
            else cout << query(a,1,n,1)-1 << "\n";
        }
    }
}
/*
7
 1 2 3 4 5 6 7

 5
 5 2 3 4 1
 * */