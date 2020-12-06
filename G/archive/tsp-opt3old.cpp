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
//mt19937 mt_rng(0);
ll randint(ll a, ll b,int c=-1) {
    if(c>=0){
        mt_rng.seed(c);
        return uniform_int_distribution<>(a, b)(mt_rng);
    }
    return uniform_int_distribution<>(a, b)(mt_rng);
}
template<class T, class U> void vti(vt<T> &v, U x, size_t n) {v=vt<T>(n, x);}
template<class T, class U> void vti(vt<T> &v, U x, size_t n, size_t m...) {
    v=vt<T>(n);
    EACH(a, v)vti(a, x, m);
}
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
const int MAXN = 2e3+20;
const int LOGMAXN = 18;
//ll const MOD=998244353;
ll const MOD=1e9+7;
using namespace std;
clock_t timebegin;
int n;
int w[MAXN][MAXN],tour[MAXN],besttour[MAXN],vertex2idx[MAXN];
int maxneighbor,minneighbor;
int dlb2[MAXN],dlb3[MAXN];
const int DLB=0;
int tmptour[MAXN],tmpvertex2idx[MAXN];
ll mindis=0,curdis=0;
int vis[MAXN],timecnt;
double vec[MAXN][2];
int arr[MAXN][MAXN];
ll bitdp[21][220000];
int nextedge[21][220000];

inline bool timecheck(){
    clock_t timeend = clock();
    double elapsed_secs = double(timeend - timebegin) / CLOCKS_PER_SEC;
    return elapsed_secs>=1.98;
}
inline bool timecntcheck(){
    timecnt++;
    if(timecnt>=1e4){
        timecnt=0;
        return timecheck();
    }
    return false;
}


inline int dis(double a0,double a1,double b0,double b1){
    return int(sqrt((a0-a1)*(a0-a1)+(b0-b1)*(b0-b1))+0.5);
}
void dpforsmalldata(){
    memset(bitdp,0x3f,sizeof(bitdp));
    bitdp[0][(1<<n)-1]=0;
    for(int s=(1<<n)-2;s>=0;--s)
        FOR(i,n)FOR(j,n)if(!(s>>j & 1))
                    if(i!=j && ((s==0 && i==0) || (s && (s>>i & 1))) && umin(bitdp[i][s],bitdp[j][s|(1<<j)]+w[i][j])){
                        nextedge[i][s]=j;
                    }
    //print(0,bitdp[0][0]);
    print(0);
    for (int i = 0,u=0,s=0; i < n-1; ++i) {
        int v=nextedge[u][s];
        //print(v,bitdp[u][s],w[u][v]);
        print(v);
        s|=(1<<v);
        u=v;
        //if(i==n-2)print(0,bitdp[u][s],w[u][0]);
    }
}
inline void reversetour(int i,int j){
    for (int k0 = i+1,k1=j; k0<=k1; ++k0,--k1){
#ifdef _DEBUG
        assert(vertex2idx[tour[k0]]==k0);
        assert(vertex2idx[tour[k1]]==k1);
#endif
        swap(vertex2idx[tour[k0]],vertex2idx[tour[k1]]);
        swap(tour[k0],tour[k1]);
#ifdef _DEBUG
        assert(vertex2idx[tour[k0]]==k0);
        assert(vertex2idx[tour[k1]]==k1);
#endif
    }

}
inline int opt2(int i,int j){
    int x1=tour[i],x2=tour[(i+1)%n],y1=tour[j],y2=tour[(j+1)%n];
    int d0=w[x1][x2]+w[y1][y2];
    int d1=w[x1][y1]+w[x2][y2];
    if(d0>d1){
        if(DLB)dlb2[x1]=dlb2[x2]=dlb2[y1]=dlb2[y2]=1;
        umax(maxneighbor,max(w[x1][y1],w[x2][y2]));
        reversetour(i,j);
        return d0-d1;
    }
    return 0;
}
inline void opt2LocalOptimal(double localFactor=2,int maxnumberneighbor=20){
    if(timecheck())return;
    while(1){
        int change=0;
        FOR(i,n-1){
            int changei=0;
            int x1=tour[i],x2=tour[(i+1)%n];
            if(DLB && !dlb2[x1])continue;
            for(int jarr=0;jarr<min(n-1,maxnumberneighbor);jarr++){
                int y1=arr[x1][jarr];
                if(DLB && !dlb2[y1])continue;
                int j=vertex2idx[y1],y2=tour[(j+1)%n];
                if(i+1>=j || (j+1)%n==i)continue;
                if(w[x1][y1]+minneighbor>w[x1][x2]+maxneighbor)break;
                if(localFactor>0 && w[x1][y1]>w[x1][x2]*localFactor)break;
                int delta = opt2(i,j);
                change+=bool(delta);
                changei+=bool(delta);
                curdis-=delta;
                if(timecntcheck())return;
            }
            if(!changei)dlb2[x1]=0;
        }
        if(!change)break;
        if(timecntcheck())return;
    }
}
inline int opt3(int i,int j,int k){
    int x1=tour[i],x2=tour[i+1],y1=tour[j],y2=tour[j+1],z1=tour[k],z2=tour[(k+1)%n];
    int d0=w[x1][x2]+w[y1][y2]+w[z1][z2];
    int d1=w[x1][y1]+w[x2][y2]+w[z1][z2];
    int d2=w[x1][x2]+w[y1][z1]+w[y2][z2];
    int d3=w[z2][x2]+w[y1][y2]+w[z1][x1];

    int d4=w[x1][y2]+w[x2][z1]+w[y1][z2];
    int d5=w[x1][z1]+w[x2][y2]+w[y1][z2];
    int d6=w[x1][y1]+w[x2][z1]+w[y2][z2];
    int d7=w[x1][y2]+w[x2][z2]+w[y1][z1];
    //http://tsp-basics.blogspot.com/2017/03/3-opt-move.html
    //https://en.wikipedia.org/wiki/3-opt
//    if(d0>d1){
//        reversetour(i,j);
//        if(DLB)dlb3[x1]=dlb3[x2]=dlb3[y1]=dlb3[y2]=1;
//        return d0-d1;
//    }else if(d0>d2){
//        reversetour(j,k);
//        if(DLB)dlb3[y1]=dlb3[y2]=dlb3[z1]=dlb3[z2]=1;
//        return d0-d2;
//    }else if(d0>d3){
//        reversetour(i,k);
//        if(DLB)dlb3[x1]=dlb3[x2]=dlb3[z1]=dlb3[z2]=1;
//        return d0-d3;
//    }else

    if(DLB && d0>min({d4,d5,d6,d7}))dlb3[x1]=dlb3[x2]=dlb3[y1]=dlb3[y2]=dlb3[z1]=dlb3[z2]=1;
    if(d0>d4){
        //x1x2y1->x1y1x2
        //int d4=w[x1][y2]+w[x2][z1]+w[y1][z2];
        umax(maxneighbor,max({w[x1][y2],w[x2][z1],w[y1][z2]}));
        //memcpy(tmptour+i+1,tour+i+1,sizeof(int)*(j+1-(i+1)));
        memcpy(tmptour,tour,sizeof(int)*n);
        memcpy(tmpvertex2idx,vertex2idx,sizeof(int)*n);
        int m=i+1;
        for (int l = j+1; l <= k; ++l) tour[m]=tmptour[l],vertex2idx[tour[m]]=m,m++;
        for (int l = i+1; l <= j; ++l) tour[m]=tmptour[l],vertex2idx[tour[m]]=m,m++;
        return d0-d4;
    }
    else if(d0>d5){
        //x1x2y1->x1y1'x2
        //int d5=w[x1][z1]+w[x2][y2]+w[y1][z2];
        umax(maxneighbor,max({w[x1][z1],w[x2][y2],w[y1][z2]}));
        memcpy(tmptour,tour,sizeof(int)*n);
        memcpy(tmpvertex2idx,vertex2idx,sizeof(int)*n);
        int m=i+1;
        for (int l = k; l >= j+1; --l)tour[m]=tmptour[l],vertex2idx[tour[m]]=m,m++;
        for (int l = i+1; l <= j; ++l)tour[m]=tmptour[l],vertex2idx[tour[m]]=m,m++;
        return d0-d5;
    }
    else if(d0>d6){
        //int d6=w[x1][y1]+w[x2][z1]+w[y2][z2];
        umax(maxneighbor,max({w[x1][y1],w[x2][z1],w[y2][z2]}));
        memcpy(tmptour,tour,sizeof(int)*n);
        memcpy(tmpvertex2idx,vertex2idx,sizeof(int)*n);
        int m=i+1;
        for (int l = j; l >= i+1; --l) tour[m]=tmptour[l],vertex2idx[tour[m]]=m,m++;
        for (int l = k; l >= j+1; --l) tour[m]=tmptour[l],vertex2idx[tour[m]]=m,m++;
        return d0-d6;
    }else if(d0>d7){
        //int d7=w[x1][y2]+w[x2][z2]+w[y1][z1];
        umax(maxneighbor,max({w[x1][y2],w[x2][z2],w[y1][z1]}));
        memcpy(tmptour,tour,sizeof(int)*n);
        memcpy(tmpvertex2idx,vertex2idx,sizeof(int)*n);
        int m=i+1;
        for (int l = j+1; l <= k; ++l) tour[m]=tmptour[l],vertex2idx[tour[m]]=m,m++;
        for (int l = j; l >= i+1; --l) tour[m]=tmptour[l],vertex2idx[tour[m]]=m,m++;
        return d0-d7;
    }
    return 0;
}
inline void opt3LocalOptimal(int maxnumberneighbor=20){
    if(timecheck())return;
    while(1){
        int change=0;
        FOR(i,n-1){
            int x1=tour[i],x2=tour[(i+1)%n];
            for(int jarr=0;jarr<min(n-1,maxnumberneighbor);jarr++){
                int y1=arr[x1][jarr];
                int j=vertex2idx[y1];
                int y2=tour[(j+1)%n];
                if(i+1>=j || (j+1)%n==i)continue;
//                int d2 = distance(X1, Y1) + minLenInSet
//                if d2 + minLenInSet > distance(X1, X2) + 2 * maxLenInTour:break
//                d1 = distance(X1, X2) + distance(Y1, Y2) + maxLenInTour
//                if d2 + minLenInSet > d1:continue
                int d2 = w[x1][y1]+minneighbor;
                if (d2+minneighbor>w[x1][x2]+2*maxneighbor)break;
                int d1=w[x1][x2]+w[y1][y2]+maxneighbor;
                if(d2+minneighbor>d1)continue;

                for(int karr=0;karr<min(n-1,maxnumberneighbor);karr++){
                    int z1=arr[x1][karr];
                    if(timecntcheck())return;
                    int k=vertex2idx[z1];
                    int z2=tour[(k+1)%n];
                    if(j+1>=k || (k+1)%n==i)continue;
                    //if d2 + distance(Y1, Z1) > d1:break
                    if(d2+w[y1][z1]>d1)break;
                    int delta=opt3(i,j,k);
                    change+=bool(delta);
                    curdis-=delta;
                }
            }
        }
        if(!change)break;
        if(timecntcheck())return;
    }
}
ll perturbation(int seed=-1,ll perdis=-1){
    int ii=randint(1,n/4,seed);
    int jj=randint(1,n/4,seed)+ii;
    int kk=randint(1,n/4,seed)+jj;
    //print(ii,jj,kk);
    //memcpy(tmptour,tour,sizeof(int)*n);
    int m=0;
    FOR(l,0,ii)tmptour[m++]=tour[l];
//    memcpy(tmptour,tour,sizeof(int)*ii);
    FOR(l,kk,n)tmptour[m++]=tour[l];
//    memcpy(tmptour+ii,tour+kk,sizeof(int)*(n-kk));
    FOR(l,jj,kk)tmptour[m++]=tour[l];
    FOR(l,ii,jj)tmptour[m++]=tour[l];
    ll cur=0;
    FOR(n)cur+=w[tmptour[i]][tmptour[(i+1)%n]];
    if(perdis==-1 || cur<perdis){
        memcpy(tour,tmptour,sizeof(int)*n);
        FOR(n)vertex2idx[tour[i]]=i;
        perdis=curdis=cur;
    }
    return perdis;
}
void solve() {
    read(n);
    FOR(n)FOR(j,2)read(vec[i][j]);
    minneighbor=1e9;
    FOR(n){
        int k=0;
        FOR(j,n)if(i!=j){
                w[i][j]=dis(vec[i][0],vec[j][0],vec[i][1],vec[j][1]);
                umin(minneighbor,w[i][j]);
                arr[i][k]=j;
                k++;
            }
        //assert(k==n-1);
        sort(arr[i],arr[i]+n-1,[&](int l,int r){return w[i][l]<w[i][r];});
    }
    //FOR(n)FOR(j,n)assert(w[i][j]==w[j][i]);
    if(n<=16){
        dpforsmalldata();
        //print("min",bitdp[0][0]);
        debug(bitdp[0][0]);
        return;
    }
    FOR(q,1000000){
        memset(vis,0,sizeof(int)*n);
        vis[0]=1;
        curdis=0;

        for (int k = 0,u=0; k < n-1; ++k){
            int rand=randint(1,min(n-k-1,min(2,q+1)));
            //int rand=randint(1,1);
            int cnt=0;
            tour[0]=0,vertex2idx[0]=0;
            FOR(j,n-1)if(!vis[arr[u][j]]){
                    int v=arr[u][j];
                    if(++cnt>=rand){
                        curdis+=w[u][v];
                        vis[v]=1;
                        tour[k+1]=v;
                        vertex2idx[v]=k+1;
                        u=v;
                        break;
                    }
                }
            if(k==n-2)curdis+=w[u][0];
        }
        maxneighbor=0;
        FOR(n)umax(maxneighbor,w[tour[i]][tour[(i+1)%n]]);
        if(q==0){
            mindis=curdis;
            //debug(mindis);
            memcpy(besttour,tour,n*sizeof(int));
        }
//        FOR(n)write(tour[i]," ");
//        print();
        timecnt=0;
        FOR(seed,100000){
            if(timecheck())break;
            int maxnumberneighbor=30;///TODO:wrong here
            if(DLB)FOR(n)dlb3[i]=dlb2[i]=1;
            opt2LocalOptimal(1.2,maxnumberneighbor);
            opt2LocalOptimal(-1,maxnumberneighbor);
            opt3LocalOptimal(maxnumberneighbor);
            if(umin(mindis,curdis))memcpy(besttour,tour,n*sizeof(int));
            if(timecheck())break;
            //perturbation((seed+5)*2);
#ifdef _DEBUG
            ll perdis=perturbation(seed*10,-1);
            FOR(p,5)perdis=perturbation(seed*10+p+1,perdis);
            FOR(n)umax(maxneighbor,w[tour[i]][tour[(i+1)%n]]);
#else
            ll perdis=perturbation(-1,-1);
        FOR(p,5)perdis=perturbation(-1,perdis);
        FOR(n)umax(maxneighbor,w[tour[i]][tour[(i+1)%n]]);
#endif

        }

        //break;
        if(timecheck())break;
    }
    debug(mindis);
    ll finaldis=0;

    FOR(n)finaldis+=w[besttour[i]][besttour[(i+1)%n]];
    assert(mindis==finaldis);
#ifndef _DEBUG
    FOR(n)print(besttour[i]);
#endif
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef _DEBUG
    //freopen("/home/csc/Online-Judge-Code/G/10tsp.txt", "r", stdin);//276
    //freopen("/home/csc/Online-Judge-Code/G/1000tsp.txt", "r", stdin);//47296138
    //freopen("/home/csc/Online-Judge-Code/G/data2/bcl380.tsp", "r", stdin);//1653
    //freopen("/home/csc/Online-Judge-Code/G/data2/xit1083.tsp", "r", stdin);//3733
    //freopen("/home/csc/Online-Judge-Code/G/data2/dka1376.tsp", "r", stdin);//4882
    freopen("/home/csc/Online-Judge-Code/G/data2/xql662.tsp", "r", stdin);//2597
#endif
    //1000tsp 49295531
    //opt2+2*opt3 = 48689614
    //opt2+opt3 = 48796791
    //opt2 til fail, opt3 til fail = 48532928
    //opt2 til fail, complete opt3 til fail = 48492524
    //opt2 til fail, complete opt2+3 til fail maxneibor=50 = 48076767
    //opt2 til fail, complete opt3 til fail maxneibor=50 = 48039674
    //opt2 til fail, complete opt3 til fail maxneibor=100 = 47825325
    //opt2 til fail, complete opt3 til fail maxneibor=100, local factor1.2 = 47577737
    //opt2 til fail, complete opt3 til fail maxneibor=100, local factor1.2, x1->y1,x1->z1 = 47555153
    //opt2 til fail, complete opt3 til fail maxneibor=100, local factor1.2, x1->y1,x1->z1 = 47331365

    //100tsp opt3 17375806
    //opt2+2*opt3 = 17206547
    //opt2+opt3 = 17014981
    //50tsp 11514358
    //10tsp 276
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