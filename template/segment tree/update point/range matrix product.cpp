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
ll sum[MAXN*4][4],mod;
int arr[MAXN][4];
int n,m;
void matmul(int cnt0,int cnt1,int cnt2){
    ll cur[4];
    for (int i = 0; i < 4; ++i)
        cur[i]=sum[cnt1][i/2*2]*sum[cnt2][i%2]+sum[cnt1][i/2*2+1]*sum[cnt2][i%2+2];
    for (int i = 0; i < 4; ++i)
        sum[cnt0][i]=cur[i]%mod;
}
void pushup(int cnt){
    matmul(cnt,lcnt,rcnt);
}
void build(int l,int r,int cnt){
    if(l==r){
        for(int i = 0; i < 4; ++i)
            sum[cnt][i]=arr[l][i]%mod;
        return;
    }
    int mid=l+r>>1;
    build(l,mid,lcnt);
    build(mid+1,r,rcnt);
    pushup(cnt);
}
void query(int ql,int qr,int l,int r,int cnt){
    if(qr<l || ql>r || ql>qr)return;
    if(ql<=l && r<=qr){
        matmul(0,0,cnt);
        return;
    }
    int mid=l+r>>1;
    query(ql,qr,l,mid,lcnt);
    query(ql,qr,mid+1,r,rcnt);
}
int main(){
    cin>>mod>>n>>m;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < 4; ++j)
            scanf("%d",&arr[i][j]);
    build(1,n,1);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        sum[0][0]=sum[0][3]=1;
        sum[0][1]=sum[0][2]=0;
        query(a,b,1,n,1);
        cout << sum[0][0]%mod << " " << sum[0][1]%mod << "\n";
        cout << sum[0][2]%mod << " " << sum[0][3]%mod << "\n";
        puts("");
    }
}
/*
7
 1 2 3 4 5 6 7

 5
 5 2 3 4 1
 * */