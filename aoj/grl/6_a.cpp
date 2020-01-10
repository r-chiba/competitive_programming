// {{{
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
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
#define FOR(i, a, b) for(ll i = static_cast<ll>(a); i < static_cast<ll>(b); i++)
#define FORR(i, a, b) for(ll i = static_cast<ll>(a); i >= static_cast<ll>(b); i--)
#define REP(i, n) for(ll i = 0ll; i < static_cast<ll>(n); i++)
#define REPR(i, n) for(ll i = static_cast<ll>(n); i >= 0ll; i--)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> IP;
typedef pair<ll, LP> LLP;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

constexpr int INF = 100000000;
constexpr ll LINF = 10000000000000000ll;
constexpr int MOD = static_cast<int>(1e9 + 7);
constexpr double EPS = 1e-9;

static inline ll mod(ll x, ll m)
{
    ll y = x % m;
    return (y >= 0 ? y : y+m);
}

// }}}

struct Edge {
    int to_, rev_;
    ll capacity_;
    Edge(int to, int rev, ll capacity): to_(to), rev_(rev), capacity_(capacity) {}
};

int V, E;
vector<Edge> g[100];
bool visited[100];

ll dfs(int v, ll c)
{
    visited[v] = true;
    if (v == V-1) return c;
    REP (i, g[v].size()) {
        if (visited[g[v][i].to_] || g[v][i].capacity_ <= 0)
            continue;
        ll ret = dfs(g[v][i].to_, min(c, g[v][i].capacity_));
        if (ret > 0) {
            g[v][i].capacity_ -= ret;
            g[g[v][i].to_][g[v][i].rev_].capacity_ += ret;
            return ret;
        }
    }
    return 0;
}


void solve()
{
    ll ans = 0;
    while (true) {
        REP (i, V) visited[i] = false;
        ll f = dfs(0, LINF);
        if (f <= 0) break;
        ans += f;
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> V >> E;
    REP (i, E) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].pb(Edge(v, g[v].size(), c));
        g[v].pb(Edge(u, g[u].size()-1, 0));
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
