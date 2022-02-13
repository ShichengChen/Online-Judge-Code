#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
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
    int n;
    read(n);
    vt<int>w(n);
    vt<ll>d(n,0);
    vt<vt<int>>vec(n);
    read(w);
    FOR(n-1){
        int u,v;
        read(u,v);
        vec[u-1].push_back(v-1);
        vec[v-1].push_back(u-1);
    }
    if(n==1){print(w[0]);return;}
    auto DFS=Recur([&](auto dfs, int u,int f)->void{
        d[u]=w[u];
        ll maxn=0;
        EACH(v,vec[u])if(v!=f){
            dfs(v,u);
            umax(maxn,d[v]);
        }
        d[u]+=maxn;
    });
    multiset<ll,greater<>>se={0,0};
    EACH(v,vec[0]){
        DFS(v,0);
        se.insert(d[v]);
    }
    auto it=se.begin();it++;
    print(*se.begin()+w[0]+*it);
}
struct Point {
    double x, y;
    Point(double x=0, double y=0):x(x),y(y) { }
};
const double eps = 1e-8;
int dcmp(double x) {
    if(fabs(x) < eps) return 0; else return x < 0 ? -1 : 1;
}
bool operator == (const Point& a, const Point &b) {
    return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;
}
typedef Point Vector;
Vector operator + (const Vector& A, const Vector& B) { return Vector(A.x+B.x, A.y+B.y); }
Vector operator - (const Point& A, const Point& B) { return Vector(A.x-B.x, A.y-B.y); }
Vector operator * (const Vector& A, double p) { return Vector(A.x*p, A.y*p); }
Vector operator / (const Vector& A, double p) { return Vector(A.x/p, A.y/p); }
double Cross(const Vector& A, const Vector& B) { return A.x*B.y - A.y*B.x; }
double Dot(const Vector& A, const Vector& B) { return A.x*B.x + A.y*B.y; }
bool SegmentProperIntersection(const Point& a1, const Point& a2, const Point& b1, const Point& b2) {
    double c1 = Cross(a2-a1,b1-a1), c2 = Cross(a2-a1,b2-a1),
            c3 = Cross(b2-b1,a1-b1), c4=Cross(b2-b1,a2-b1);
    return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}
bool OnSegment(const Point& p, const Point& a1, const Point& a2) {
    return dcmp(Cross(a1-p, a2-p)) == 0 && dcmp(Dot(a1-p, a2-p)) < 0;
}

bool InTriangle2D(vector<double> point, vector<vector<double>> triangle) {
    Point cpoint(point[0],point[1]);
    vector<Point>cpoints;
    for (int i = 0; i < (int)triangle.size(); ++i)
        cpoints.emplace_back(triangle[i][0],triangle[i][1]);
    cpoint+(cpoint-cpoints[2])*1000
    bool c01= SegmentProperIntersection(cpoint,cpoints[2],cpoints[1],cpoints[0]);
    bool c02= SegmentProperIntersection(cpoint,cpoints[1],cpoints[2],cpoints[0]);
    bool c12= SegmentProperIntersection(cpoint,cpoints[0],cpoints[1],cpoints[2]);
    bool d01 = OnSegment(cpoint,cpoints[0],cpoints[1]);
    bool d02 = OnSegment(cpoint,cpoints[0],cpoints[2]);
    bool d12 = OnSegment(cpoint,cpoints[1],cpoints[2]);
    bool e01 = OnSegment(cpoints[0],cpoint,cpoints[1])||OnSegment(cpoints[1],cpoint,cpoints[0]);
    bool e02 = OnSegment(cpoints[0],cpoint,cpoints[2])||OnSegment(cpoints[2],cpoint,cpoints[0]);
    bool e12 = OnSegment(cpoints[1],cpoint,cpoints[2])||OnSegment(cpoints[2],cpoint,cpoints[1]);
    bool notClick=true;
    for (int i = 0; i < (int)triangle.size(); ++i)
        notClick=notClick&&(!(cpoints[i]==cpoint));
    bool noIntersection=((!c01)&&(!c02)&&(!c12));
    bool notOnLines=(!d01)&&(!d02)&&(!d12);
    bool notGeneralLines=(!e01)&&(!e02)&&(!e12);
    //return (d01||d02||d12)||((!c01)&&(!c02)&&(!c12));
    return noIntersection&&notOnLines&&notGeneralLines&&notClick;
}
int main() {
/*
2
0
1
3
2
0 0
0 2
2 0
 * */


//    ios::sync_with_stdio(0);
//    cin.tie(0);
//freopen("/home/csc/Downloads/gold_mine_chapter_1_input.txt", "r", stdin);
//freopen("/home/csc/Downloads/output.txt", "w", stdout);
//freopen("/home/csc/Online-Judge-Code/G/output.txt", "w", stdout);
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
 4
 3 3
 4 5 1
 0 0 0 0
 1 2 4
 0 0 0 0
 1 3 4
 0 0 0 0

  3 3
 5 3 1
 0 0 0 0
 1 2 4
 0 0 0 0
 1 3 4
 0 0 0 0

 3 3
 3 1 3
 0 0 0 0
 1 2 4
 0 0 0 0
 1 3 4
 0 0 0 0

 3 3
 1 2 2
 0 0 0 0
 1 2 4
 0 0 0 0
 1 3 4
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