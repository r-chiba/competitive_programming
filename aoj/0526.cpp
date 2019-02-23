// {{{
#include <iostream>
#include <cmath>
#include <cstdio>
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
#include <numeric>
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

//#if __cplusplus >= 201103
typedef long long ll;
//#endif
typedef pair<int, int> P;
typedef pair<int, P> IP;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int INF = 100000000;
//#if __cplusplus >= 201103
const ll LINF = 10000000000000000ll;
//#endif
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
// }}}

int n, k;
struct edge {
    int to, cost;
    edge(int t, int c): to(t), cost(c) {};
};
vector<edge> g[100010];
int d[100010];

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

void init()
{
    REP(i, n) g[i].clear();
}

void solve()
{
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(true){
        cin >> n >> k;
        init();
        if(n == 0 && k == 0) break;
        REP(i, k){
            int s, a, b, c;
            cin >> s;
            if(s == 0){
                cin >> a >> b;
                a--; b--;
                dijkstra(a);
                cout << (d[b] == INF ? -1 : d[b]) << endl;
            }else{
                cin >> a >> b >> c;
                a--; b--;
                g[a].pb(edge(b, c));
                g[b].pb(edge(a, c));
            }
        }
    }
    return 0;
}

// vim:set foldmethod=marker:
