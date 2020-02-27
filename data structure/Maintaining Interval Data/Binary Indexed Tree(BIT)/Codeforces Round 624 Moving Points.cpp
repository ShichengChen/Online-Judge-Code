#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN =2e5+20;
map<int,int>ma;
int n;
long long query(vector<long long> &f, int pos) {
    long long res = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
        res += f[pos];
    return res;
}

void modify(vector<long long> &f, int pos, int val) {
    for (; pos < int(f.size()); pos |= pos + 1) {
        f[pos] += val;
    }
}
bool sortbyspeed(const pair<int,int> &a,const pair<int,int> &b){
    if (a.first==b.first)
        return a.second > b.second;
    else
        return (a.first > b.first);
}
int main()
{
    cin>>n;
    vector<pair<int,int>>arr(n);
    for (auto &u:arr) {
        cin>>u.second;
    }
    for(auto &u:arr){
        cin>>u.first;
    }
    vector<int> pos;
    for (auto &pnt : arr) pos.push_back(pnt.second);
    sort(pos.begin(), pos.end());
    for (int i = 0; i < n; ++i) {
        ma[pos[i]]=i+1;
    }
    sort(arr.begin(),arr.end(),sortbyspeed);
    vector<ll>num(2*n),spos(2*n);
    for (int i = 1; i <= n; ++i) {
        modify(num,i,1);
        modify(spos,i,pos[i-1]);
    }
    ll ans=0;
    for (int i = 0; i < n; ++i) {
        int qr=ma[arr[i].second];
        ll cnum=query(num,qr);
        ll dis=query(spos,qr);
        ans+=(cnum*arr[i].second)-dis;
        modify(num,qr,-1);
        modify(spos,qr,-arr[i].second);
    }
    cout << ans << endl;
}
