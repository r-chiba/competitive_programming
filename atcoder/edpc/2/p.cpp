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

int N;
vector<int> neighbors[100000];
bool visited[100001][2];
ll dp[100001][2];

ll rec(int v, int pv, int c)
{
    if (visited[v][c]) return dp[v][c];
    visited[v][c] = true;

    ll ret = 1;
    if (c == 0) {
        for (int nv: neighbors[v]) {
            ll x = 0;
            if (nv == pv) continue;
            REP (i, 2) {
                x += rec(nv, v, i);
                x %= MOD;
            }
            ret *= x;
            ret %= MOD;
        }
    } else {
        for (int nv: neighbors[v]) {
            if (nv == pv) continue;
            ret *= rec(nv, v, 0);
            ret %= MOD;
        }
    }
    return dp[v][c] = ret;
}

void solve()
{
    ll ans = 0;
    ans += rec(0, -1, 0);
    ans %= MOD;
    ans += rec(0, -1, 1);
    ans %= MOD;
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP (i, N-1) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        neighbors[x].pb(y);
        neighbors[y].pb(x);
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
