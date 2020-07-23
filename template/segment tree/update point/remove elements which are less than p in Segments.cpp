#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define debug(x) cout << '>' << #x << ':' << (x) << endl;
#define debug2(y,z) cout << '>' << #y << ':' << (y) << " " << #z << ":" <<(z) << endl;
#define lcnt (cnt<<1)
#define rcnt (cnt<<1|1)
const int MAXN =1e5+50;
const int LOGMAXN = 18;
ll const MOD=1e9+7;
vector<int>br;
int arr[MAXN];
int lazy[MAXN*4];
vector<int>vec[MAXN*4];
multiset<int>se[MAXN*4];
int n,m;
void pushdown(int cnt,int l,int r){
    if(lazy[cnt]){
        while(se[cnt].size() && *(se[cnt].begin())<=lazy[cnt])
            se[cnt].erase(se[cnt].begin());
        if(l!=r){
            lazy[lcnt]=max(lazy[lcnt],lazy[cnt]);
            lazy[rcnt]=max(lazy[rcnt],lazy[cnt]);
        }
        lazy[cnt]=0;
    }
}
int query(int ql,int qr,int val,int l,int r,int cnt){
    vec[cnt].clear();
    if(qr<l || ql>r)return 0;
    pushdown(cnt,l,r);
    if(ql<=l && r<=qr){
        int cur=0;
        while(se[cnt].size() && *(se[cnt].begin())<=val){
            //debug(*(se[cnt].begin()))
            auto it=se[cnt].begin();
            vec[cnt].push_back(*it);
            se[cnt].erase(it);
            cur++;
        }
        if(l!=r){
            lazy[lcnt]=max(lazy[lcnt],val);
            lazy[rcnt]=max(lazy[rcnt],val);
        }
        return cur;
    }
    int mid=l+r>>1;
    int c0=query(ql,qr,val,l,mid,lcnt);
    int c1=query(ql,qr,val,mid+1,r,rcnt);
    for (int i:vec[lcnt])vec[cnt].push_back(i),se[cnt].erase(se[cnt].find(i));
    for (int i:vec[rcnt])vec[cnt].push_back(i),se[cnt].erase(se[cnt].find(i));
    return c0+c1;
}
bool update(int ql,int val,int l,int r,int cnt){
    pushdown(cnt,l,r);
    if(l==r && l==ql){
        if(se[cnt].size()){
            se[cnt].clear();
            se[cnt].insert(val);
            return true;
        }
        else{
            se[cnt].insert(val);
            return false;
        }
    }
    int mid=l+r>>1;
    bool ans;
    if(ql<=mid)ans=update(ql,val,l,mid,lcnt);
    else ans=update(ql,val,mid+1,r,rcnt);
    se[cnt].insert(val);
    if(ans){
        auto it=se[cnt].find(arr[ql]);
        se[cnt].erase(it);
        return true;
    }
    else return false;
}

int main(){
    cin>>n>>m;
    while(m--){
        int o,a,b,val;
        scanf("%d%d%d",&o,&a,&b);
        if(o==2){
            scanf("%d",&val);
            int c=query(a+1,b,val,1,n,1);
            printf("%d\n",c);
        }
        else{
            update(a+1,b,1,n,1);
            arr[a+1]=b;
        }

    }
}
/*
7
 1 2 3 4 5 6 7

 5
 5 2 3 4 1
 * */