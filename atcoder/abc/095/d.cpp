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

ll N, C, x[100000], v[100000];
ll dl[100000], dr[100000];
ll sl[100000], sr[100000];
ll msl[100000], msr[100000];

void solve()
{
    REP(i, N){
        dr[i] = x[i];
        dl[i] = (i > 0 ? dl[i-1] : 0) + (C-x[N-1-i]) - (i > 0 ? (C - x[N-1-i+1]) : 0);
        sr[i] = (i > 0 ? sr[i-1] : 0)
                    + v[i]
                    - (x[i] - (i > 0 ? x[i-1] : 0));
        sl[i] = (i > 0 ? sl[i-1] : 0)
                    + v[N-1-i]
                    - ((C-x[N-1-i]) - (i > 0 ? (C-x[N-1-i+1]) : 0));
    }
    ll ans = 0;
    REP(i, N){
        msr[i] = max((i > 0 ? msr[i-1] : 0), sr[i]);
        msl[i] = max((i > 0 ? msl[i-1] : 0), sl[i]);
        ans = max(ans, max(sr[i], sl[i]));
    }
    REP(i, N-1){
        ans = max(ans, sr[i] - dr[i] + msl[N-1-i-1]);
        ans = max(ans, sl[i] - dl[i] + msr[N-1-i-1]);
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> C;
    REP(i, N) cin >> x[i] >> v[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
