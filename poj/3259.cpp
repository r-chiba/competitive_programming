#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct edge{
  int from, to, weight;
  edge(int f, int t, int w): from(f), to(t), weight(w) {}
};
int n, m, w;
vector<edge> v;
int d[500];

bool negative_loop()
{
  int i = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < v.size(); j++){
      edge e = v[j];
      if(d[e.to] > d[e.from] + e.weight){
        d[e.to] = d[e.from] + e.weight;
        if(i == n-1) return true;
      }
    }
  }
  return false;
}

int main()
{
  int f;
  scanf("%d", &f);
  while(f--){
    scanf("%d %d %d", &n, &m, &w);
    v.clear();
    for(int i = 0; i < n; i++){
      d[i] = 0;
    }
    for(int i = 0; i < m; i++){
      int s, e, t;
      scanf("%d %d %d", &s, &e, &t);
      s--; e--;
      v.push_back(edge(s, e, t));
      v.push_back(edge(e, s, t));
    }
    for(int i = 0; i < w; i++){
      int s, e, t;
      scanf("%d %d %d", &s, &e, &t);
      s--; e--;
      v.push_back(edge(s, e, -t));
    }
    if(negative_loop()) printf("YES\n");
    else printf("NO\n");
  }
}
