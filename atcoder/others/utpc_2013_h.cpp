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
#define FOR(i, a, b) for(ll i = static_cast<ll>(a); i < static_cast<ll>(b); i++)
#define FORR(i, a, b) for(ll i = static_cast<ll>(a); i >= static_cast<ll>(b); i--)
#define REP(i, n) for(ll i = 0ll; i < static_cast<ll>(n); i++)
#define REPR(i, n) for(ll i = static_cast<ll>(n); i >= 0ll; i--)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
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
// }}}

int N, M;
int p[1000];
int q[1000];
int x[100000], y[100000];
int a[100000], b[100000];
ll d[2001];

struct edge {
    int from, to;
    ll cost;
    edge(): from(0), to(0), cost(0) {};
    edge(int f, int t, ll c): from(f), to(t), cost(c) {};
};
int V, E;
vector<edge> es;

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

void init()
{

}

void solve()
{
    V = 2*N+1; // (V-1)-th vertex is a slack variable, whose cost should be equivalent to 0
    E = 4*N + 2*M;
    REP(i, N){
        es.pb(edge(i, V-1, p[i]));
        es.pb(edge(V-1, N+i, q[i]));
        es.pb(edge(V-1, i, 0));
        es.pb(edge(N+i, V-1, 0));
    }
    REP(i, M){
        es.pb(edge(N+y[i], x[i], -a[i]));
        es.pb(edge(x[i], N+y[i], b[i]));
    }
    bool nnl = bellman_ford(V-1);
    if(!nnl || d[V-1] != 0) cout << "no" << endl;
    else cout << "yes" << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    REP(i, N) cin >> p[i];
    REP(i, N) cin >> q[i];
    REP(i, M){
        int t, u, v, w;
        cin >> x[i] >> y[i] >> a[i] >> b[i];
        x[i]--; y[i]--;
    }
    solve();

    return 0;
}

// vim:set foldmethod=marker:
