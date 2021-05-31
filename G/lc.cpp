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
const int MAXN = 2e5+20;
const int LOGMAXN = 18;
//ll const MOD=998244353;
ll const MOD=1e9+7;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//class Node {
//public:
//    int val;
//    Node* prev;
//    Node* next;
//    Node* child;
//};
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class NestedInteger {
public:
// Return true if this NestedInteger holds a single integer, rather than a nested list.
bool isInteger() const;
// Return the single integer that this NestedInteger holds, if it holds a single integer
// The result is undefined if this NestedInteger holds a nested list
int getInteger() const;
// Return the nested list that this NestedInteger holds, if it holds a nested list
// The result is undefined if this NestedInteger holds a single integer
const vector<NestedInteger> &getList() const;
};
class Solution {
//class LRUCache {
    typedef long long ll;
#define vt vector
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
    string to_string(int v){std::ostringstream ss;ss << v;return ss.str();}
    string to_string(ll v){std::ostringstream ss;ss << v;return ss.str();}
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
    template<class T,class U> string to_string(pair<T,U> a){return to_string(a.first)+":"+to_string(a.second);}
    template <class T> string to_string(T v) {
        char c=' ';
        if constexpr (std::is_same_v<T, vector<vector<ll>>>) c='\n';
        if constexpr (std::is_same_v<T, vector<vector<int>>>) c='\n';
        if constexpr (std::is_same_v<T, vector<vector<pair<int,int>>>>) c='\n';
        bool f=1;
        string res;
        for (auto& x: v) {
            if(!f)res+=c;
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
    const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
    const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
    inline bool inboard(int y,int x,int n,int m){
        return y>=0 && x >=0 && y<n && x<m;
    }
public:
    int minMoves2(vector<int>& nums) {
        sort(all(nums));
        int len= sz(nums);
        int ans=0;
        for (int i:nums) {
            ans+= abs(i-nums[len/2]);
        }
        return ans;
    }
};
int main() {
    Solution s;
    s.numSubmatrixSumTarget({1,2,3},4);
//    vector<int>arr={1,1,2,2,2,3};
//    int idx=max_element(arr.begin(),arr.end())-arr.begin();
//    int maxn=arr[idx?0:1];
//    for (int i = 0; i < arr.size(); ++i) {
//        if(i==idx)continue;
//        if(arr[i]>maxn)maxn=arr[i];
//    }
//    print(maxn);
//    int idx=max_element(arr.begin(),arr.end())-arr.begin();
    //int ans=max()

}
