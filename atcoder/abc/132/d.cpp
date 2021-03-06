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

ll pow_mod(ll x, ll n, ll mod)
{
    ll ret = 1ll;
    ll v = x;
    for (; n > 0; n >>= 1) {
        if (n & 1) (ret *= v) %= mod;
        (v *= v) %= mod;
    }
    return ret;
}

constexpr int COMB_MAX = 5000;
ll fac[COMB_MAX];   // fac[i]  = i!        (mod MOD)
ll finv[COMB_MAX];  // finv[i] = (i!)^{-1} (mod MOD)
ll inv[COMB_MAX];   // inv[i]  = i^{-1}    (mod MOD)

void combInit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    FOR(i, 2, COMB_MAX){
        fac[i] = fac[i-1] * i % MOD;
        // i^{-1} (mod p) = -(p mod i)^{-1} * (p/i) (mod p)
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}

ll comb(int n, int k)
{
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}

int N, K;

void solve()
{
    combInit();
    FOR (i, 1, K+1) {
        cout << (comb(K-1, K-i) * comb(N-K+1, i)) % MOD << endl;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
