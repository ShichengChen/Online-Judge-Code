#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
typedef long long ll;
#define debug(x) cout << '>' << #x << ':' << (x) << endl;
#define debug2(y,z) cout << '>' << #y << ':' << (y) << " " << #z << ":" <<(z) << endl;
#define lcnt (cnt<<1)
#define rcnt (cnt<<1|1)
const int MAXN =2e5+50;
const int LOGMAXN = 18;
ll const MOD=1e9+7;
int sum[MAXN*4];
int arr[MAXN],ans[MAXN];
int n,m;
void update(int ql,int val,int l,int r,int cnt){
    if(l==r && l==ql){
        sum[cnt]+=val;
        return;
    }
    int mid=l+r>>1;
    if(ql<=mid)update(ql,val,l,mid,lcnt);
    else update(ql,val,mid+1,r,rcnt);
    sum[cnt]=sum[lcnt]+sum[rcnt];
}
int query(int ql,int qr,int l,int r,int cnt){
    if(qr<l || ql>r)return 0;
    if(ql<=l && r<=qr)return sum[cnt];
    int mid=l+r>>1;
    int a=query(ql,qr,l,mid,lcnt);
    int b=query(ql,qr,mid+1,r,rcnt);
    return a+b;
}
int main(){
    cin>>n;
    n*=2;
    map<int,int>ma;
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
        if(ma.find(arr[i])!=ma.end()){
            int prei=ma[arr[i]];
            ans[arr[i]]=i-prei-1-query(prei,i,1,n,1)*2;
            update(prei,1,1,n,1);
            ma.erase(arr[i]);
        }
        else ma[arr[i]]=i;
    }
    for (int i = 1; i <= n/2; ++i) {
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