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
#define FOR(i, a, b) for(size_t i = static_cast<size_t>(a); i < static_cast<size_t>(b); i++)
#define FORR(i, a, b) for(size_t i = static_cast<size_t>(a); i >= static_cast<size_t>(b); i--)
#define REP(i, n) for(size_t i = 0; i < static_cast<size_t>(n); i++)
#define REPR(i, n) for(size_t i = static_cast<size_t>(n); i >= 0; i--)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> IP;
typedef pair<ll, LP> LIP;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

constexpr int INF = 100000000;
constexpr ll LINF = 10000000000000000ll;
constexpr int MOD = static_cast<int>(1e9 + 7);
constexpr double EPS = 1e-9;
// }}}

ll N, M, T;
struct edge {
    ll to, cost;
    edge(ll t, ll c): to(t), cost(c) {};
};
vector<edge> g[100010];
vector<edge> g_rev[100010];
ll a[100010];
ll d[100010];
ll d_rev[100010];

class Compare
{
public:
    bool operator()(const LP &lhs, const LP &rhs){
        if(lhs.fi < rhs.fi)
            return true;
        return false;
    }
};

void dijkstra(ll s, vector<edge> *g, ll *d)
{
    priority_queue<LP, vector<LP>, Compare> q;
    REP(i, N) d[i] = LINF;
    d[s] = 0ll;
    q.push(LP(0ll, s));
    while(!q.empty()){
      LP p = q.top(); q.pop();
      ll v = p.se;
      if(p.first > d[v]) continue;
      size_t len = g[v].size();
      for(size_t i = 0; i < len; i++){
        edge e = g[v][i];
        if(d[e.to] > d[v] + e.cost){
          d[e.to] = d[v] + e.cost;
          q.push(LP(d[e.to], e.to));
        }
      }
    }
}

void init()
{
}

void solve()
{
    dijkstra(0ll, g, d);
    dijkstra(0ll, g_rev, d_rev);
    ll ans = 0ll;
    REP(i, N){
        ans = max(ans, a[i] * (T - d[i] - d_rev[i]));
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> T;
    REP(i, N) cin >> a[i];
    REP(i, M){
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].pb(edge(b, c));
        g_rev[b].pb(edge(a, c));
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
