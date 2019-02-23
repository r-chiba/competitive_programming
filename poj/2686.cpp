#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
const int INF = 1000000;
const double DINF = 1e6;
const int MAX_N = 8;
const int MAX_M = 30;
int n, m, p, a, b;
int t[MAX_M];
int cost[MAX_M][MAX_M];
double d[1<<MAX_N][MAX_M];

void init()
{
  for(int i = 0; i < MAX_M; i++){
    for(int j = 0; j < MAX_M; j++){
      cost[i][j] = i==j ? 0 : INF;
    }
  }
  for(int i = 0; i < 1<<MAX_N; i++){
    fill(d[i], d[i]+m, DINF);
  }
}

void solve()
{
  priority_queue<P> q;
  d[(1<<n)-1][a] = 0;
  double res = DINF;
  for(int s = (1<<n)-1; s >= 0; s--){
    res = min(res, d[s][b]);
    for(int v = 0; v < m; v++){
      for(int i = 0; i < n; i++){
        if((s>>i) & 1){
          for(int u = 0; u < m; u++){
            if(cost[v][u] < INF){
              d[s&~(1<<i)][u] = min(d[s&~(1<<i)][u],
                                    d[s][v] + static_cast<double>(cost[v][u])/t[i]);
            }
          }
        }
      }
    }
  }
  if(res != DINF){
    printf("%f\n", res);
  }else{
    printf("Impossible\n");
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
