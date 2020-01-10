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

int N, M;
vector<int> neighbors[2][100001];
int dp[100001];

int rec(int v)
{
    if (dp[v] != -1) return dp[v];
    if (neighbors[0][v].size() == 0) return 0;
    int ret = 0;
    for (int i: neighbors[0][v]) {
        ret = max(ret, rec(i));
    }
    return dp[v] = ret + 1;
}

void solve()
{
    int ans = 0;
    REP (i, N) dp[i] = -1;
    REP (i, N) {
        if (neighbors[1][i].size() == 0) {
            ans = max(ans, rec(i));
        }
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    REP (i, M) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        neighbors[0][x].pb(y);
        neighbors[1][y].pb(x);
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
