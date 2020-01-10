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
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
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

int N, T;
int a[3010], b[3010];
LP dp[3010][3010]; // dp[i][j]: i 番目までの料理でj分までに得られる最大の満足度と最後に選んだ料理

void solve()
{
    FOR (i, 1, N+1) {
        REP (j, T+1) {
            if (dp[i][j].fi < dp[i-1][j].fi)
                dp[i][j] = dp[i-1][j];
            if (j > 0 && dp[i][j].fi < dp[i][j-1].fi)
                dp[i][j] = dp[i][j-1];
            if (dp[i][j].fi < b[i])
                dp[i][j] = mp(b[i], i);
            if (j + a[dp[i-1][j].se] < T)
                dp[i][j+a[dp[i-1][j].se]] = mp(dp[i-1][j].fi + b[i], i);
        }
    }
    cout << dp[N][T].fi << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> T;
    REP (i, N) cin >> a[i+1] >> b[i+1];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
