#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
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
        //cout << mb << endl;
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
template <class T> string to_string(T v);
template<class T,class U> string to_string(pair<T,U> a);
string to_string(char c) {return string(1, c);}
string to_string(bool b) {return b?"true":"false";}
string to_string(const char* s) {return string(s);}
string to_string(string s) {return s;}
string to_string(vector<bool> v) {
    string res;
    FOR(sz(v))res+=char('0'+v[i]);
    return res;
}
template<size_t S> string to_string(bitset<S> b) {
    string res;
    FOR(S)res+=char('0'+b[i]);
    return res;
}

template <class T> string to_string(T v) {
    char c=' ';
    if constexpr (std::is_same_v<T, vector<vector<ll>>>) c='\n';
    if constexpr (std::is_same_v<T, vector<vector<int>>>) c='\n';
    bool f=1;
    string res;
    EACH(x, v) {
        if(!f)res+=c;
        f=0;
        res+=to_string(x);
    }
    return res;
}
template<class T,class U> string to_string(pair<T,U> a){return to_string(a.first)+":"+to_string(a.second);}
template<class A> void write(A x) {cout << to_string(x);}
template<class H, class... T> void write(const H& h, const T&... t) {write(h);write(t...);}
template<class H, class... T> void print(const H& h, const T&... t);
void print() {write("\n");}
template<class H, class... T> void print(const H& h, const T&... t) {
    write(h);
    if(sizeof...(t))write(' ');
    print(t...);
}
void DBG() {cout << "]" << endl;}
template<class H, class... T> void DBG(H h, T... t) {
    cout << to_string(h);
    if(sizeof...(t))
        cout << ", ";
    DBG(t...);
}
#define _DEBUG
#ifdef _DEBUG
#define debug(...) cout << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [\n", DBG(__VA_ARGS__)
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
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

const int LOGMAXN = 18;
//ll const MOD=998244353;
ll const MOD=1e9+7;

//template <int MOD_> struct modnum {
//    static constexpr int MOD = MOD_;
//    static_assert(MOD_ > 0, "MOD must be positive");
//private:
//    using ll = long long;
//    int v;
//    static int minv(int a, int m) {
//        a %= m;
//        assert(a);
//        return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
//    }
//public:
//    modnum() : v(0) {}
//    modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
//    explicit operator int() const { return v; }
//    friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
//    friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }
//    friend string to_string(modnum& n){return to_string(n.v);}
//    //friend void read(int &n){cin>>n;}
//    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
//    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }
//
//    modnum inv() const {
//        modnum res;
//        res.v = minv(v, MOD);
//        return res;
//    }
//    friend modnum inv(const modnum& m) { return m.inv(); }
//    modnum neg() const {
//        modnum res;
//        res.v = v ? MOD-v : 0;
//        return res;
//    }
//    friend modnum neg(const modnum& m) { return m.neg(); }
//
//    modnum operator- () const {
//        return neg();
//    }
//    modnum operator+ () const {
//        return modnum(*this);
//    }
//
//    modnum& operator ++ () {
//        v ++;
//        if (v == MOD) v = 0;
//        return *this;
//    }
//    modnum& operator -- () {
//        if (v == 0) v = MOD;
//        v --;
//        return *this;
//    }
//    modnum& operator += (const modnum& o) {
//        v += o.v;
//        if (v >= MOD) v -= MOD;
//        return *this;
//    }
//    modnum& operator -= (const modnum& o) {
//        v -= o.v;
//        if (v < 0) v += MOD;
//        return *this;
//    }
//    modnum& operator *= (const modnum& o) {
//        v = int(ll(v) * ll(o.v) % MOD);
//        return *this;
//    }
//    modnum& operator /= (const modnum& o) {
//        return *this *= o.inv();
//    }
//    friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
//    friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
//    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
//    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
//    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
//    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
//};
//
//using mint = modnum<MOD>;
//const int MAXN = 2e6+20;
const int MAXN = 505;
int f[MAXN*2];
int findf(int i){return f[i]==i?i:f[i]=findf(f[i]);}
bool merge(int a,int b){
    if(findf(a)==findf(b))return false;
    else{
        f[f[a]]=f[b];
        return true;
    }
}
void solve() {
    int n;read(n);int ans=0;
    vt<array<int,3>>edge;
    vt<vt<int>> s(n, vt<int>(n));
    vt<vt<int>> cost(n, vt<int>(n));
    read(s,cost);
    FOR(i,n)FOR(j,n)if(s[i][j]==-1)edge.push_back({cost[i][j],i,n+j}),ans+=cost[i][j];
    sort(all(edge));
    reverse(all(edge));
    {int cur;FOR(n)read(cur);FOR(n)read(cur);}
    FOR(2*n)f[i]=i;
    FOR(sz(edge)){
        if(merge(edge[i][1],edge[i][2]))ans-=edge[i][0];
    }
    print(ans);
}
int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    int t, i=1;
    read(t);
    while(t--) {
        cout << "Case #" << i << ": ";
        solve();
        ++i;
    }
    return 0;
}/*

99
8 10
1 1 2 2 3 3 9 9



99
2 1 1 1
2 2 1 1
2 2 2 2
2 1 2 1
5 2 2 2
5 3 3 3
5 5 5 5


 1 1 1
H
H H H H H H H H H H H H H H H H H H H H H H H H H H H H M
M H M H M H M H M H M H M H M H M H M H M H M H M H H M M H M
M M M M M M M M M M M M M M M M M M M M M M M M M M M M
M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M
H H H H C
 * */