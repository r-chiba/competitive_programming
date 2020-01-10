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
int a[200010];
int dp[200010];

void solve()
{
    dp[0] = 1;
    FOR (i, 1, N+1) {
        dp[i] = 1;
        auto p = lower_bound(dp, &dp[i], 1);
        int j = (int)(p - dp);
        FORR (k, i-1, j) {
            dp[k] = (dp[k] && a[i-1] == i-k ? 1 : 0);
            if (k > 0 && dp[k] == 0) {
                dp[k] = (dp[k-1] && a[i-1] != i-k ? 1 : 0);
            }
        }
    }
    auto p = lower_bound(dp, &dp[N], 1);
    int idx = (int)(p - dp);
    cout << (idx < N ? idx : -1) << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP (i, N) cin >> a[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
