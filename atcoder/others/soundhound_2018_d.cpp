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

typedef pair<ll, ll> LP;
struct edge {
    ll to, cost;
    edge(ll t, ll c): to(t), cost(c) {};
};
vector<edge> g_yen[100010];
vector<edge> g_snook[100010];
int n, m, s, t;
ll d_yen[100010];
ll d_snook[100010];

void dijkstra(int s, vector<edge> *g, ll *d)
{
    priority_queue<LP, vector<LP>, greater<LP> > q;
    REP(i, n) d[i] = LINF;
    d[s] = 0;
    q.push(P(0, s));
    while(!q.empty()){
      P p = q.top(); q.pop();
      ll v = p.se;
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
}

void solve()
{
    dijkstra(s, g_yen, d_yen);
    dijkstra(t, g_snook, d_snook);
    priority_queue<LP, vector<LP>, greater<LP> > q;
    REP(i, n){
        auto p = mp(d_yen[i] + d_snook[i], i+1);
        q.push(p);
    }
    REP(i, n){
        while(true){
            auto p = q.top();
            if(p.se > i){
                cout << 1000000000000000ll - p.fi << endl;
                break;
            }else{
                q.pop();
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m >> s >> t;
    s--; t--;
    REP(i, m){
        ll u, v, a, b;
        cin >> u >> v >> a >> b;
        u--; v--;
        g_yen[u].pb(edge(v, a));
        g_yen[v].pb(edge(u, a));
        g_snook[u].pb(edge(v, b));
        g_snook[v].pb(edge(u, b));
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
