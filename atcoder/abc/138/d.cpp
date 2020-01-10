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

int N, Q;
vector<int> es[200005];
P is[200005];
int cs[200005];
int p[200005];

#if 0
void rec(int v, int prev)
{
    for(int next: es[v]){
        if(next == prev) continue;
        sts[v].pb(next);
    }
    if(prev == -1) return;
    for(int nv: sts[v]){
        sts[prev].pb(nv);
    }
    sts[prev].pb(v);
}
#else
void find_parent(int v, int par)
{
    //cout << v << "$" << par << endl;
    p[v] = par;
    for(int next: es[v]){
        if(next == par) continue;
        find_parent(next, v);
    }
}
void count_all(int v, int par)
{
    //cout << v << "#" << par << endl;
    if(par != -1) cs[v] += cs[par];
    for(int next: es[v]){
        if(next == par) continue;
        count_all(next, v);
    }
}
#endif

void solve()
{
    find_parent(0, -1);
    REP(i, Q) cs[is[i].fi] += is[i].se;
    count_all(0, -1);
    REP(i, N-1){
        cout << cs[i] << " ";
    }
    cout << cs[N-1] << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> Q;
    REP(i, N-1){
        int v, w;
        cin >> v >> w;
        v--; w--;
        es[v].pb(w);
        es[w].pb(v);
    }
    REP(i, Q){
        cin >> is[i].fi >> is[i].se;
        is[i].fi--;
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
