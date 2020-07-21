#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
typedef long long ll;
#define debug(x) cout << '>' << #x << ':' << (x) << endl;
#define debug2(y,z) cout << '>' << #y << ':' << (y) << " " << #z << ":" <<(z) << endl;
const int MAXN =1e5+50;
const int LOGMAXN = 18;
ll const MOD=1e9+7;
int minn[MAXN*4];
int num[MAXN*4];
int arr[MAXN];
int n,m;
void pushup(int cnt){
    if(minn[cnt<<1]==minn[cnt<<1|1])
        num[cnt]=num[cnt<<1]+num[cnt<<1|1];
    else if(minn[cnt<<1]<minn[cnt<<1|1])
        num[cnt]=num[cnt<<1];
    else num[cnt]=num[cnt<<1|1];
    minn[cnt]=min(minn[cnt<<1],minn[cnt<<1|1]);
}
void build(int l,int r,int cnt){
    if(l==r){
        minn[cnt]=arr[l];
        num[cnt]=1;
        return;
    }
    int mid=l+r>>1;
    build(l,mid,cnt<<1);
    build(mid+1,r,cnt<<1|1);
    pushup(cnt);
}
void update(int ql,int val,int l,int r,int cnt){
    if(l==r && l==ql){
        minn[cnt]=val;
        return;
    }
    int mid=l+r>>1;
    if(ql<=mid)update(ql,val,l,mid,cnt<<1);
    else update(ql,val,mid+1,r,cnt<<1|1);
    pushup(cnt);
}
pair<int,int> query(int ql,int qr,int l,int r,int cnt){
    if(qr<l || ql>r)return {1,1e9+1};
    if(ql<=l && r<=qr)return {num[cnt],minn[cnt]};
    int mid=l+r>>1;
    auto a=query(ql,qr,l,mid,cnt<<1);
    auto b=query(ql,qr,mid+1,r,cnt<<1|1);
    int nc0=0,nc1=min(a.second,b.second);
    if(a.second==b.second)nc0=a.first+b.first;
    else if(a.second<b.second)nc0=a.first;
    else nc0=b.first;
    return {nc0,nc1};
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
            auto c=query(a+1,b,1,n,1);
            cout << c.second << " " << c.first << "\n";
        }
    }
}
/*
7
 1 2 3 4 5 6 7

 5
 5 2 3 4 1
 * */