#include <bits/stdc++.h>
using namespace std;

using Int = long long;
const char newl = '\n';

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}
template<typename T=Int>
vector<T> read(size_t n){
    vector<T> ts(n);
    for(size_t i=0;i<n;i++) cin>>ts[i];
    return ts;
}


template<typename F>
struct FixPoint : F{
    FixPoint(F&& f):F(forward<F>(f)){}
    template<typename... Args>
    decltype(auto) operator()(Args&&... args) const{
        return F::operator()(*this,forward<Args>(args)...);
    }
};
template<typename F>
inline decltype(auto) MFP(F&& f){
    return FixPoint<F>{forward<F>(f)};
}

//INSERT ABOVE HERE
const Int MAX = 6;

Int idx[MAX][MAX*MAX+1];

signed solve(){
    Int s,ra,pa,rb,pb,n;
    cin>>s>>ra>>pa>>rb>>pb>>n;
    ra--;pa--;rb--;pb--;

    memset(idx,-1,sizeof(idx));
    for(Int i=0,t=1,cur=0;i<s;i++,t+=2)
        for(Int j=0;j<t;j++)
            idx[i][j]=1LL<<(cur++);

    // cout<<idx[ra][pa]<<endl;

    Int state=idx[ra][pa]+idx[rb][pb];
    // cout<<state<<endl;

    for(Int i=0;i<n;i++){
        Int r,p;
        cin>>r>>p;
        r--;p--;
        state+=idx[r][p];
    }
    // cout<<state<<endl;

    using T = tuple<Int, Int, Int, Int, Int>;
    map<T, Int> dp;
    MFP([&](auto dfs,Int bit,Int a,Int b,Int c,Int d)->Int{
        if(dp.count(T(bit,a,b,c,d))) return dp[T(bit,a,b,c,d)];
        Int &res=dp[T(bit,a,b,c,d)];
        const Int INF = 1000000;
        res=-INF;

        auto in=[&](Int y,Int x){
            return 0<=y and 0<=x and idx[y][x]>0 and (bit&idx[y][x])==0;
        };

        auto uku=[&](Int y,Int x){
            if( x&1 and in(y-1,x-1)) return 0;
            if(~x&1 and in(y+1,x+1)) return 0;
            if(in(y,x-1)) return 0;
            if(in(y,x+1)) return 0;
            return 1;
        };


        // cout<<bit<<' '<<a<<' '<<b<<' '<<c<<' '<<d<<':'<<uku(a,b)<<' '<<uku(c,d)<<newl;
        if(uku(a,b) and uku(c,d)) return res=0;

        // tate
        if(b&1 and in(a-1,b-1))
            chmax(res,-dfs(bit+idx[a-1][b-1],c,d,a-1,b-1)+1);

        if(~b&1 and in(a+1,b+1))
            chmax(res,-dfs(bit+idx[a+1][b+1],c,d,a+1,b+1)+1);

        // yoko
        if(in(a,b-1))
            chmax(res,-dfs(bit+idx[a][b-1],c,d,a,b-1)+1);
        if(in(a,b+1))
            chmax(res,-dfs(bit+idx[a][b+1],c,d,a,b+1)+1);

        // stay
        if(uku(a,b)) chmax(res,-dfs(bit,c,d,a,b));

        // cout<<bit<<' '<<a<<' '<<b<<' '<<c<<' '<<d<<':'<<res<<newl;
        return res;
    })(state,ra,pa,rb,pb);
    cout<<dp[T(state,ra,pa,rb,pb)]<<newl;
    return 0;
}
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    Int T;
    cin>>T;
    for(Int t=1;t<=T;t++){
        cout<<"Case #"<<t<<": ";
        solve();
    }
    return 0;
}