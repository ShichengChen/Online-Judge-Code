#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cstring>
#include <queue>
#include <bits/stdc++.h>
#include <cstdio>
#include <stdio.h>
using namespace std;
const int N = (int)4e5+10;
char strc[N];
int fail[N],val[N],num[N],ans[N],qtot[N],last[N],tot, tr[N][26],n,m;;
struct Node{
  Node(int v,int w): v(v) , w(w) {};
  int v,w;
};
vector<Node>vec[N];
vector<int>que[N];

int cinsert(const char *s) {
  int charu = 0;
  for (int i = 0; s[i]; i++) {
    if (!tr[charu][s[i] - 'a']) tr[charu][s[i] - 'a'] = ++tot;
    charu = tr[charu][s[i] - 'a'];
  }
  num[charu]=1;
  return charu;
}
void cbuild() {
  queue<int> q;
  for (int i = 0; i < 26; i++)
    if (tr[0][i]) q.push(tr[0][i]);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < 26; i++) {
      if (tr[u][i]){
        fail[tr[u][i]] = tr[fail[u]][i];
        q.push(tr[u][i]);
        int c = tr[u][i];
        last[c]=num[fail[c]]?fail[c]:last[fail[c]];
      }
      else
        tr[u][i] = tr[fail[u]][i];
    }
  }
}
void dfs(int u,int charu){
  for(auto const& cur: vec[u]){
    int v=cur.v,c=cur.w;
    int charv = tr[charu][c];
    for (int j = charv; j; j = last[j])val[j]+=num[j];
    for(auto const& quei: que[v]) {
      int cnt = qtot[quei];
      ans[quei]+=val[cnt];
    }
    dfs(v,charv);
    for (int j = charv; j; j = last[j])val[j]-=num[j];
  }
}
int main(){
  cin>>n;
  for(int i=1;i<=n;++i){
    int op,j;
    char ch;
    scanf("%d",&op);
    if(op==1)scanf(" %c",&ch),vec[0].emplace_back(i,ch-'a');
    else scanf("%d %c",&j,&ch),vec[j].emplace_back(i,ch-'a');
  }
  cin>>m;
  for(int quei=1;quei <= m;quei++){
    int u;
    scanf("%d%s",&u,strc);
    int cnt = cinsert(strc);
    qtot[quei]=cnt;
    que[u].push_back(quei);
  }
  cbuild();
  dfs(0,0);
  for(int i =0;i < m;i++)cout << ans[i+1] << endl;
  return 0;
}