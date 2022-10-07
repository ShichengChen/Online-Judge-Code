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
const int MAXN = 1e5+20;
const int LOGMAXN = 18;
ll const MOD=1e9+7;
int n,q,m;
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
void solve(){
    read(n);
    vector<ll>arr(n);
    read(arr,q);
    arr.insert(arr.begin(),0ll);
    BIT<ll>bit(arr,1);
    ll acc=0;
    FOR(i,2,n+1)if(arr[i]-arr[i-1]>0)acc+=arr[i]-arr[i-1];
    //FOR(k,1,n+1)print(bit.query(k));
    if(arr[1]+acc>0)print((arr[1]+acc+1)/2);
    else print((arr[1]+acc)/2);
    FOR(q){
        int l,r;ll a;read(l,r,a);
        if(l>1){
            arr[l]=bit.query(l);
            arr[l-1]=bit.query(l-1);
            ll dif=abs(arr[l]-arr[l-1]);
            if(arr[l]-arr[l-1]>=0 && a>=0)acc+=a;
            else if(arr[l]-arr[l-1]>=0 && a<=0)acc-=min(abs(a),dif);
            else if(arr[l]-arr[l-1]<=0 && a>=0)acc+=max(abs(a)-dif,0ll);

        }
        if(r<n){
            arr[r]=bit.query(r);
            arr[r+1]=bit.query(r+1);
            ll dif=abs(arr[r+1]-arr[r]);
            if(arr[r+1]>=arr[r] && a>=0)acc-=min(dif,a);
            else if(arr[r+1]>=arr[r] && a<=0)acc+=abs(a);
            else if(arr[r+1]<=arr[r] && a<=0)acc+=max(abs(a)-dif,0ll);
            else if(arr[r+1]<=arr[r] && a>=0) {}
        }
        //print(l,r);
        bit.update(l,a);
        bit.update(r+1,-a);
        //FOR(k,1,n+1)print(bit.query(k));
        arr[l]=bit.query(l),arr[r]=bit.query(r);
        if(arr[1]+acc>0)print((arr[1]+acc+1)/2);
        else print((arr[1]+acc)/2);
    }
}
int main() {
    //print(set<int>({1,2,3}).size());
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
    //freopen("/home/csc/Downloads/vivoparc/1.in", "r", stdin);
    //freopen("/home/csc/G/output.txt", "w", stdout);
    //print(-11/2);
    int t=1;
    //read(t);
    FOR(t) {
        //write("Case #", i+1, ": ");
        solve();
    }
    return 0;
}
/*
99

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