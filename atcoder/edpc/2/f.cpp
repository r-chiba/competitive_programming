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

string s, t;
pair<int, pair<int, P> > dp[3001][3001];

void solve()
{
    int sl = s.size(), tl = t.size();
    FOR (i, 1, sl+1) {
        FOR (j, 1, tl+1) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = make_pair(dp[i-1][j-1].fi + 1, make_pair(i-1, make_pair(i-1, j-1)));
            } else {
                dp[i][j] = (dp[i-1][j].fi > dp[i][j-1].fi ? dp[i-1][j] : dp[i][j-1]);
            }
        }
    }
    string ans;
    auto p = dp[sl][tl];
    while (p.fi > 0) {
        ans += s[p.se.fi];
        p = dp[p.se.se.fi][p.se.se.se];
    }
    reverse(ALL(ans));
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> s >> t;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
