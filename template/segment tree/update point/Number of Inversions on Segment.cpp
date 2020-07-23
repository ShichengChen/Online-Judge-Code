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
map<int,int>ans;
int arr[MAXN];
int curnum[MAXN*4][41];
int num[MAXN*4][41];
int sum[41];
ll inv[MAXN*4];
int n,m;
void pushup(int cnt){
    inv[cnt]=inv[lcnt]+inv[rcnt];
    for (int i = 1; i <= 40; ++i) {
        sum[i]=sum[i-1]+num[rcnt][i];
    }
    for (int i = 1; i <= 40; ++i) {
        inv[cnt]+=(ll)num[lcnt][i]*sum[i-1];
        num[cnt][i]=num[lcnt][i]+num[rcnt][i];
    }
}
void build(int l,int r,int cnt){
    if(l==r){
        num[cnt][arr[l]]++;
        return;
    }
    int mid=l+r>>1;
    build(l,mid,lcnt);
    build(mid+1,r,rcnt);
    pushup(cnt);
}
ll query(int ql,int qr,int l,int r,int cnt){
    if(qr<l || ql>r){
        memset(curnum[cnt],0, sizeof(int)*41);
        return 0;
    }
    if(ql<=l && r<=qr){
        memcpy(curnum[cnt],num[cnt],sizeof(int)*41);
        return inv[cnt];
    }
    int mid=l+r>>1;
    ll c0=query(ql,qr,l,mid,lcnt);
    ll c1=query(ql,qr,mid+1,r,rcnt);
    ll c=c0+c1;
    for (int i = 1; i <= 40; ++i) {
        sum[i]=sum[i-1]+curnum[rcnt][i];
    }
    for (int i = 1; i <= 40; ++i) {
        c+=(ll)curnum[lcnt][i]*sum[i-1];
        curnum[cnt][i]=curnum[lcnt][i]+curnum[rcnt][i];
    }
    return c;
}
void update(int ql,int val,int l,int r,int cnt){
    if(l==r && l==ql){
        num[cnt][arr[ql]]--;
        num[cnt][val]++;
        arr[ql]=val;
        return;
    }
    int mid=l+r>>1;
    if(ql<=mid)update(ql,val,l,mid,lcnt);
    else update(ql,val,mid+1,r,rcnt);
    pushup(cnt);
}
int main(){
    cin>>n>>m;
    for (int i = 1; i <= n; ++i)
        scanf("%d",&arr[i]);
    build(1,n,1);
    while(m--){
        int o,a,b;
        scanf("%d%d%d",&o,&a,&b);
        if(o==1){
            ll c=query(a,b,1,n,1);
            cout << c << "\n";
        }
        else{
            update(a,b,1,n,1);
        }

    }
}
/*
7
 1 2 3 4 5 6 7

 5
 5 2 3 4 1
 * */