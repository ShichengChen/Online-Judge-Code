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
template<size_t S> string to_string(bitset<S> b) {
    string res;
    FOR(S)
        res+=char('0'+b[i]);
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
#define dbg(...) 0
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

template<class T, class U> void vti(vt<T> &v, U x, size_t n) {
    v=vt<T>(n, x);
}
template<class T, class U> void vti(vt<T> &v, U x, size_t n, size_t m...) {
    v=vt<T>(n);
    EACH(a, v)vti(a, x, m);
}

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct SuffixArray {
    static const int MAXN = 4001 * 100 + 10;
    int s[MAXN];      // 原始字符数组（最后一个字符应必须是0，而前面的字符必须非0）
    int sa[MAXN];     // 后缀数组
    int t[MAXN], t2[MAXN], c[MAXN]; // 辅助数组
    int n; // 字符个数
    void build_sa(int m){
        int *x=t,*y=t2;
        memset(c,0,sizeof(int)*(m+5));
        FOR(n)c[x[i]=s[i]]++;
        FOR(m)c[i+1]+=c[i];
        FOR(i,n-1,-1,-1)sa[--c[x[i]]]=i;
//        vector<int>vc(sa,sa+n);
//        print(vc);
//        vc=vector<int>(s,s+n);
//        print(vc);
//        print();
        for (int k = 1,p=1; k <= n && p<n; k*=2,m=p) {
            p=0;
            FOR(i,n-k,n)y[p++]=i;
            FOR(n)if(sa[i]>=k)y[p++]=sa[i]-k;
//            vector<int>vc(y,y+n);
//            print(vc);
            memset(c,0,sizeof(int)*(m+5));
            FOR(n)c[x[y[i]]]++;
            FOR(m)c[i+1]+=c[i];
            FOR(i,n-1,-1,-1)sa[--c[x[y[i]]]]=y[i];
//            vc=vector<int>(sa,sa+n);
//            print(vc);
//            print();
            p=1;y[sa[0]]=0;
            FOR(i,1,n)y[sa[i]]=(x[sa[i]]==x[sa[i-1]] && x[sa[i]+k]==x[sa[i-1]+k])?p-1:p++;
            swap(x,y);
        }
    }
};
const int MAXN = 4e5+50;
const int LOGMAXN = 18;
ll const MOD=1e9+7;
void solve() {
    SuffixArray sa;
    string s;cin>>s;
    s+=('a'-1);
    int slen=s.length();
    sa.n=slen;
    vector<int>num(27,0);
    FOR(slen)num[s[i]-('a'-1)]=1;
    FOR(i,1,27)num[i]+=num[i-1];
    FOR(slen)sa.s[i]=num[s[i]-('a'-1)];
    sa.build_sa(num[26]);
    FOR(sa.n)cout << sa.sa[i] << " ";
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
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


 * */