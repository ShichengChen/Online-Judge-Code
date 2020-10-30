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
const int d2i[4]={-1, 0}, d2j[4]={0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
const int MAXN = 3e5+20;
const int LOGMAXN = 18;
ll const MOD=998244353;



template<int N>struct KM {
    const int INF = 0x3f3f3f3f;
    int n;
    vector<int> G[N];
    int we[N][N];
    int dx[N], dy[N];
    int linker[N];
    bool vx[N], vy[N];
    void init(int nn) {
        n = nn;
        memset(we, 0, sizeof(we));
        FOR(n) G[i].clear();
    }
    void pushedge(int u, int v, int w) {
        G[u].push_back(v);
        we[u][v] = w;
    }
    bool match(int u){
        vx[u] = true;
        EACH(v,G[u]) {
            if (!vy[v] && we[u][v]==dx[u]+dy[v]){
                vy[v] = true;
                if (linker[v] == -1 || match(linker[v])){
                    linker[v] = u;
                    return true;
                }
            }
        }
        return false;
    }
    void update(){
        int cur = INF;
        FOR(u,n)if(vx[u])
        EACH(v,G[u]) if(!vy[v]) cur = min(cur, dx[u]+dy[v] - we[u][v]);
        FOR(n){
            if(vy[i]) dy[i] += cur;
            if(vx[i]) dx[i] -= cur;
        }
    }

    int solver() {
        FOR(n) {
            dx[i] = *max_element(we[i], we[i]+n);
            dy[i] = 0,linker[i] = -1;
        }
        FOR(u,n) {
            while (1){
                memset(vx,0,sizeof(vx));
                memset(vy,0,sizeof(vy));
                if(match(u)) break; else update();
            }
        }
        int ans=0;
        FOR(n)if(linker[i]!=-1)ans+=we[linker[i]][i];
        return ans;
    }
};


int n,m;
void solve(){
    vector<string>s(2);
    vector<vector<int>>arr(2,vector<int>(26));
    read(s);
    FOR(l,2){
        FOR(i,26){
            if(s[l][i]=='A')arr[l][i]=12;
            else if(s[l][i]=='K')arr[l][i]=11;
            else if(s[l][i]=='Q')arr[l][i]=10;
            else if(s[l][i]=='J')arr[l][i]=9;
            else if(s[l][i]=='T')arr[l][i]=8;
            else arr[l][i]=s[l][i]-'2';
        }
    }
    //FOR(2)sort(all(arr[i]),greater<>());
    FOR(2)sort(all(arr[i]));
    //print(arr);
    KM<60>solver;
    solver.init(26);
    FOR(i,26)FOR(j,26){
        if(arr[1][i]==arr[0][j])
            solver.pushedge(i,j,1);
        else if(arr[1][i]>arr[0][j])
            solver.pushedge(i,j,2);
        else solver.pushedge(i,j,0);
    }
    print(solver.solver());
}
int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
    //freopen("/home/csc/Downloads/vivoparc/1.in", "r", stdin);
    //freopen("/home/csc/G/output.txt", "w", stdout);
    int t=1;
    read(t);
    FOR(t) {
        //write("Case #", i+1, ": ");
        solve();
    }
    return 0;
}
/*
8 5
A11111AA
AA7B111A
111BB111
11BBB111
11BBB11B

3 1
A0B


7 7 1 2 5
1 2
2 3
 2 5
 3 4
 5 6
 6 7

7 6 1 2 5
1 2
2 3
 2 5
 3 4
 5 6
 6 7

 6 6 1 2 5
1 2
2 3
 2 5
 3 4
 5 6




10 2 2
9 7
10 6
3 2 4 8
1 3
1 6
1 5
1 10
1 7
0
1 9
0
0

7 2 1
5 4
6
3 2 3 4
1 5
1 6
1 7
0
0
0


RGBW
WWWW
WWWW
RGBW

RGBW
WWWW
WWWW
RGWB




 8 7
 1 2 1
 1 3 1
 1 4 1
 1 5 3
 1 6 2
 1 7 2
 1 8 2
 2 3 4 5 6 7 8

 3 1
 1 2 1
 1 1 1 3 3 3 3

 1 1
 1 1 1
 1 1 1 1 1 1 1

 2 1
 1 2 1
 2 2 2 2 2 2 2


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