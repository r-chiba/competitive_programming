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

#define DBG(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl;

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "[";
    for (auto e: v) os << e << ",";
    os << "]";
    return os;
}

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

// print floating-point number
// cout << fixed << setprecision(12) <<

// }}}

ll gcd(ll a, ll b)
{
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

inline ll lcm(ll a, ll b)
{
    // a*b may be overflowed
    return a / gcd(a, b) * b;
}

ll lcm(vector<ll> v)
{
    size_t s = v.size();
    ll ret = 1ll;
    REP (i, s) {
        if (ret % v[i] != 0) ret = lcm(ret, v[i]);
    }
    return ret;
}

int N;
vector<ll> a, b;

void solve()
{
    ll lall = lcm(a);
    ll ans = 0;
    REP (i, N) b[i] = lall / a[i];
    //REP (i, N) cout << b[i] << " ";
    //cout << endl;
    //REP (i, N) cout << a[i]*b[i] << " ";
    //cout << endl;
    REP (i, N) {
        ans += b[i];
        ans %= MOD;
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    a.resize(N);
    b.resize(N);
    REP (i, N) cin >> a[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
