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
ll maxn[MAXN*4],prefix[MAXN*4],suffix[MAXN*4],sum[MAXN*4];
int arr[MAXN];
int n,m;
void pushup(int cnt){
    suffix[cnt]=max(sum[rcnt]+suffix[lcnt],suffix[rcnt]);
    prefix[cnt]=max(sum[lcnt]+prefix[rcnt],prefix[lcnt]);
    maxn[cnt]=max(maxn[lcnt],maxn[rcnt]);
    maxn[cnt]=max(suffix[cnt],maxn[cnt]);
    maxn[cnt]=max(prefix[cnt],maxn[cnt]);
    maxn[cnt]=max(prefix[rcnt]+suffix[lcnt],maxn[cnt]);
    sum[cnt]=sum[lcnt]+sum[rcnt];
}
void update(int ql,int val,int l,int r,int cnt){
    if(l==r && l==ql){
        suffix[cnt]=prefix[cnt]=maxn[cnt]=sum[cnt]=val;
        return;
    }
    int mid=l+r>>1;
    if(ql<=mid)update(ql,val,l,mid,lcnt);
    else update(ql,val,mid+1,r,rcnt);
    pushup(cnt);
}
int main(){
    cin>>n>>m;
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
        update(i,arr[i],1,n,1);
    }
    //build(1,n,1);
    cout << max(maxn[1],0ll) << "\n";
    while(m--){
        int a,b;cin>>a>>b;
        update(a+1,b,1,n,1);
        cout << max(maxn[1],0ll) << "\n";
    }
}
/*
7
 1 2 3 4 5 6 7

 5
 5 2 3 4 1
 * */