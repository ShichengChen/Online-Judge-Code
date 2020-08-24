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
typedef long long ll;
const int MAXN =5e5+20;
int n,sum;
vector<vector<int>>arr;
ll f(int m){
    //print("m",m);
    ll extra=0;
    ll removed=0;
    ll maxn=sum;
    multiset<int,greater<>>se;
    EACH(i,arr)se.insert(i[1]+i[0]);
    int succ=1;
    FOR(n){
        if(sum>=arr[i][1]+arr[i][0]){
            extra+=arr[i][0];
            if(succ)umax(maxn,sum+extra-removed);
        }
        else if(m>0){
            removed+=arr[i][0];
            se.erase(se.find(arr[i][1]+arr[i][0]));
            m--;
            if(*(se.begin())<=sum-removed)umax(maxn,sum+extra-removed);
            else succ=0;
            if(m==0 && *(se.begin())>sum-removed)break;
            //if()return extra+sum-removed;
        }
        else break;
        print("i",m,i,maxn,succ);
        if(i==n-1 && *(se.begin())<=sum-removed)return 1e18;
    }
    return maxn;
}
void solve() {
    read(n);
    vti(arr,0,n,2);
    read(arr);
    //print(arr);
    sum=0;
    EACH(i,arr)sum+=i[0];
    ll initime=sum;
    int l=0,r=n-1;
    int idx=0;
    for (;l<n;l++) {
        ll cur=f(l);
        //print("l",l,cur);
        if(initime<1e18 && cur>initime){
            idx=l;
            initime=cur;
        }
    }
//    while (l<r){
//        int mid=(l+r+1)/2;
//        ll cur=f(mid);
//        print(mid,cur);
//        if(initime<1e18 && cur>initime){
//            l=mid;
//            initime=cur;
//        }
//        else r=mid-1;
//    }
    if(initime>=1e18){
        write(idx);
        print(" INDEFINITELY");
    }
    else{
        write(idx," ");
        print(initime);
    }
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

4
4
30 17
1 17
5 10
10 3



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