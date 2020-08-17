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
void DBG() {cout << "]" << endl;}
template<class H, class... T> void DBG(H h, T... t) {
    cout << to_string(h);
    if(sizeof...(t))
        cout << ", ";
    DBG(t...);
}
#define _DEBUG
#ifdef _DEBUG
#define debug(...) cout << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
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
const int MAXN = 5e5+50;
const int LOGMAXN = 18;
ll const MOD=1e9+7;
int n,m;
int in[MAXN],vis[MAXN];
vector<int>G;
vector<int>st,loop;
void dfs(int u){
    vis[u]=2;
    st.push_back(u);
    int v=G[u];
    if(vis[v]==2){
        while(sz(st)){
            loop[st.back()]=1;
            if(st.back()==v)break;
            st.pop_back();
        }
    }
    else dfs(v);
    vis[u]=1;
}
void solve() {
    read(n);
    G=vector<int>(n);
    loop=vector<int>(n+1,0);
    vector<int>mark(n+1,0);
    read(G);
    G.insert(G.begin(),0);
    FOR(i,1,n+1)in[G[i]]++;
    FOR(i,1,n+1)if(!vis[i]){
        st.clear();
        dfs(i);
    }
    //print(loop);
    queue<int>que;
    int cnt=0;
    FOR(i,1,n+1)if(!in[i])que.push(i),mark[i]=1,cnt++;
    while(!que.empty()){
        int u=que.front();que.pop();
        int v=G[u];
        if(mark[u]==2 && !mark[v])mark[v]=1;
        if(mark[u]==1)mark[v]=2;
        in[v]--;
        if(!in[v])que.push(v);
    }
    FOR(i,1,n+1)if(loop[i] && (in[i] && mark[i])){
        if(!mark[i])mark[i]=1;
        loop[i]=0;
        for (int u = G[i],pre=i; u != i; u=G[u],pre=G[pre]) {
            loop[u]=0;
            if(mark[u])continue;
            if(mark[pre]==1 || mark[G[u]]==1)mark[u]=2;
            else mark[u]=1;
        }
    }
    FOR(i,1,n+1)if(loop[i]){
        if(!mark[i])mark[i]=1;
        loop[i]=0;
        for (int u = G[i],pre=i; u != i; u=G[u],pre=G[pre]) {
            loop[u]=0;
            if(mark[u])continue;
            if(mark[pre]==1 || mark[G[u]]==1)mark[u]=2;
            else mark[u]=1;
        }
    }

    cnt=0;
    int ans=0;
    FOR(i,1,n+1)cnt+=(mark[i]==1),ans+=(mark[i]>0);
    assert(ans==n);
    print(cnt);
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

5
2 1 1 5 4
6
2 1 4 3 6 5
6
2 3 1 5 6 4
8
2 3 4 2 6 7 8 6
10
2 3 4 5 2 7 8 9 10 7

 * */