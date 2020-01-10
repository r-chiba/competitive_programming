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

int H, W;
int tiles[1500][1500];
int dp[1500][1500];

void solve()
{
    int x = 0;
    REP(i, H) {
        REP(j, W) {
            if (tiles[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                int m = INF;
                m = min(m, (i > 0 ? dp[i-1][j] : 0));
                m = min(m, (j > 0 ? dp[i][j-1] : 0));
                m = min(m, (i > 0 && j > 0 ? dp[i-1][j-1] : 0));
                dp[i][j]  = m + 1;
            }
            //cout << dp[i][j] << " ";
            x = max(x, dp[i][j]);
        }
        //cout << endl;
    }
    cout << x * x << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    REP(i, H) {
        REP(j, W) {
            cin >> tiles[i][j];
        }
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
