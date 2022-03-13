#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<class T>
using ordered_greater_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
#define lcnt (cnt<<1)
#define rcnt (cnt<<1|1)
#define vt vector
#define pb push_back
#define mp make_pair
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
struct Point {
    double x, y;
    Point(double x=0, double y=0):x(x),y(y) { }
};
template<class A> void read(vt<A>& v);
template<class A> void read(Point& v);
template<class A, size_t S> void read(array<A, S>& a);
template<class H, class T> void read(pair<H,T>&c);
template<class H, class T> void read(Point &c);
template<class T> void read(T& x) {cin >> x;}
void read(double& d) {string t;read(t);d=stod(t);}
void read(long double& d) {string t;read(t);d=stold(t);}
void read(Point &c){read(c.x);read(c.y);}
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
string to_string(Point c) {return to_string(c.x)+":"+to_string(c.y);}
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
    if constexpr (std::is_same_v<T, vt<vt<ll>>>) c='\n';
    if constexpr (std::is_same_v<T, vt<vt<int>>>) c='\n';
    if constexpr (std::is_same_v<T, vt<vt<double>>>) c='\n';
    if constexpr (std::is_same_v<T, vt<vt<vt<int>>>>) c='\n';
    if constexpr (std::is_same_v<T, vt<vt<vt<ll>>>>) c='\n';
    if constexpr (std::is_same_v<T, vt<vt<vt<double>>>>) c='\n';
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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int64_t random_long(long long l = LLONG_MIN,long long r = LLONG_MAX){
    uniform_int_distribution<int64_t> generator(l,r);
    return generator(rng);
}
struct custom_hash { // Credits: https://codeforces.com/blog/entry/62393
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    template<typename L, typename R>
    size_t operator()(pair<L,R> const& Y) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31ull + Y.second + FIXED_RANDOM);
    }
};
template<class T, class U> void vti(vt<T> &v, U x, size_t n) {v=vt<T>(n, x);}
template<class T, class U> void vti(vt<T> &v, U x, size_t n, size_t m...) {
    v=vt<T>(n);
    EACH(a, v)vti(a, x, m);
}
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
inline bool inboard(int y,int x,int n,int m){return y>=0 && x >=0 && y<n && x<m;}
const int LOGMAXN = 18;
//ll const MOD=998244353;
ll const MOD=1e9+7;

template <int MOD_> struct modnum {
    static constexpr int MOD = MOD_;
    static_assert(MOD_ > 0, "MOD must be positive");
private:
    using ll = long long;
    int v;
    static int minv(int a, int m) {
        a %= m;
        assert(a);
        return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
    }
public:
    modnum() : v(0) {}
    modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
    explicit operator int() const { return v; }
    friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
    friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }
    friend string to_string(modnum& n){return to_string(n.v);}
    friend void read(int &n){cin>>n;}
    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

    modnum inv() const {
        modnum res;
        res.v = minv(v, MOD);
        return res;
    }
    friend modnum inv(const modnum& m) { return m.inv(); }
    modnum neg() const {
        modnum res;
        res.v = v ? MOD-v : 0;
        return res;
    }
    friend modnum neg(const modnum& m) { return m.neg(); }

    modnum operator- () const {
        return neg();
    }
    modnum operator+ () const {
        return modnum(*this);
    }

    modnum& operator ++ () {
        v ++;
        if (v == MOD) v = 0;
        return *this;
    }
    modnum& operator -- () {
        if (v == 0) v = MOD;
        v --;
        return *this;
    }
    modnum& operator += (const modnum& o) {
        v += o.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    modnum& operator -= (const modnum& o) {
        v -= o.v;
        if (v < 0) v += MOD;
        return *this;
    }
    modnum& operator *= (const modnum& o) {
        v = int(ll(v) * ll(o.v) % MOD);
        return *this;
    }
    modnum& operator /= (const modnum& o) {
        return *this *= o.inv();
    }
    friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
    friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

template <typename T,typename U>
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {
    return {l.first+r.first,l.second+r.second};
}
template <typename T,typename U>
std::pair<T,U> operator+(const std::pair<T,U> & l,T &r) {return l+mp(r,r);}
template <typename T,typename U>
std::pair<T,U> operator- (const std::pair<T,U> & l) {return mp(-l.first,-l.second);}
template <typename T,typename U>
std::pair<T,U> operator-(const std::pair<T,U> & l,const std::pair<T,U> & r) {return l+(-r);}
template <typename T,typename U>
std::pair<T,U> operator-(const std::pair<T,U> & l,T &r) {return l-mp(r,r);}
template <typename T,typename U>
std::pair<T,U> operator*(const std::pair<T,U> & l,const std::pair<T,U> & r) {return {l.first*r.first,l.second*r.second};}
template <typename T,typename U>
std::pair<T,U> operator*(const std::pair<T,U> & l,T &r) {return l*mp(r,r);}
template <typename T,typename U>
bool checkPairRange(const std::pair<T,U> & l,T lx0,T lx1, U ly0, U ly1){
    return l.first>=lx0 && l.first<lx1 && l.second>=ly0 && l.second<ly1;
};
template<class F>
struct fHelper:F{
    explicit fHelper(F&& f):F(forward<F>(f)){}
    template<typename... Args>
    decltype(auto) operator()(Args&&... args) const{
        return F::operator()(*this,forward<Args>(args)...);
    }
};
template<class F>
inline decltype(auto) Recur(F&&f){return fHelper<F>{forward<F>(f)};}
// auto DFS=Recur([&](auto dfs, int u,int f)->void{dfs(v,u);});
// DFS(u,f);
// Recur([&](auto dfs, int u,int f)->void{dfs(f,u);})(0,-1);
using mint = modnum<MOD>;
const int MAXN = 2e5+20;
void solve() {
    string s0,s1;
    read(s0,s1);
    int ans=0;
    if(s0==s1){print(0);return;}
    if(s0=="0")ans=1,s0="1";
    //if(s0==s1){print(1);return;}
    auto str2vec=[&](string s){
        vt<int>vec;
        s+="2";
        for (int i = 1,j=0; i < sz(s); ++i)
            if(s[i]!=s[i-1])vec.push_back(i-j),j=i;
        return vec;
    };
    vt<int>v0=str2vec(s0),v1=str2vec(s1);
    //debug(v0,v1);
    if(s1=="0"){ print(sz(v0));return;}
    if(sz(v0)+(s0.back()=='1')< sz(v1)){ print("IMPOSSIBLE");return;}
    if(sz(v0)< sz(v1))v0.push_back(0),s0+='0';
    auto cmpv=[&](int idx){
        for (int i = 0; i+idx < sz(v0); ++i) {
//            if(i+idx==sz(v0)-1 && !((!idx && v0[idx+i]<=v1[i]) || (idx && s0.back()=='0' && v0[idx+i]<=v1[i]) ||
//                    (idx && s0.back()==1 && v0[idx+i]==v1[i])))return false;
            if(i+idx==sz(v0)-1 && !((!idx && v0[idx+i]<=v1[i] && s0.back()=='0') ||
                                    (!idx && v0[idx+i]==v1[i] && s0.back()=='1') ||
                                    (idx && (sz(v0)> sz(v1)||s0.back()=='0') && v0[idx+i]<=v1[i]) ||
                                    (idx && sz(v0)==sz(v1) && v0[idx+i]==v1[i])))return false;
            if(i+idx<sz(v0)-1 && v1[i]!=v0[i+idx])return false;
        }
        return true;
    };
    auto calculate=[&](int idx){
        int len= sz(v0)-idx;
        //debug(idx,len);
        if(idx== sz(v0)){
            ans+=accumulate(all(v1),0)+ max(sz(v1)-len,idx);
        }else{

            ans+=(v1[len-1]-v0.back());
            //debug(ans);
            ans+= max(sz(v1)-len,idx)+ accumulate(v1.begin()+len,v1.end(),0);
        }
        print(ans);
    };

    for (int i = sz(v0)- sz(v1); i < sz(v0); ++i) {
        if(cmpv(i)){calculate(i);return;}
    }
    calculate(sz(v0));
}
int main() {


    vt<int>vec={1,2,3,4},ans(4),ordinals;
    std::generate(vec.begin(), vec.end(), [n = 0] () mutable { return n++; });
    print(vec);
    std::transform(vec.begin(), vec.end(), std::back_inserter(ordinals),
                   [](unsigned char c) -> std::size_t { return c; });
    print(ordinals);
    transform(ordinals.cbegin(), ordinals.cend(), ordinals.cbegin(),
              ordinals.begin(), std::plus<>{});
    print(ordinals);
//    int a[3]={1,2,3};
//    print(1[a]);
//    freopen("/home/csc/Online-Judge-Code/G/input.txt", "r", stdin);
//    freopen("/home/csc/Online-Judge-Code/G/output.txt2", "w", stdout);
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
re-read the problem
re-read the code
create some samples
go through each variable!
check boundary situations
draw graphs!

listen to instrumental songs only.
dp? binary search? math?
find the essentials in the problem instead of trying different samples
solving the problem from forward and backward directions.
abstract the problem so that I can write condensed code.
changed variables vs unchanged variables
formulate the problem by math notations
 */



/*

99
 1010 101
 101 1010
 0 1110000
 1001110000 1
 100111 1111

 10100 101110
 10001 1101

 * */