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
    return uniform_int_distribution<>(a, b)(mt_rng);
}
template<class T, class U> void vti(vt<T> &v, U x, size_t n) {v=vt<T>(n, x);}
template<class T, class U> void vti(vt<T> &v, U x, size_t n, size_t m...) {
    v=vt<T>(n);
    EACH(a, v)vti(a, x, m);
}
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
const int MAXN = 4e3+100;
const int MAXM = 600000 +100;
const int LOGMAXN = 18;
//ll const MOD=998244353;
ll const MOD=1e9+7;
using namespace std;
clock_t timebegin;
int n,m;
ll mindis=0,curdis=0;
int curcover[MAXN],bestcover[MAXN],vis[MAXN],tempCover[MAXN];
int w[MAXN],inde[MAXN];
ll childw[MAXN];
multiset<pair<ll,int>>se;
vector<int>vec[MAXN];
vector<int>vecrg[MAXN];
int vid[MAXN];
struct Edges{
    int u,v;
    bool operator < (const Edges& c)const{
        //return abs(w[u]-w[v])>abs(w[c.u]-w[c.v]);
        //return max(childw[u]-w[u],childw[v]-w[v])>max(childw[c.u]-w[c.u],childw[c.v]-w[c.v]);
        return min(w[u],w[v])<min(w[c.u],w[c.v]);
    }
}edges[MAXM];

inline bool timecheck(){
    clock_t timeend = clock();
    double elapsed_secs = double(timeend - timebegin) / CLOCKS_PER_SEC;
    return elapsed_secs>=1.99;
}
inline void removeUeslessVertex(ll &curval,int u,int *cover){
    for(int &v:vec[u])if(!cover[v])return;
    cover[u]=0,curval-=w[u];
}
inline void removeUseless(ll &curval,int *cover){
    FOR(i,n)if(cover[vid[i]])
            removeUeslessVertex(curval,vid[i],cover);
}
inline ll optRemove(int u,int *cover){
    ll dif=-w[u];
    memset(vis,0,sizeof(int)*n);
    cover[u]=0;
    for(int &v:vec[u]){
        if(cover[v])vis[v]=1;
        else if(!cover[v])cover[v]=1,vis[v]=2,dif+=w[v];
    }
    for(int &v:vec[u]){
        if(vis[v]!=2)continue;
        for(int &vv:vec[v]){
            if(vis[vv] || !cover[vv])continue;
            vis[vv]=1;
            removeUeslessVertex(dif,vv,cover);
        }
        if(timecheck())return dif;
    }
    return dif;
}
inline ll optAdd(int u,int *cover){
    ll dif=w[u];
    cover[u]=1;
    for(int &v:vec[u]){
        if(cover[v]){
            removeUeslessVertex(dif,v,cover);
            if(timecheck())return dif;
        }
    }
    return dif;
}
void solve() {
    read(n,m);
    FOR(n){
        read(w[i]);
        vid[i]=i;
    }
    FOR(m){
        int u,v;read(u,v);
        vec[u].push_back(v);
        vec[v].push_back(u);
        inde[v]++,inde[u]++;
        edges[i]={u,v};
    }
    FOR(u,n)for(int v:vec[u])childw[u]+=w[v];
    FOR(u,n)sort(all(vec[u]),[&](int l,int r){return w[l]>w[r];});
    //FOR(u,n)sort(all(vec[u]),[&](int l,int r){return childw[l]-w[l]<childw[r]-w[r];});

    FOR(q,100000){
        //print(q);
        if(q>=0 && q<=2)sort(edges,edges+m);
        if(q>2)shuffle(edges,edges+m,std::default_random_engine(q));
        //shuffle(edges,edges+m,std::default_random_engine(q));
        if(q%3==0)sort(vid,vid+n,[&](int l,int r){return w[l]>w[r];});
        if(q%3==1)sort(vid,vid+n,[&](int l,int r){return (ll)w[l]*inde[l]>(ll)w[r]*inde[r];});
        if(q%3==2)sort(vid,vid+n,[&](int l,int r){return inde[l]<inde[r];});
//        if(q==0){FOR(n)write(w[vid[i]]," ");print();}
//        if(q==2){FOR(n)write(inde[vid[i]]," ");print();}
        memset(curcover,0,sizeof(int)*n);
        curdis=0;
        FOR(m){
            int u=edges[i].u,v=edges[i].v;
            if(curcover[v] || curcover[u])continue;
            int c;
            if(childw[u]-w[u]>childw[v]-w[v])c=u;
            else if(childw[u]-w[u] < childw[v]-w[v])c=v;
            else if(inde[u]>inde[v])c=u;
            else c=v;
            curcover[c] = 1,curdis+=w[c];
            for (int vc:vec[c]) childw[vc]-=w[c];
        }

//        FOR(m){
//            int u=edges[i].u,v=edges[i].v;
//            if(curcover[v] || curcover[u])continue;
//            int c;
//            if(w[u]<w[v])c=u;
//            else if(w[u] > w[v])c=v;
//            else if(inde[u] > inde[v])c=u;
//            else c=v;
//            curcover[c]=1,curdis+=w[c];
//        }
        removeUseless(curdis,curcover);
        if(!q){
            //print(curdis);
            mindis=curdis;
            memcpy(bestcover,curcover,n*sizeof(int));
        }
        int unchangecnt=0;
        while(1){
            if(timecheck())break;

            int change=0;
            int purerandom=1;
            if(!purerandom)se.clear();
            FOR(n){
                //print(i);
                int u=vid[i];
                if(!curcover[u]){
                    memcpy(tempCover, curcover, sizeof(int) * n);
                    ll dif = optAdd(u, tempCover);
                    if (dif < 0) {
                        change = 1;
                        curdis += dif;
                        memcpy(curcover, tempCover, sizeof(int) * n);
                    }
                }else{
                    memcpy(tempCover, curcover, sizeof(int) * n);
                    ll dif = optRemove(u, tempCover);
                    if(!purerandom)se.insert({-dif,u});
                    if (dif < 0) {
                        change = 1;
                        curdis += dif;
                        memcpy(curcover, tempCover, sizeof(int) * n);
                    }
                }

                if(timecheck())break;
            }
            //if(n<=1000 || unchangecnt>=2)break;
            if(!change){
                unchangecnt++;
                if(umin(mindis,curdis))memcpy(bestcover,curcover,n*sizeof(int));
                //{ll cc=0;FOR(n)if(bestcover[i])cc+=w[i];assert(cc==mindis);}
                //bigger to small 32
                //small to big 28
                //pure random 4 33
                for (int i = 0,cc=0; i < 200&&cc<5; ++i) {
                    int u;
                    if(purerandom || n<=40){
                        u=randint(0,n-1);
                        if(!curcover[u])continue;
                    }else{
                        int rand=randint(0,1);
                        if(se.empty())break;
                        u=se.begin()->second;
                        se.erase(se.begin());
                        if(!curcover[u] || rand==0)continue;
                    }
                    cc++;
                    memcpy(tempCover, curcover, sizeof(int) * n);
                    ll dif;//=optRemove(u, tempCover);
                    if(curcover[u])dif=optRemove(u, tempCover);
                    else dif=optAdd(u, tempCover);
                    curdis += dif;
                    memcpy(curcover, tempCover, sizeof(int) * n);
                    if(timecheck())break;
                }
                int rand=randint(0,2);
                if(rand==0)sort(vid,vid+n,[&](int l,int r){return w[l]>w[r];});
                else if(rand==1)sort(vid,vid+n,[&](int l,int r){return (ll)w[l]*inde[l]>(ll)w[r]*inde[r];});
                else sort(vid,vid+n,[&](int l,int r){return inde[l]<inde[r];});
            }
        }
        if(umin(mindis,curdis))memcpy(bestcover,curcover,n*sizeof(int));
        if(timecheck())break;
    }

    ll cur=0;
    FOR(n)if(bestcover[i])cur+=w[i];
    print(mindis);
    assert(cur==mindis);
#if !defined(_DEBUG)
    FOR(n)if(bestcover[i])write(i," ");
#endif
}
int main() {
#if !defined(_DEBUG)
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
#ifdef _DEBUG
    freopen("/home/csc/Online-Judge-Code/G/4000WMVC.txt", "r", stdin);
#endif
//4000: 1916229798
//4000: pertubation: 1916229798
//4000: pertubation+add or remove 5: 1914386252
//4000: pertubation 4 remove: 1910,v)<min(c.u,c.v) 1913842507
//4000: childw[u]-w[u]>childw[v]-w[v] 1916293214,1916231182
//4000: vector sort by childw[u]-w[u]<childw[v]-w[v] 1915503763
//400 192500067
//400:pertubation 192441483
//40: 17029624
//40:pertubation 17029624

    //freopen("/home/csc/Downloads/vivoparc/1.in", "r", stdin);
    //freopen("/home/csc/G/output.txt", "w", stdout);
    timebegin = clock();
    int t=1;
//    read(t);
    FOR(t) {
        //write("Case #", i+1, ": ");
        solve();
    }
    return 0;
}

/*

shuffle the number of variables follow unchange number is a bad idea, result is 33.1

local very good, //4000: sort edge by min(u,v)<min(c.u,c.v) 1913842507 , kattis just 32.997952
local very bad // if(childw[u]-w[u]>childw[v]-w[v])c=u; kattis is good 33.73205
strange! remove decrease add increase did not imporve the kattis scroe is 33.108387
 score (32.26056) for random flip
 combine best with if(childw[u]-w[u]>childw[v]-w[v])c=u;, get lower score, strange!
every time sort remove opt is very slow

 //vec and grvec is 34.20
 * */