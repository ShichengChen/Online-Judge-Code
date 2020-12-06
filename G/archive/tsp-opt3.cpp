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
bool dlb2[MAXN],dlb3[MAXN];
const int DLB=1;
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
    return elapsed_secs>=1.99;
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
inline void reversetour(int a,int b,int len){
    for (int i=0; i<len; a=(a+1)%n,b=(b-1+n)%n,i++){
#ifdef _DEBUG
        assert(vertex2idx[tour[a]]==a);
        assert(vertex2idx[tour[b]]==b);
#endif
        swap(vertex2idx[tour[a]],vertex2idx[tour[b]]);
        swap(tour[a],tour[b]);
#ifdef _DEBUG
        assert(vertex2idx[tour[a]]==a);
        assert(vertex2idx[tour[b]]==b);
#endif
    }
}
inline int opt2(int i,int j,bool takebest=0){
    int x1=tour[i],x2=tour[(i+1)%n],y1=tour[j],y2=tour[(j+1)%n];
    int d0=w[x1][x2]+w[y1][y2];
    int d1=w[x1][y1]+w[x2][y2];
    if(d0>d1){
        if(takebest)return d0-d1;
        umax(maxneighbor,max(w[x1][y1],w[x2][y2]));
        int len=(j-(i+1)%n+1+n)%n;
        //reversetour((i+1)%n,j,len/2);
        if(len*2<=n)reversetour((i+1)%n,j,len/2);
        else reversetour((j+1)%n,i,(n-len)/2);
        return d0-d1;
    }
    return 0;
}
struct BestOpt3{int i,j,k;ll v;}bo3;
inline bool opt2LocalOptimal(int i,double localfactor=2,int maxnumberneighbor=20,bool useDLB=false,bool takebest=0){
//    FOR(direction,1){
//        if(direction==1)i=(i-1+n)%n;
    int x1=tour[i],x2=tour[(i+1)%n];
    for(int jarr=0;jarr<min(n-1,maxnumberneighbor);jarr++){
        int y1=arr[x1][jarr];
        int j=vertex2idx[y1],y2=tour[(j+1)%n];
        //if(direction==1)swap(y1,y2);
        if((x1 == y1) || (x2 == y1) || (y2 == x1))continue;
        if(w[x1][y1]+minneighbor>w[x1][x2]+maxneighbor)break;
        if(localfactor>0 && w[x1][y1]>w[x1][x2]*localfactor)continue;
        int delta = opt2(i,j,takebest);
        if(takebest){
            if(delta>bo3.v)bo3={i,j,-1,delta};
        }else{
            if(useDLB && delta)dlb2[x1]=dlb2[x2]=dlb2[y1]=dlb2[y2]=false;
            curdis-=delta;
            if(delta)return true;
        }
        if(timecntcheck())return false;
    }
//    }

    return false;
}
inline void opt2Base(double localfactor=2,int maxnumberneighbor=20,bool useDLB=false,bool takebest=0){
    if(timecheck())return;
    if(useDLB)memset(dlb2,0,sizeof(bool)*n);
    while(1){
        int change=0;
        bo3={0,0,0,-1};
        FOR(i,n){
            if(useDLB && dlb2[tour[i]])continue;
            bool improve=opt2LocalOptimal(i,localfactor,maxnumberneighbor,useDLB);
            if(improve)change=1;
            else dlb2[tour[i]]=true;
            if(timecntcheck())return;
        }
        if(takebest && bo3.v>0){
            change=1;
            int delta=opt2(bo3.i,bo3.j,false);
            assert(delta>0);
            curdis-=delta;
        }
        if(!change)break;
        if(timecntcheck())return;
    }
}

inline int opt3(int i,int j,int k,bool takebest=0){
    if(k==-1)return opt2(i,j,takebest);
    int x1=tour[i],x2=tour[(i+1)%n],y1=tour[j],y2=tour[(j+1)%n],z1=tour[k],z2=tour[(k+1)%n];
    int d0=w[x1][x2]+w[y1][y2]+w[z1][z2];
    int d4=w[x1][y1]+w[x2][z1]+w[y2][z2];
    int d7=w[x1][y2]+w[x2][z1]+w[y1][z2];
    if((d0>d4 && d4<=d7)){
        if(takebest)return d0-d4;
        //int d7=w[x1][y2]+w[x2][z2]+w[y1][z1];
        umax(maxneighbor,max({w[x1][y1],w[x2][z1],w[y2][z2]}));
        reversetour((j+1)%n,k,((k-j+n)%n)/2);
        reversetour((i+1)%n,j,((j-i+n)%n)/2);
        return d0-d4;
    }
    if(d0>d7){
        if(takebest)return d0-d7;
        //x1x2y1->x1y1x2
        //int d4=w[x1][y2]+w[x2][z1]+w[y1][z2];
        umax(maxneighbor,max({w[x1][y2],w[x2][z1],w[y1][z2]}));
        reversetour((k+1)%n,i,((i-k+n)%n)/2);
        reversetour((i+1)%n,j,((j-i+n)%n)/2);
        reversetour((j+1)%n,k,((k-j+n)%n)/2);
        return d0-d7;
    }
    return 0;
}
inline bool between(int i,int j,int k){
    if(i<k)
        return j>i && j<k;
    if(i>k)
        return j>i || j<k;
    return false;
}

inline bool opt3LocalOptimal(int i,double localfactor,int maxnumberneighbor=20,bool takebest=0){
    if(timecheck())return false;
    int x1=tour[i],x2=tour[(i+1)%n];
    for(int jarr=0;jarr<min(n-1,maxnumberneighbor);jarr++){
        int y1=arr[x1][jarr];
        int j=vertex2idx[y1];
        int y2=tour[(j+1)%n];

        if((x1 == y1) || (x2 == y1) || (y2 == x1))continue;
        if(localfactor>0 && w[x1][y1]>w[x1][x2]*localfactor)continue;
        //if(w[x1][y1]+minneighbor>w[x1][x2]+maxneighbor)break;
        int delta = opt3(i,j,-1,takebest);
        if(takebest){
            if(delta>bo3.v)bo3={i,j,-1,delta};
        }else{
            curdis-=delta;
            if(delta)return true;
        }
        if(timecntcheck())return false;


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
            if(timecntcheck())return false;
            int k=vertex2idx[z1];
            int z2=tour[(k+1)%n];

            if(x2==z1 || x1==z1|| x1==z2 ||y1==z1 || y2==z1 || y1==z2)continue;
            //if d2 + distance(Y1, Z1) > d1:break
            if(d2+w[y1][z1]>d1)break;
            int jj=j,kk=k;
            //if(!between(i,j,k))jj = k,kk = j;
            if(!between(i,j,k))continue;

            int delta=opt3(i,jj,kk,takebest);
            if(takebest){
                if(delta>bo3.v)bo3={i,j,k,delta};
            }else{
                curdis-=delta;
                if(delta)return true;
            }


//            curdis-=delta;
//            if(delta)return true;
//            print(i,j,k);
//            ll cc=0;
//            FOR(p,n)cc+=w[tour[p]][tour[(p+1)%n]];
//            print(curdis,cc);
//            assert(curdis==cc);


        }
    }
    return false;
}
inline void opt3Base(double localfactor,int maxnumberneighbor=20,bool takebest=0){
    while(1){
        int change=0;
        bo3={0,0,0,-1};
        FOR(i,n-1){
            bool improve=opt3LocalOptimal(i,localfactor,maxnumberneighbor,takebest);
            if(improve)change=1;
        }
        if(takebest && bo3.v>0){
            change=1;
            int delta=opt3(bo3.i,bo3.j,bo3.k,0);
            assert(delta>0);
            curdis-=delta;
        }
        if(!change)break;
        if(timecntcheck())return;
    }
}
void perturbation(int seed=-1){
    vector<int>ivec(4);
    FOR(4)ivec[i]=randint(0,n-2);
    sort(all(ivec));
    if(abs(ivec[1]-ivec[0])<=1 ||
            abs(ivec[2]-ivec[1])<=1||
            abs(ivec[3]-ivec[2])<=1)return;
    //print(ii,jj,kk);
    int m=0;
    FOR(l,(ivec[0]-ivec[3]+n)%n)tmptour[m++]=tour[(ivec[3]+1+l)%n];
    FOR(l,(ivec[3]-ivec[2]+n)%n)tmptour[m++]=tour[(ivec[2]+1+l)%n];
    FOR(l,(ivec[2]-ivec[1]+n)%n)tmptour[m++]=tour[(ivec[1]+1+l)%n];
    FOR(l,(ivec[1]-ivec[0]+n)%n)tmptour[m++]=tour[(ivec[0]+1+l)%n];

    ll cur=0;
    FOR(n)cur+=w[tmptour[i]][tmptour[(i+1)%n]];
    memcpy(tour,tmptour,sizeof(int)*n);
    FOR(n)vertex2idx[tour[i]]=i;
}
void solve() {
    timebegin = clock();
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
        sort(arr[i],arr[i]+n-1,[&](int l,int r){return w[i][l]<w[i][r];});
    }
    if(n<=16){
        dpforsmalldata();
        //print("min",bitdp[0][0]);
        debug(bitdp[0][0]);
        return;
    }
    memset(vis,0,sizeof(int)*n);
    vis[0]=1;
    curdis=0;
    for (int k = 0,u=0; k < n-1; ++k){
        tour[0]=0,vertex2idx[0]=0;
        FOR(j,n-1)if(!vis[arr[u][j]]){
                int v=arr[u][j];
                curdis+=w[u][v];
                vis[v]=1;
                tour[k+1]=v;
                vertex2idx[v]=k+1;
                u=v;
                break;
            }
        if(k==n-2)curdis+=w[u][0];
    }
    maxneighbor=0;
    FOR(n)umax(maxneighbor,w[tour[i]][tour[(i+1)%n]]);
    mindis=curdis;
    memcpy(besttour,tour,n*sizeof(int));
    timecnt=0;
    FOR(seed,100000){
        if(timecheck())break;
        int maxnumberneighbor=20;
        opt2Base(1.2,maxnumberneighbor,false,0);
//        opt2Base(-1,maxnumberneighbor,false,0);
        opt3Base(-1,maxnumberneighbor,0);
        if(mindis>curdis){
            mindis=curdis;//new best
            memcpy(besttour,tour,n*sizeof(int));
        }
        else if(curdis>mindis*1.5){
            //new bad local optimal, change back to old good local optimal
            curdis=mindis;
            memcpy(tour,besttour,n*sizeof(int));
        }
        if(timecheck())break;
        //perturbation((seed+5)*2);
#ifdef _DEBUG
        FOR(p,5)perturbation(seed*10+p+1);
        FOR(n)umax(maxneighbor,w[tour[i]][tour[(i+1)%n]]);
#else
        FOR(p,5)perturbation(-1);
        FOR(n)umax(maxneighbor,w[tour[i]][tour[(i+1)%n]]);
#endif
    }
    debug(mindis);
    ll finaldis=0;
    FOR(n)finaldis+=w[besttour[i]][besttour[(i+1)%n]];
    assert(mindis==finaldis);
#ifndef _DEBUG
    int start=0;for(;besttour[start];start++){}
    assert(start<n);
    FOR(n)print(besttour[(i+start)%n]);
#endif
}
int main() {

#ifdef _DEBUG
    //freopen("/home/csc/Online-Judge-Code/G/10tsp.txt", "r", stdin);//276
    //freopen("/home/csc/Online-Judge-Code/G/1000tsp.txt", "r", stdin);
    //47254603,47297589
    //take best 47484509
    //freopen("/home/csc/Online-Judge-Code/G/data2/bcl380.tsp", "r", stdin);
    //1640
    //take best 1644
    //freopen("/home/csc/Online-Judge-Code/G/data2/xit1083.tsp", "r", stdin);
    //3723
    //take best 3739
    //freopen("/home/csc/Online-Judge-Code/G/data2/dka1376.tsp", "r", stdin);
    // 4853
    //take best 4865
    freopen("/home/csc/Online-Judge-Code/G/data2/xql662.tsp", "r", stdin);
    //2583
    //take best 2596
#else
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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
    //opt2 til fail, complete opt3 til fail maxneibor=100, local factor1.2, x1->y1,x1->z1 = 47594790
    //opt2 til fail, complete opt3 til fail maxneibor=100, local factor1.2, x1->y1,x1->z1 = 47563225
    //opt2 til fail, complete opt3 til fail maxneibor=100, local factor1.2, opt3 combine opt2 = 47458373

    //100tsp opt3 17375806
    //opt2+2*opt3 = 17206547
    //opt2+opt3 = 17014981
    //2*opt2+opt3with2 = 16744227
    //with accept ratio 16598027
    //50tsp 11235912
    //10tsp 276
    //freopen("/home/csc/G/output.txt", "w", stdout);

    int t=1;
//    read(t);
    FOR(t) {
        solve();
    }
    return 0;
}

/*





 * */