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
// }}}

int N;
int h[200000];
ll a[200000];
LP dp[200000];

void init()
{
}

void solve()
{
    REP(i, N+1){
        dp[i].fi = INF;
        dp[i].se = 0;
    }
    REP(i, N){
        auto l = lower_bound(dp, dp+N, LP(h[i], 0));
        ll v = a[i] + (l-dp > 0 ? (l-1)->se : 0);
        if(l->se < v){
            l->fi = h[i];
            l->se = v;
        }
        REP(i, N+1) cout << "(" << dp[i].fi << ", " << dp[i].se << ") ";
        cout << endl;
    }
    ll ans = 0;
    REPR(i, N){
        ans = max(ans, dp[i].se);
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP(i, N) cin >> h[i];
    REP(i, N) cin >> a[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
