// {{{
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <complex>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#if __cplusplus >= 201103
#include <numeric>
#endif
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REPR(i, n) for(int i = (n); i >= 0; i--)
#define ALL(x) (x).begin(), (x).end()

#if __cplusplus >= 201103
typedef long long ll;
#endif
typedef pair<int, int> P;
typedef pair<int, P> IP;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int INF = 100000000;
#if __cplusplus >= 201103
const ll LINF = 10000000000000000ll;
#endif
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
// }}}

//vector<int> g[100010];
bool bipartite_coloring(int v, int c)
{
    color[v] = c;
    for(auto next: g[v]){
        if(color[next] == c) return false;
        if(color[next] == 0 && !dfs(next, -c)) return false;
    }
    return true;
}

//struct edge {
//    int from, to;
//    ll cost;
//    edge(): from(0), to(0), cost(0) {};
//    edge(int f, int t, ll c): from(f), to(t), cost(c) {};
//};
//int V, E;
//ll d[1000];
//bool neg[1000];
//edge es[2000];
bool bellman_ford(int s)
{
    bool ret = true; // doesn't there exist negative loops?
    REP(i, V) d[i] = LINF;
    d[s] = 0;
    int loop = 0;
    REP(l, V){
        bool update = false;
        REP(i, E){
            edge e = es[i];
            if(d[e.from] != LINF && d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if(!update) break;
        if(update && l == V-1) ret = false;
    }
    return ret;
}
bool bellman_ford_find_negative(int s)
{
    bool ret = true; // doesn't there exist negative loops?
    REP(i, V) d[i] = LINF;
    d[s] = 0;
    int loop = 0;
    REP(l, 2*V){
        bool update = false;
        REP(i, E){
            edge e = es[i];
            if(d[e.from] != LINF && d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                update = true;
                if(l >= V) neg[e.to] = true;
            }
        }
        if(!update) break;
        if(update && l == V-1) ret = false;
    }
    return ret;
}

//struct edge {
//    int to, cost;
//    edge(int t, int c): to(t), cost(c) {};
//};
//vector<edge> g[100010];
void dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P> > q;
    REP(i, n) d[i] = INF;
    d[s] = 0;
    q.push(P(0, s));
    while(!q.empty()){
      P p = q.top(); q.pop();
      int v = p.se;
      if(p.first > d[v]) continue;
      size_t len = g[v].size();
      for(size_t i = 0; i < len; i++){
        edge e = g[v][i];
        if(d[e.to] > d[v] + e.cost){
          d[e.to] = d[v] + e.cost;
          q.push(mp(d[e.to], e.to));
        }
      }
    }
}

//struct edge {
//    int u, v, cost;
//    edge(): u(0), v(0), cost(0) {};
//    edge(int u_, int v_, int c): u(u_), v(v_), cost(c) {};
//};
//edge es[100010];
//bool comp(const edge &lhs, const edge &rhs)
//{
//    return lhs.cost < rhs.cost;
//}
int kruskal()
{
    sort(es, es+E, comp);
    UnionFind uf(V);
    int ret = 0;
    REP(i, E){
        edge e = es[i];
        if(!uf.isSame(e.u, e.v)){
            uf.unite(e.u, e.v);
            ret += e.cost;
        }
    }
    return ret;
}

void warshall_floyd()
{
    REP(k, V){
        REP(i, V){
            REP(j, V){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    return 0;
}

// vim:set foldmethod=marker:
