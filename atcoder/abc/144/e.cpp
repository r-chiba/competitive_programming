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

ll N, K;
ll a[200010], f[200010];

bool eatable(ll t)
{
    ll train = 0;
    REP (i, N) {
        if (a[i] * f[i] > t) {
            train += a[i] - t/f[i];
            if (train > K) return false;
        }
    }
    return true;
}

void solve()
{
    sort(a, a+N, greater<ll>());
    sort(f, f+N);
    ll l = -1, u = a[0] * f[N-1];
    while (u - l > 1) {
        ll mid = (l + u) / 2;
        if (eatable(mid)) {
            u = mid;
        } else {
            l = mid;
        }
    }
    cout << u << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    REP (i, N) cin >> a[i];
    REP (i, N) cin >> f[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
