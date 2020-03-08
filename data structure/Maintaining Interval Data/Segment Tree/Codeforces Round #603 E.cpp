#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
typedef long long ll;
const int MAXN = 1e6+20;
//const int MAXM = 20;
int n;
char s[MAXN],s1[MAXN];
int maxn[MAXN*2],minn[MAXN*2],lazy[MAXN*2];
struct STNode{
  int l,r,c;
  STNode(int ll,int rr,int cc){
    l=ll,r=rr,c=cc;
    lazy_update();
  }
  STNode left(){
    return STNode(l, (r+l)/2, c*2);
  }
  STNode right(){
    return STNode((l+r)/2+1,r,c*2+1);
  }
  void lazy_update(){
    if(lazy[c]){
      maxn[c]+=lazy[c],minn[c]+=lazy[c];
      if(l!=r){
        lazy[c*2]+=lazy[c];
        lazy[c*2+1]+=lazy[c];
//        maxn[c*2]+=lazy[c],minn[c*2]+=lazy[c];
//        maxn[c*2+1]+=lazy[c],minn[c*2+1]+=lazy[c];
      }
      lazy[c]=0;
    }
  }
  void update(int ql,int qr,int val){
    if(l>qr||r<ql)return;
    if(ql<=l&&r<=qr){
      lazy[c]+=val;
      lazy_update();
      return;
    }
    left().update(ql,qr,val);
    right().update(ql,qr,val);
    maxn[c]=max(maxn[c*2],maxn[c*2+1]);
    minn[c]=min(minn[c*2],minn[c*2+1]);
  }
  int query(int ql){
    lazy_update();
    if(l==ql&&r==ql)return maxn[c];
    if(l>ql||r<ql)return 0;
    int ans = left().query(ql)+right().query(ql);
    maxn[c]=max(maxn[c*2],maxn[c*2+1]);
    minn[c]=min(minn[c*2],minn[c*2+1]);
    return ans;
  }
};
 
int main()
{
  cin>>n;
  scanf("%s",s);
  int idx=1;
  STNode root(1, n, 1);
  for (int i = 0; i <= n; ++i) {s1[i]=' ';}
  for (int i = 0;i<n; ++i) {
    if(s[i]=='L'){idx--;idx=max(idx,1);}
    else if(s[i]=='R')idx++;
    else{
      if(s1[idx]=='(')root.update(idx,n,-1);
      else if(s1[idx]==')')root.update(idx,n,1);
 
      if(s[i]=='('){
        s1[idx]='(';
        root.update(idx,n,1);
      }
      else if(s[i]==')'){
        s1[idx]=')';
        root.update(idx,n,-1);
      }
      else{
        s1[idx]=s[i];
 
      }
    }
 
    //cout << "\n"<< s[i] <<" "  <<  maxn[1] << " " << minn[1]<< endl;
//    puts("");
//    for (int i = 1; i <= n; ++i) {
//      cout << root.query(i) << " ";
//    }
//    puts("");
    //int q=root.query(n);
//    cout << "\n"<< s[i] <<" "  << q << " " << maxn[1] << " " << minn[1]<< endl;
    if(minn[1]<0 || root.query(n)!=0)printf("-1 ");
    else printf("%d ",maxn[1]);
  }
  puts("");
}
/*
 11
(RaRbR)L)L(
 
 11
(R)R(R)Ra)c
 
 
 * */
