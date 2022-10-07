#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <random>
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
#define bg begin
#define f_ first
#define s_ second
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
    char c=' ';int brace=0;
    if constexpr (std::is_same_v<T, vt<vt<int>>>) c='\n',brace=1;
    if constexpr (std::is_same_v<T, vt<vt<vt<int>>>>) c='\n',brace=1;
    if constexpr (std::is_same_v<T, vt<vt<ll>>>) c='\n',brace=1;
    if constexpr (std::is_same_v<T, vt<vt<vt<ll>>>>) c='\n',brace=1;
    if constexpr (std::is_same_v<T, vt<vt<double>>>) c='\n',brace=1;
    if constexpr (std::is_same_v<T, vt<vt<vt<double>>>>) c='\n',brace=1;
    //if(c=='\n')brace=1;
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
template<class T, class U> void vtini(vt<T> &v, U x, size_t n) {v=vt<T>(n, x);}
template<class T, class U> void vtini(vt<T> &v, U x, size_t n, size_t m...) {
    v=vt<T>(n);
    EACH(a, v)vtini(a, x, m);
}


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
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
const pair<int,int> pairdir[]={{0,1},{0,-1},{1,0},{-1,0}};
inline bool inboard(int y,int x,int n,int m){return y>=0 && x >=0 && y<n && x<m;}
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
// DFS(1,n)
// Recur([&](auto dfs, int u,int f)->void{dfs(f,u);})(0,-1);
using mint = modnum<MOD>;
const int LOGMAXN = 18;
const int MAXN = 2e5+20;
using pii=pair<int,int>;
//vector<int>vec[MAXN];
//int depth[MAXN],fa[MAXN][LOGMAXN];
template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            FOR(j,0,sz(jmp[k]))
                jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }
    T query(int a, int b) {
        assert(a < b); // or return inf if a == b
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};
struct LCA {
    int T = 0;
    vt<int> time, path, ret;
    RMQ<int> rmq;
    LCA(vector<vt<int>>& C) : time(sz(C)), rmq((dfs(C,0,-1), ret)) {}
    void dfs(vector<vt<int>>& C, int v, int par) {
        time[v] = T++;
        for (int y : C[v]) if (y != par) {
                path.push_back(v), ret.push_back(time[v]);
                dfs(C, y, v);
            }
    }
    int lca(int a, int b) {
        if (a == b) return a;
        tie(a, b) = minmax(time[a], time[b]);
        return path[rmq.query(a, b)];
    }
    //dist(a,b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}
};
//void readEdges(int m, vt<vt<int>>&vec){
void readEdges(int m,vt<vt<int>>&vec,int o){
    FOR(i,m){
        int a,b;read(a,b);
        a+=o,b+=o;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
}
//struct Node{
//    int v,id;
//    bool operator < (const Node &c)const{return v<c.v;}
//};
struct Node{
    int u,v,id;
    bool operator < (const Node &c)const{return v<c.v;}
};
template<class T>
class BIT{
public:
    vector<T>arr;
    //type==0:query range sum,update points
    //type==1:update range,query points  a1-a0,a2-a1,a3-a2,a4-a3
    //input vector cur start from 1
    BIT(vector<T>&cur, int type){
        arr.clear();
        arr=vector<T>(sz(cur),0);
        assert(type==1);
//        if(type==1)FOR(i,1,sz(cur))update(i,cur[i]-cur[i-1]);//,print(arr[i]);
        if(type==1)FOR(i,1,sz(cur))update(i,cur[i]);//,print(arr[i]);
        //print(arr);
    }
    void update(int x,T val) { while(x<sz(arr))  {  arr[x]+=val;  x+=(x&-x);}   }
    T query(int x) {  T res=0;  while(x>0)  {  res+=arr[x];  x-=(x&-x); } return res; }
};
void get_fail(vt<int>&p,vt<int>&f){
    int m=sz(p);
    f[0]=f[1]=0;
    for (int i = 1; i < m; ++i) {
        int j=f[i];
        while (j && p[i]!=p[j])j=f[j];
        f[i+1]=p[i]==p[j]?j+1:0;
    }
}
bool KMP(vt<int>& pattern,vt<int>& text){
    int m = sz(pattern);
    vector<int>f(m+1);
    get_fail(pattern,f);
    for (int i = 1,j=0;i< sz(text) ; ++i) {
        while (j&&pattern[j]!=text[i])j=f[j];
        if(pattern[j]==text[i])j++;
        if(j==m)return true;
    }
    return false;
}
void solve(){
    int n,k;
    read(n,k);
    vt<int> arr(n);
    vt<int> brr(n*2),crr(n);
    read(arr,crr);
    FOR(i,2*n)brr[i]=crr[i%n];

    if(k==0){
        print(arr==crr?"YES":"NO");
    }else if(n==2){
        if(k%2 && arr[0]==crr[1] && arr[1]==crr[0])print("YES");
        else if(k%2==0 && arr==crr)print("YES");
        else print("NO");
    }else{
        if(KMP(arr,brr))print("YES");
        else print("NO");
    }
}
int main() {
//    freopen("/home/csc/Online-Judge-Code/G/input.txt", "r", stdin);
//    freopen("/home/csc/Online-Judge-Code/G/output.txt2", "w", stdout);
//    freopen("/home/csc/Downloads/consecutive_cuts_chapter_2_input.txt", "r", stdin);
    freopen("/home/csc/Downloads/consecutive_cuts_chapter_2_input.txt", "r", stdin);
    freopen("/home/csc/Downloads/output.txt", "w", stdout);
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
    int t=1, i=1;
    read(t);
    while(t--) {
        cout << "Case #" << i << ": ";
        solve();
        ++i;
    }
    return 0;
}
/*
99
 1
2
1 2
10
2 4
2 1
5 7
3 10
8 6
6 1
1 3
4 7
9 6


4
1 2 2 3 3 4
15
 1 2 2 3
 3 4 4 5 4 6 4 7
 3 14 14 8 14 9 14 10
 3 15 15 11 15 12 15 13

 16
 1 2 2 3
 3 4    4 5    4 6    4 7
 3 14  14  8  14  9  14 10
 3 15  15 11  15 12  15 13
 3 16


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
 *
 99 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36
 99
 31
 230 231 232 233 234 235 236 237 238 239
 240 241 242 243 244 245 246 247 248 249
 250 251 252 253 254 255     257 258 259
 260 262



999
 5
20 10 30 10 20
3
1 8 1
6
7 6 6 8 5 8
6
14 3 8 10 15 4
4
1 100 100 1
3
40 10 10








 99
 -521613854 56777512 428978993
-180948782 170332536 141234994
 -208371359 112978477 228078842
243542549 225956954 64861504


 990906301

 *
4 2 1
 9 1 1
 5 1 0
 6 0 1
 1 0 0

 4 3 1
 9 1 1
 5 1 0
 6 0 1
 1 0 0


 99
 ?1?1??????
 111??????

 ????????????????


99
 1010 101
 101 1010
 0 1110000
 1001110000 1
 100111 1111

 10100 101110
 10001 1101

 * */
//#pragma clang diagnostic pop