#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> P;
const int INF = 1000000;
int n, m, x;
int d[2][1000];
vector<P> g[1000], r[1000];

void dijkstra(int s, vector<P> *graph, int *dist)
{
  priority_queue<P, vector<P>, greater<P> > q;
  dist[s] = 0;
  q.push(P(0, s));
  while(!q.empty()){
    P p = q.top(); q.pop();
    if(p.first > dist[p.second]) continue;
    for(int i = 0; i < graph[p.second].size(); i++){
      P e = graph[p.second][i];
      if(dist[e.first] > dist[p.second] + e.second){
        dist[e.first] = dist[p.second] + e.second;
        q.push(P(dist[e.first], e.first));
      }
    }
  }
}

int main()
{
  scanf("%d %d %d", &n, &m, &x);
  x--;
  for(int i = 0; i < n; i++){
    d[0][i] = d[1][i] = INF;
  }
  for(int i = 0; i < m; i++){
    int s, e, t;
    scanf("%d %d %d", &s, &e, &t);
    s--; e--;
    g[s].push_back(P(e, t));
    r[e].push_back(P(s, t));
  }
  dijkstra(x, g, d[0]);
  dijkstra(x, r, d[1]);
  int ans = -1;
  for(int i = 0; i < n; i++){
    int tmp = d[0][i] + d[1][i];
    if(ans == -1 || ans < tmp) ans = tmp;
  }
  printf("%d\n", ans);
}
