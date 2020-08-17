#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
#define debug1(__x) cout << '>' << #__x << ':' << (__x) << endl;
#define debug2(__y,__z) cout << '>' << #__y << ':' << (__y) << " " << #__z << ":" <<(__z) << endl;
#define debug3(__x,__y,__z) cout << '>' << #__x << ':' << (__x) << " >" << #__y << ":" <<(__y) << " >" << #__z << ":" <<(__z) << endl;
#define GET4(a,b,c,d,...) d
#define debug_(...) GET4(__VA_ARGS__,debug3,debug2,debug1)
#define debug(...) debug_(__VA_ARGS__)(__VA_ARGS__)
#define lcnt (cnt<<1)
#define rcnt (cnt<<1|1)
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)
template<class T> bool umin(T& a, const T& b) {return b<a?a=b, 1:0;}
template<class T> bool umax(T& a, const T& b) {return a<b?a=b, 1:0;}
ll FIRSTTRUE(function<bool(ll)> f, ll lb, ll rb) {
    while(lb<rb) {
        ll mb=(lb+rb)/2;
        f(mb)?rb=mb:lb=mb+1;
    }
    return lb;
}
ll LASTTRUE(function<bool(ll)> f, ll lb, ll rb) {
    while(lb<rb) {
        ll mb=(lb+rb+1)/2;
        f(mb)?lb=mb:rb=mb-1;
    }
    return lb;
}

template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(array<A, S>& a);
template<class H, class T> void read(pair<H,T>&c);
template<class T> void read(T& x) {cin >> x;}
void read(double& d) {
    string t;
    read(t);
    d=stod(t);
}
void read(long double& d) {
    string t;
    read(t);
    d=stold(t);
}
template<class H, class T> void read(pair<H,T>&c){read(c.first);read(c.second);}
template<class H, class... T> void read(H& h, T&... t) {read(h);read(t...);}
template<class A> void read(vector<A>& x) {EACH(a, x)read(a);}
template<class A, size_t S> void read(array<A, S>& x) {EACH(a, x)read(a);}
string to_string(char c) {return string(1, c);}
string to_string(bool b) {return b?"true":"false";}
string to_string(const char* s) {return string(s);}
string to_string(string s) {return s;}
string to_string(vector<bool> v) {
    string res;
    FOR(sz(v))res+=char('0'+v[i]);
    return res;
}
template<class T,class U> string to_string(pair<T,U> a){
    return to_string(a.first)+":"+to_string(a.second);
}
template<size_t S> string to_string(bitset<S> b) {
    string res;
    FOR(S)res+=char('0'+b[i]);
    return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    EACH(x, v) {
        if(!f)res+=' ';
        f=0;
        res+=to_string(x);
    }
    return res;
}
template<class A> void write(A x) {cout << to_string(x);}
template<class H, class... T> void write(const H& h, const T&... t) {write(h);write(t...);}
void print() {write("\n");}
template<class H, class... T> void print(const H& h, const T&... t) {
    write(h);
    if(sizeof...(t))write(' ');
    print(t...);
}
void DBG() {cerr << "]" << endl;}
template<class H, class... T> void DBG(H h, T... t) {
    cerr << to_string(h);
    if(sizeof...(t))
        cerr << ", ";
    DBG(t...);
}
#define _DEBUG
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...) 0
#endif

template<class T> void offset(ll o, T& x) {x+=o;}
template<class T> void offset(ll o, vt<T>& x) {
    EACH(a, x)offset(o, a);
}
template<class T, size_t S> void offset(ll o, array<T, S>& x) {
    EACH(a, x)offset(o, a);
}

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) {
    return uniform_int_distribution<ll>(a, b)(mt_rng);
}
template<class T, class U> void vti(vt<T> &v, U x, size_t n) {v=vt<T>(n, x);}
template<class T, class U> void vti(vt<T> &v, U x, size_t n, size_t m...) {
    v=vt<T>(n);
    EACH(a, v)vti(a, x, m);
}
const int MAXN = 4e6+20;
const int LOGMAXN = 18;
ll const MOD=1e9+7;
int n,m,nn;
vector<ll>vec[3];
vector<ll>param[3];
int coor[MAXN];
unordered_map<int,int>ma;
ll sum[3][MAXN*4],lazy[3][MAXN*4],arr[MAXN];
void pushup(int cnt){FOR(3)sum[i][cnt]=sum[i][lcnt]+sum[i][rcnt];}
void pushdown(int l,int r,int cnt){
    FOR(3){
        if(i<=1){if(lazy[i][cnt])sum[i][cnt]=0;}
        else {if(lazy[i][cnt])sum[i][cnt]=1;}
        if(l!=r && lazy[i][cnt])lazy[i][lcnt]=lazy[i][rcnt]=lazy[i][cnt];
        lazy[i][cnt]=0;
    }
}
void build(int l,int r,int cnt){
    FOR(3)lazy[i][cnt]=0;
    if(l==r) {
        sum[0][cnt]=arr[l];
        sum[1][cnt]=0;
        sum[2][cnt]=0;
        return;
    }
    int mid=l+r>>1;
    build(l,mid,lcnt);build(mid+1,r,rcnt);
    pushup(cnt);
}
void update(int ql,int qr,int l,int r,int cnt,int type){
    if(ql>qr)return;
    pushdown(l,r,cnt);
    if(ql<=l && r<=qr){
        if(l!=r)lazy[type][lcnt]=lazy[type][rcnt]=1;
        if(type==0)
            sum[type][cnt]=0;
        else if(type==1){
            if(ql==qr)sum[type][cnt]=1;
            else sum[type][cnt]=0;
        }
        else if(type==2)
            sum[type][cnt]=1;
        else assert(false);
        return;
    }
    if(qr<l || ql>r)return;
    int mid=l+r>>1;
    update(ql,qr,l,mid,lcnt,type);
    update(ql,qr,mid+1,r,rcnt,type);
    pushup(cnt);
}
ll query(int ql,int qr,int l,int r,int cnt,int type){
    if(ql>qr)return 0;
    if(ql<1 || qr>nn)return 0;
    pushdown(l,r,cnt);
    if(ql<=l && r<=qr)return sum[type][cnt];
    if(qr<l || ql>r)return 0;
    int mid=l+r>>1;
    ll a=query(ql,qr,l,mid,lcnt,type);
    ll b=query(ql,qr,mid+1,r,rcnt,type);
    return a+b;
}
void solve() {
    read(n,m);
//    memset(sum,0,sizeof(sum));
//    memset(lazy,0,sizeof(lazy));

    ma.clear();
    FOR(3)vec[i].clear(),vec[i]=vector<ll>(m);
    FOR(3)param[i].clear(),param[i]=vector<ll>(4);
    FOR(3){
        read(vec[i]);
        read(param[i]);
    }
    FOR(i,3)FOR(j,m,n)
    vec[i].push_back((param[i][0]*vec[i][sz(vec[i])-2]+param[i][1]*vec[i][sz(vec[i])-1]+param[i][2])%param[i][3]+1);
    FOR(i,n)coor[i*2]=vec[0][i],coor[i*2+1]=vec[0][i]+vec[1][i];
    sort(coor,coor+n*2);
    nn=4*n;
    memset(arr,0,sizeof(int)*(nn+5));
    FOR(i,n*2-1){
        arr[(i+1)*2]=coor[i+1]-coor[i];
        ma[coor[i]]=(i+1)*2;
        if(i==n*2-2){
            ma[coor[i+1]]=(i+2)*2;
        }
    }

    //FOR(3)memset(lazy[i],0,sizeof(int)*(n*2+10));
    build(1,nn,1);
    ll ans=1,pre=0;
    FOR(i,n){
        int l=ma[vec[0][i]],r=ma[vec[0][i]+vec[1][i]];
        ll lin=query(l,l,1,nn,1,2);
        ll lem=query(l-1,l-1,1,nn,1,2);
        ll rin=query(r,r,1,nn,1,2);
        ll rem=query(r+1,r+1,1,nn,1,2);
        ll cedge=0;
        if(!lin)cedge+=vec[2][i];
        if(!rin)cedge+=vec[2][i];
        //debug(lin,rin)
        ll re=query(l,r,1,nn,1,1);
        update(l,r,1,nn,1,1);//remove all one
        if(!lin || !lem)update(l,l,1,nn,1,1);//add point
        if(!rin || !rem)update(r,r,1,nn,1,1);//add point
        if(lin && !lem)re--;
        if(rin && !rem)re--;
        update(l,r,1,nn,1,2);//type 2 range add

//        debug((!lin || (!lem)),(!rin || (!rem)))
        //debug(query(l,r,1,nn,1,1))
        //print(query(l,r,1,nn,1,1));
        ll weight=query(l,r-1,1,nn,1,0);
        update(l,r-1,1,nn,1,0);
        ll cur=cedge+weight*2+pre-re*vec[2][i];
        cur=(cur%MOD+MOD)%MOD;
        pre=cur;
        //print(i,cur,weight,re);
        ans=ans*cur%MOD;
    }
    print(ans);
}
int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    freopen("/home/csc/Downloads/perimetric_chapter_2_input.txt", "r", stdin); // redirects standard input
    freopen("/home/csc/G/output.txt", "w", stdout); // redirects standard output
    int t, i=1; 
    read(t);
    while(t--) {
        cout << "Case #" << i << ": ";
        solve();
        ++i;
    }
    return 0;
}
/*
 1
 5 5
 1 2 1 2 1
 0 0 0 0
 1 1 1 1 2
 0 0 0 0
 1 1 1 1 1
 0 0 0 0

 1
 5 5
 1 3 4 5 6
 0 0 0 0
 1 1 1 1 1
 0 0 0 0
 1 1 1 1 1
 0 0 0 0

 * */