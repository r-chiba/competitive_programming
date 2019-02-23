#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
const int INF = 1000000;
const int MAX_N = 8;
const int MAX_M = 30;
int n, m, p, a, b;
int t[MAX_M];
int cost[MAX_M][MAX_M];
int d[MAX_M], prev_[MAX_M];

void init()
{
  for(int i = 0; i < MAX_M; i++){
    d[i] = INF;
    prev_[i] = -1;
    for(int j = 0; j < MAX_M; j++){
      cost[i][j] = i==j ? 0 : INF;
    }
  }
}

void solve()
{
  priority_queue<P> q;
  d[a] = 0;
  q.push(P(0, a));
  while(!q.empty()){
    P e = q.top(); q.pop();
    if(d[e.second] < e.first) continue;
    for(int i = 0; i < m; i++){
      if(d[i] > d[e.second] + cost[e.second][i]){
        d[i] = d[e.second] + cost[e.second][i];
        prev_[i] = e.second;
        q.push(P(d[i], i));
      }
    }
  }
  int step = 0, v = b;
  int dist[MAX_N];
  while(v != a){
    if(step == n+1) break;
    dist[step] = cost[prev_[v]][v];
    v = prev_[v];
    step++;
  }
  if(step != n+1 && d[b] != INF){
    sort(dist, dist+step, greater<int>());
    sort(t, t+n, greater<int>());
    double ans = 0;
    for(int i = 0; i < step; i++){
      ans += static_cast<double>(dist[i])/t[i];
    }
    printf("%f [%d:%d]\n", ans, d[b], step);
  }else{
    printf("Impossible [%d:%d]\n", d[b], step);
  }
}

int main()
{
  while(true){
    scanf("%d %d %d %d %d", &n, &m, &p, &a, &b);
    //printf("%d %d %d %d %d\n", n, m, p, a, b);
    if(n == 0) break;
    a--; b--;
    init();
    for(int i = 0; i < n; i++){
      scanf("%d", &t[i]);
    }
    for(int i = 0; i < p; i++){
      int f, t, c;
      scanf("%d %d %d", &f, &t, &c);
      f--; t--;
      cost[f][t] = cost[t][f] = c;
      //v.push_back(edge(f, t, c));

    }
    solve();
  }
  return 0;
}
