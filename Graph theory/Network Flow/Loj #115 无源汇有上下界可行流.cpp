#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include <iostream>
using namespace std;

const int maxn = 200 + 10;
const int INF = 1000000000;

struct Edge {
  int from, to, cap, flow, lb;
};

bool operator < (const Edge& a, const Edge& b) {
  return a.from < b.from || (a.from == b.from && a.to < b.to);
}

struct Dinic {
  int n, m, s, t;
  vector<Edge> edges;    // 边数的两倍
  vector<int> G[maxn];   // 邻接表，G[i][j]表示结点i的第j条边在e数组中的序号
  bool vis[maxn];         // BFS使用
  int d[maxn];           // 从起点到i的距离
  int cur[maxn];        // 当前弧指针

  void ClearAll(int n) {
    for(int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void ClearFlow() {
    for(int i = 0; i < edges.size(); i++) edges[i].flow = 0;
  }

  void AddEdge(int from, int to, int cap, int lb) {
    edges.push_back((Edge){from, to, cap, 0, lb});
    edges.push_back((Edge){to, from, 0, 0, lb});
    m = edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
  }

  bool BFS() {
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(s);
    vis[s] = 1;
    d[s] = 0;
    while(!Q.empty()) {
      int x = Q.front(); Q.pop();
      for(int i = 0; i < G[x].size(); i++) {
        Edge& e = edges[G[x][i]];
        if(!vis[e.to] && e.cap > e.flow) {
          vis[e.to] = 1;
          d[e.to] = d[x] + 1;
          Q.push(e.to);
        }
      }
    }
    return vis[t];
  }

  int DFS(int x, int a) {
    if(x == t || a == 0) return a;
    int flow = 0, f;
    for(int& i = cur[x]; i < G[x].size(); i++) {
      Edge& e = edges[G[x][i]];
      if(d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap-e.flow))) > 0) {
        e.flow += f;
        edges[G[x][i]^1].flow -= f;
        flow += f;
        a -= f;
        if(a == 0) break;
      }
    }
    return flow;
  }

  int Maxflow(int s, int t) {
    this->s = s; this->t = t;
    int flow = 0;
    while(BFS()) {
      memset(cur, 0, sizeof(cur));
      flow += DFS(s, INF);
    }
    return flow;
  }
  int checkExist(){
    for (int i = 0; i < G[0].size(); ++i) {
      Edge& e = edges[G[0][i]];
      if(e.flow!=e.cap)return 0;
    }
    for (int i = 0; i < G[n+1].size(); ++i) {
      Edge& e = edges[G[0][i]];
      if(e.flow!=e.cap)return 0;
    }
    return 1;
  }
};
Dinic g;

int main(){
  int n,m,s,t;
  //cin >> n >> m >> s >>t;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u,v,a,b;
    cin >> u >> v >> a >> b;
    g.AddEdge(u, v, b-a,a);
    if(a > 0){
      g.AddEdge(u, n+1, a,0);
      g.AddEdge(0, v, a,0);
    }
  }
  g.Maxflow(0,n+1);
  if(g.checkExist()){
    puts("YES");
    for (int i = 0; i < g.edges.size(); ++i) {
      if(i % 2 || g.edges[i].from==0 || g.edges[i].to==n+1)continue;
      cout << g.edges[i].flow+g.edges[i].lb << endl;
    }
  }
  else{
    puts("NO");
//    for (int i = 0; i < g.edges.size(); ++i) {
//      if(i % 2 || g.edges[i].from==0 || g.edges[i].to==n+1)continue;
//      cout << g.edges[i].flow+g.edges[i].lb << endl;
//    }
  }
}
