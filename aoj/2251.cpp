#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

struct edge{
  int to, weight, rev;
  edge(int t, int w, int r): to(t), weight(w), rev(r) {};
};

const int MAX_N = 100;
const int MAX_L = 1000;
const int INF = 1<<20;
int n, m, l;
vector<edge> g[MAX_N];
int d[MAX_N][MAX_N];
int used[MAX_N];
int reqs[MAX_L];

void init(){
  for(int i = 0; i < MAX_N; i++){
    g[i].clear();
  }
}

void add_edge(int f, int t, int w)
{
  g[f].push_back(edge(t, w, g[t].size()));
  g[t].push_back(edge(f, 0, g[f].size()-1));
}

int dfs(int v, int t, int f)
{
  if(v == t) return f;
  used[v] = true;
  for(int i = 0; i < g[v].size(); i++){
    edge &e = g[v][i];
    if(!used[e.to] && e.weight > 0){
      int d = dfs(e.to, t, min(f, e.weight));
      if(d > 0){
        e.weight -= d;
        g[e.to][e.rev].weight += d;
        return d;
      }
    }
  }
  return 0;
}

int max_flow(int s, int t)
{
  int flow = 0;
  while(true){
    memset(used, 0, sizeof(used));
    int f = dfs(s, t, INF);
    if(f == 0) return flow;
    flow += f;
  }
}

void min_distance()
{
  for(int k = 0; k < n; k++){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

void solve()
{
  init();
  min_distance();
}

int main()
{
  while(true){
    scanf("%d %d %d", &n, &m, &l);
    if(n == 0) break;
    for(int i = 0; i < MAX_N; i++){
      for(int j = 0; j < MAX_N; j++){
        d[i][j] = i==j ? 0 : INF;
      }
    }
    for(int i = 0; i < m; i++){
      int u, v, dis;
      scanf("%d %d %d", &u, &v, &dis);
      d[u][v] = d[v][u] = dis;
    }
    for(int i = 0; i < l; i++){
      int to, ti;
      scanf("%d %d", &to, &ti);
    }
  }
  return 0;
}
