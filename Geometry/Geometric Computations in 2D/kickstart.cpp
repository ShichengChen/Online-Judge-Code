//https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435bae/0000000000888d45#problem

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
    //friend void read(int &n){cin>>n;}
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

const double eps = 1e-8;
int dcmp(double x) { if(fabs(x) < eps) return 0; else return x < 0 ? -1 : 1; }

const double PI = acos(-1.0);
double torad(double deg) { return deg/180 * PI; }



typedef Point Vector;

Vector operator + (const Vector& A, const Vector& B) { return Vector(A.x+B.x, A.y+B.y); }
Vector operator - (const Point& A, const Point& B) { return Vector(A.x-B.x, A.y-B.y); }
Vector operator * (const Vector& A, double p) { return Vector(A.x*p, A.y*p); }
Vector operator / (const Vector& A, double p) { return Vector(A.x/p, A.y/p); }
bool operator < (const Point& a, const Point& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
bool operator == (const Point& a, const Point &b) {
    return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;
}
bool operator != (const Point& a, const Point &b) {return !(a==b);}
double Dot(const Vector& A, const Vector& B) { return A.x*B.x + A.y*B.y; }
double Det(const Vector& A, const Vector& B){return A.x*B.y - A.y*B.x;}
double Length(const Vector& A) { return sqrt(Dot(A, A)); }
double Angle(const Vector& A, const Vector& B) { return acos(Dot(A, B) / Length(A) / Length(B)); }
double Rad2pi(const Vector& A, const Vector& B){return atan2(Det(A,B), Dot(A,B));  }
double Cross(const Vector& A, const Vector& B) { return A.x*B.y - A.y*B.x; }
Point GetLineIntersection(const Point& P, const Point& v, const Point& Q, const Point& w) {
    Vector u = P-Q;
    double t = Cross(w, u) / Cross(v, w);
    return P+v*t;
}
double DistanceToSegment(const Point& P, const Point& A, const Point& B) {
    if(A == B) return Length(P-A);
    Vector v1 = B - A, v2 = P - A, v3 = P - B;
    if(dcmp(Dot(v1, v2)) < 0) return Length(v2);
    else if(dcmp(Dot(v1, v3)) > 0) return Length(v3);
    else return fabs(Cross(v1, v2)) / Length(v1);
}
Vector Rotate(const Vector& A, double rad) {
    return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));
}
bool SegmentProperIntersection(const Point& a1, const Point& a2, const Point& b1, const Point& b2) {
    double c1 = Cross(a2-a1,b1-a1), c2 = Cross(a2-a1,b2-a1),
            c3 = Cross(b2-b1,a1-b1), c4=Cross(b2-b1,a2-b1);
    return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}
bool OnSegment(const Point& p, const Point& a1, const Point& a2) {
    return dcmp(Cross(a1-p, a2-p)) == 0 && dcmp(Dot(a1-p, a2-p)) < 0;
}
Vector Normal(Vector A) {
    double L = Length(A);
    return Vector(-A.y/L, A.x/L);
}
Point GetLineProjection(Point P, Point A, Point B) {
    Vector v = B-A;
    return A+v*(Dot(v, P-A) / Dot(v, v));
}
double DistanceToLine(Point P, Point A, Point B) {
    Vector v1 = B - A, v2 = P - A;
    return fabs(Cross(v1, v2)) / Length(v1); // 如果不取绝对值，得到的是有向距离
}
bool OnLine(Point P, Point A, Point B){return dcmp(DistanceToLine(P,A,B))==0;}
int IsPointInPolygon(const Point& p, const vector<Point> poly){
    int wn = 0;
    int n = poly.size();
    for(int i = 0; i < n; i++){
        const Point& p1 = poly[i];
        const Point& p2 = poly[(i+1)%n];
        if(p1 == p || p2 == p || OnSegment(p, p1, p2)) return -1; // 在边界上
        int k = dcmp(Cross(p2-p1, p-p1));
        int d1 = dcmp(p1.y - p.y);
        int d2 = dcmp(p2.y - p.y);
        if(k > 0 && d1 <= 0 && d2 > 0) wn++;
        if(k < 0 && d2 <= 0 && d1 > 0) wn--;
    }
    if (wn != 0) return 1; // 内部
    return 0; // 外部
}
void solve() {
    int n;
    read(n);
    vt<Point>arr(n);
    read(arr);
    {
        Point cur;read(cur);
        FOR(n)arr[i]=arr[i]-cur;
    }
//print(arr);
//    sort(all(arr),[&](Point a,Point b){
//        double r0= Rad2pi(Point(0,0),a),r1=Rad2pi(Point(0,0),b);
//        if(dcmp(r0-r1)==0)return Length(a)< Length(b);
//        return r0<r1;
//    });
    double ans=1e15;
    vt<vt<vt<double>>>d(n,vt<vt<double>>(n,vt<double>(2,1e15)));
    auto updated=[&](Point cur, int i,int j){
        if(OnLine(cur,arr[i],arr[j]))return;
        double d0=Length(arr[i]-cur);
        double d1=Length(arr[j]-cur);
        umin(d[i][j][Cross(arr[j]-arr[i],cur-arr[j])>0],d0+d1);
    };
    FOR(i,0,n)FOR(j,i+1,n)FOR(k,j+1,n){
                //print(IsPointInPolygon(Point({0,0}),{arr[i],arr[j],arr[k]}));
                //print(arr[i],arr[j],arr[k]);
        if(IsPointInPolygon(Point({0,0}),{arr[i],arr[j],arr[k]})==1){
            umin(ans, Length(arr[i]-arr[j])+Length(arr[i]-arr[k])+
                            Length(arr[k]-arr[j]));
        }
        updated(arr[k],i,j);
        updated(arr[j],i,k);
        updated(arr[i],k,j);
    }
    FOR(i,0,n)FOR(j,i+1,n){
        if(arr[i]!=Point({0,0}) && arr[j]!=Point({0,0}) &&
        OnSegment(Point(0,0),arr[i],arr[j])){
            umin(ans,d[i][j][0]+d[i][j][1]);
        }
    }
    if(ans>=1e15)print("IMPOSSIBLE");
    else print(ans);

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
3 5 1
2 2 3 4

 1 1 1
1 1 1 1

 5 4 1
 2 2 3 3


 * */
